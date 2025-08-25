/**
 * @file rgb565.cpp
 * @brief implements rgb565::RGB565::setColor
 */

#include <stdexcept>
#include "rgb565.hpp"
#include "display.hpp"

/**
 * @brief Sets a color channel to a specified value, validating it against channel limits.
 *
 * If the provided value exceeds the maximum allowed for the specified color channel,
 * an error message is displayed.
 *
 * @param value The new value for the color channel.
 * @param selectedColor The color channel to set (RED, GREEN, or BLUE).
 * @throws std::invalid_argument If an invalid color is specified.
 */
void rgb565::RGB565::setColor(const uint8_t value, const Color selectedColor) {
  switch (selectedColor) {
  case Color::RED:
    if (value <= max5Bit) {
      red = value;
    } else {
      display::error("Invalid value for red channel (must be 0-31). It is " +
                     std::to_string(value) + "\n");
    }
    break;

  case Color::GREEN:
    if (value <= max6Bit) {
      green = value;
    } else {
      display::error(
         "Invalid value for green channel (must be 0-63). It is " +
         std::to_string(value) + "\n");
    }
    break;

  case Color::BLUE:
    if (value <= max5Bit) {
      blue = value;
    } else {
      display::error("Invalid value for blue channel (must be 0-31). It is " +
                    std::to_string(value) + "\n");
    }
    break;

  default:
    throw std::invalid_argument("Unknown color selection.");
  }
}