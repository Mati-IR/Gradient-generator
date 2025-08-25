/**
 * @file types.hpp
 * @brief Defines common types used across the project, including image dimensions,
 * pixel representation, interpolation types, and result gradient structures.
 */

#pragma once

#include <cstdint>
#include <vector>
#include "rgb565.hpp"

/**
 * @typedef ImageHeight
 * @brief Represents the height of an image in pixels.
 */
using ImageHeight = uint16_t;

/**
 * @typedef ImageWidth
 * @brief Represents the width of an image in pixels.
 */
using ImageWidth = uint16_t;

/**
 * @typedef Pixel
 * @brief Represents a color value for a single pixel.
 *
 * This type holds a 16-bit color value in RGB565 format.
 */
using Pixel = uint16_t;

/**
 * @enum InterpolationType
 * @brief Defines the available interpolation methods for image generation.
 */
enum class InterpolationType {
    BILINEAR
};

/**
 * @typedef ResultGradient
 * @brief 2D vector of RGB565 pixels representing the final color gradient.
 *
 * Each element in the vector represents a row of pixels.
 */
using ResultGradient = std::vector<std::vector<rgb565::RGB565>>;
