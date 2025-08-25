/**
 * @file argparser.hpp
 * @brief Defines the ArgParser class, responsible for parsing and validating command-line arguments.
 */

#pragma once

#include <cstdint>
#include <string>
#include "types.hpp"

/**
 * @class ArgParser
 * @brief Parses command-line arguments for image generation parameters and validates them.
 */
class ArgParser {
public:
    ArgParser(int argc, char *argv[]);
    ~ArgParser() = default;

    [[nodiscard]] std::string getOutputPath();
    [[nodiscard]] ImageWidth getImageWidth() const;
    [[nodiscard]] ImageHeight getImageHeight() const;
    [[nodiscard]] Pixel getTopLeft() const;
    [[nodiscard]] Pixel getTopRight() const;
    [[nodiscard]] Pixel getBottomLeft() const;
    [[nodiscard]] Pixel getBottomRight() const;
private:
    ImageHeight imageWidth;    /* Image width (32-bit unsigned integer) */
    ImageWidth imageHeight;    /* Image height (32-bit unsigned integer) */
    Pixel tl;               /* Top-left pixel color value */
    Pixel tr;               /* Top-right pixel color value */
    Pixel bl;               /* Bottom-left pixel color value  */
    Pixel br;               /* Bottom-right pixel color value  */
    std::string outputPath;    /* Output file path */

    [[nodiscard]] static uint16_t parseUInt16(const std::string &arg);
    [[nodiscard]] static Pixel parsePixel(const std::string &arg);
    [[nodiscard]] static ImageWidth parseImageWidth(const std::string &arg);
    [[nodiscard]] static ImageHeight parseImageHeight(const std::string &arg);
    static constexpr uint8_t requiredArgCount = 8U;
};
