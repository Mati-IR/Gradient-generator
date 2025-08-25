/**
 * @file argparser.cpp
 * @brief Implements the ArgParser class, responsible for command-line argument parsing.
 */

#include "argparser.hpp"
#include "display.hpp"
#include <cstdint>

#include <complex>

/**
 * @brief Constructs an ArgParser object and processes the command-line
 * arguments.
 *
 * Validates argument count and extracts width, height, color values, and output
 * file path.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @throws std::invalid_argument If argc does not match requiredArgCount or if
 * argv is null.
 */
ArgParser::ArgParser(const int argc, char *argv[]) {
    if (static_cast<uint8_t>(argc) != requiredArgCount) {
        throw std::invalid_argument("Argument count is not equal to "  + std::to_string(requiredArgCount));
    }
    if (argv == nullptr) {
        display::error("Error: Argument vector is null.");
        throw std::invalid_argument("argv is null");
    }

    outputPath = std::string(argv[7]);
    if (this->outputPath.empty()) {
        throw std::invalid_argument("Output path cannot be empty");
    }

    imageWidth = parseUInt16(argv[1]);
    imageHeight = parseUInt16(argv[2]);
    tl = parsePixel(argv[3]);
    tr = parsePixel(argv[4]);
    bl = parsePixel(argv[5]);
    br = parsePixel(argv[6]);
}

/**
 * @brief Parses a string to a positive uint16_t.
 *
 * Ensures the value is non-negative and within the range of uint16_t.
 *
 * @param arg String to parse.
 * @return Parsed uint16_t value.
 * @throws std::invalid_argument If the value is negative or exceeds uint16_t.
 */
uint16_t ArgParser::parseUInt16(const std::string &arg) {
    uint16_t outValue = 0;
    size_t idx = 0;

    if (arg.find('.') != std::string::npos) {
        throw std::invalid_argument("Floating-point values are not allowed: " + arg);
    }

    int base = (arg.starts_with("0x") || arg.starts_with("0X")) ? 16 : 10;

    try {
        outValue = std::stoi(arg, &idx, base);

        /* Check if the whole string was parsed to avoid partial conversions */
        if (idx != arg.length()) {
            throw std::invalid_argument("Invalid numeric format: " + arg);
        }
    } catch ([[maybe_unused]] const std::invalid_argument& e) {
        throw std::invalid_argument("Incorrect argument value: " + arg + "\nIt should be a number");
    } catch ([[maybe_unused]] const std::out_of_range& e) {
        throw std::invalid_argument("Argument out of range for int16_t: " + arg);
    }

    return outValue;
}

/**
 * @brief Parses a string to a Pixel value.
 *
 * This function converts a string to a uint16_t pixel value, using parseUInt16()
 * to ensure the parsed value is within valid pixel range.
 *
 * @param arg String to parse as a Pixel.
 * @return Parsed Pixel value.
 */
Pixel ArgParser::parsePixel(const std::string &arg) {
    return parseUInt16(arg);
}

/**
 * @brief Parses a string to an ImageWidth value.
 *
 * Converts a string to an ImageWidth value, ensuring it is non-zero and within a valid range.
 *
 * @param arg String to parse as ImageWidth.
 * @return Parsed ImageWidth value.
 * @throws std::invalid_argument If the parsed width is zero.
 */
ImageWidth ArgParser::parseImageWidth(const std::string &arg) {
    auto outValue = static_cast<ImageWidth>(parseUInt16(arg));
    if (outValue == 0) {
        throw std::invalid_argument("Invalid image width: " + arg);
    }
    return outValue;
}

/**
 * @brief Parses a string to an ImageHeight value.
 *
 * Converts a string to an ImageHeight value, ensuring it is non-zero and within a valid range.
 *
 * @param arg String to parse as ImageHeight.
 * @return Parsed ImageHeight value.
 * @throws std::invalid_argument If the parsed height is zero.
 */
ImageHeight ArgParser::parseImageHeight(const std::string &arg) {
    auto outValue = static_cast<ImageHeight>(parseUInt16(arg));
    if (outValue == 0) {
        throw std::invalid_argument("Invalid image height: " + arg);
    }
    return outValue;
}

/** @brief Retrieves the output file path. */
std::string ArgParser::getOutputPath() {
    return this->outputPath;
}

/** @brief Retrieves the output file path. */
ImageWidth ArgParser::getImageWidth() const {
    return this->imageWidth;
}

/** @brief Retrieves the image height. */
ImageHeight ArgParser::getImageHeight() const {
    return this->imageHeight;
}

/** @brief Retrieves the top-left color value. */
uint16_t ArgParser::getTopLeft() const {
    return this->tl;
}

/** @brief Retrieves the top-right color value. */
uint16_t ArgParser::getTopRight() const {
    return this->tr;
}

/** @brief Retrieves the bottom-left color value. */
uint16_t ArgParser::getBottomLeft() const {
    return this->bl;
}

/** @brief Retrieves the bottom-right color value. */
uint16_t ArgParser::getBottomRight() const {
    return this->br;
}
