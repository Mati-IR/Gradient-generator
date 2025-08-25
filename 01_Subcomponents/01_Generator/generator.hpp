/**
 * @file generator.hpp
 * @brief Defines the Generator class for managing the process of color gradient generation.
 */

#pragma once

#include <memory>
#include "argparser.hpp"
#include "filehandler.hpp"
#include "interpolation.hpp"

/**
 * @class Generator
 * @brief Main class to orchestrate the process of generating and saving a color gradient.
 *
 * Handles argument parsing, file handling, and color interpolation.
 */
class Generator {
public:
    Generator(int argc, char *argv[], InterpolationType interpolationType);
    ~Generator() = default;
    void run();
private:
    /* data */
    std::shared_ptr<ArgParser> args;
    FileHandler fileHandler;
    std::shared_ptr<Interpolation> interpolator;
};

