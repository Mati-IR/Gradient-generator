/**
 * @file filehandler.cpp
 * @brief Implements the FileHandler class for managing file output operations.
 */

#include <iomanip>
#include "filehandler.hpp"
#include "rgb565.hpp"

/**
 * @brief Constructs a FileHandler and opens the specified file.
 *
 * Opens the file at the provided path for writing. Throws an exception if the file cannot be opened.
 *
 * @param filepath Path to the file to open.
 * @throws std::ios_base::failure If the file cannot be opened.
 */
FileHandler::FileHandler(const std::string& filepath) {
    file.open(filepath);
    if (!file.is_open()) {
        throw std::ios_base::failure("Could not open file with following path: " + filepath);
    }
}

/**
 * @brief Writes a color gradient result to the file.
 *
 * Outputs the color gradient in a hex format, each color representing an RGB565 value.
 *
 * @param result A matrix of RGB565 color values representing the gradient.
 * @param height Height of the gradient matrix.
 * @param width Width of the gradient matrix.
 * @throws std::runtime_error If the file is not open.
 */
void FileHandler::writeResults(const ResultGradient& result, const ImageHeight height, const ImageWidth width) {
    if (!file.is_open()) {
        throw std::runtime_error("File is not open.");
    }

    /* Write the gradient data to the file */
    for (auto y = height - 1; y >= 0; y--) {
        for (uint16_t x = 0; x < width; x++) {
            const rgb565::RGB565& pixel = result[y][x];

            /* Format each pixel as a hex value and write it */
            file << "0x" << std::hex << std::setw(4) << std::setfill('0')
                 << (pixel.red << rgb565::redShift | pixel.green << rgb565::greenShift | pixel.blue << rgb565::blueShift);

            /* If it's not the last pixel in the row, add a space */
            if (x < width - 1) {
                file << " ";
            }
        }
        /* New line after each row */
        file << "\n";
    }

    /* Close the file after writing */
    file.close();
}
