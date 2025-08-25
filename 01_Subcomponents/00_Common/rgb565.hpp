/**
 * @file rgb565.hpp
 * @brief Provides definitions and utilities for working with RGB565 color format,
 * including color channel masks, shifts, and the RGB565 struct.
 */

#pragma once

#include <cstdint>

namespace rgb565 {
    /**
     * @enum Color
     * @brief Defines available color channels in the RGB565 color model.
     */
    enum class Color {
        RED,
        GREEN,
        BLUE
    };

    /**
     * @brief Array of all available colors in RGB565 format.
     */
    constexpr Color allColors[] = {Color::RED, Color::GREEN, Color::BLUE };

    /**
     * @brief Bit masks for extracting individual color channels in RGB565.
     */
    static constexpr uint16_t redMask = 0xF800 , greenMask = 0x7E0, blueMask = 0x1F;

    /**
     * @brief Bit shifts for aligning color channel values in RGB565.
     */
    static constexpr uint8_t redShift = 11, greenShift = 5, blueShift = 0;

    /**
     * @struct RGB565
     * @brief Represents an RGB565 pixel with separate red, green, and blue channels.
     *
     * This struct uses bit-fields to store red, green, and blue channels in RGB565 format.
     */
    struct RGB565 {
        uint8_t red : 5;
        uint8_t green : 6;
        uint8_t blue : 5;
        static constexpr uint8_t max5Bit = 0x1F, max6Bit = 0x3F;

        void setColor(const uint8_t value, const Color selectedColor);
    };
}
