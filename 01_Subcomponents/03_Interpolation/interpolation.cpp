/**
 * @file interpolation.cpp
 * @brief Contains implementations for the InterpolationFactory, Interpolation, and BilinearInterpolation classes.
 */

#include "interpolation.hpp"
#include "rgb565.hpp"

/**
 * @brief Creates an instance of an Interpolation object based on the specified type.
 *
 * @param parser A shared pointer to an ArgParser object containing image parameters.
 * @param type The type of interpolation to create (e.g., BILINEAR).
 * @return A shared pointer to the created Interpolation object.
 * @throws std::invalid_argument if an invalid InterpolationType is provided.
 */
std::shared_ptr<Interpolation> InterpolationFactory::get(const std::shared_ptr<ArgParser>& parser, InterpolationType type)
{
    switch (type)
    {
    case InterpolationType::BILINEAR:
        return std::make_shared<BilinearInterpolation>(parser);
    default:
        throw std::invalid_argument("Invalid Interpolation Type");
    }
}

/**
 * @brief Constructs an Interpolation object.
 *
 * Initializes the Interpolation object with the provided argument parser.
 * Ensures that the image dimensions are positive.
 *
 * @param argParser A shared pointer to an ArgParser object.
 * @throws std::invalid_argument if width or height are non-positive.
 */
Interpolation::Interpolation(const std::shared_ptr<ArgParser>& argParser) {
    if (argParser->getImageWidth() < 0 || argParser->getImageHeight() < 0) {
        throw std::invalid_argument("Width and height must be positive");
    }
    args = argParser;
}

/**
 * @brief Constructs a BilinearInterpolation object.
 *
 * Initializes the BilinearInterpolation object with the provided argument parser.
 *
 * @param argParser A shared pointer to an ArgParser object.
 */
BilinearInterpolation::BilinearInterpolation(const std::shared_ptr<ArgParser>& argParser) :
                                            Interpolation(argParser) {}

/**
 * @brief Generates a bilinear-interpolated color gradient matrix.
 *
 * Computes a bilinear interpolation over the specified image dimensions and returns a 2D matrix of RGB565 colors.
 * The interpolation is performed independently for each color channel (red, green, blue).
 *
 * @return A ResultGradient containing the interpolated RGB565 color matrix.
 * @throws std::invalid_argument if an invalid color is specified in getColor.
 */
ResultGradient BilinearInterpolation::generate() {
    ResultGradient gradient(args->getImageHeight(), std::vector<rgb565::RGB565>(args->getImageWidth()));
    auto getRed =   [this](auto color) { return (color & rgb565::redMask)   >> rgb565::redShift; };
    auto getGreen = [this](auto color) { return (color & rgb565::greenMask) >> rgb565::greenShift; };
    auto getBlue =  [this](auto color) { return (color & rgb565::blueMask)  >> rgb565::blueShift; };

    auto getColor = [this, getRed, getBlue, getGreen](const auto color, const rgb565::Color selectedColor) {
        if (rgb565::Color::RED == selectedColor) return getRed(color);
        if (rgb565::Color::GREEN == selectedColor) return getGreen(color);
        if (rgb565::Color::BLUE == selectedColor) return getBlue(color);
        throw std::invalid_argument("Invalid color\n");
    };

    for (ImageHeight y = 0; y < args->getImageHeight(); y++) {
        const float positionBottomToTop = static_cast<float>(y) / static_cast<float>(args->getImageHeight()); /* Vertical position (0 to 1) */
        const float positionTopToBottom = 1.0F - positionBottomToTop;
        for (ImageWidth x = 0; x < args->getImageWidth(); x++) {
            const float positionLeftToRight = static_cast<float>(x) / static_cast<float>(args->getImageHeight()); /* Horizontal position (0 to 1) */
            const float positionRightToLeft = 1.0F - positionLeftToRight;
            /* Interpolating each color (R, G, B) independently */
            for (const auto selectedColor : rgb565::allColors) {
                /* Bilinear interpolation formula */
                const auto newColor = static_cast<uint8_t>(positionTopToBottom * positionRightToLeft * static_cast<float>(getColor(args->getBottomLeft(), selectedColor))
                                                         + positionTopToBottom * positionLeftToRight * static_cast<float>(getColor(args->getBottomRight(), selectedColor))
                                                         + positionBottomToTop * positionRightToLeft * static_cast<float>(getColor(args->getTopLeft(), selectedColor))
                                                         + positionBottomToTop * positionLeftToRight * static_cast<float>(getColor(args->getTopRight(), selectedColor)));

                gradient[y][x].setColor(newColor, selectedColor);
            }
        }
    }

    return gradient;
}