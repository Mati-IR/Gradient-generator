/**
 * @file filehandler.hpp
 * @brief Defines the FileHandler class for managing file output operations.
 */

#pragma once

#include <string>
#include <fstream>
#include <types.hpp>

/**
 * @class FileHandler
 * @brief Responsible for managing file operations, including writing color gradient data to a file.
 */
class FileHandler {
public:
    explicit FileHandler(const std::string& filepath);
    ~FileHandler() = default;
    void writeResults(const ResultGradient& result, uint16_t height, uint16_t width);
private:
    std::ofstream file;
};
