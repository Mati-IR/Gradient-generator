/**
 * @file generator.cpp
 * @brief Implements the Generator class to control color gradient generation and file output.
 */

#include "generator.hpp"

/**
 * @brief Generator constructor.
 *
 * Initializes the argument parser, file handler, and interpolation object based on the given parameters.
 *
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @param interpolationType Specifies the type of interpolation to use.
 */
Generator::Generator(int argc, char *argv[], InterpolationType interpolationType)
    : args(std::make_shared<ArgParser>(argc, argv)),
    fileHandler(args->getOutputPath()),
    interpolator(InterpolationFactory::get(args, interpolationType))
{}

/**
 * @brief Executes the generation process and saves the result to the file.
 *
 * Generates a color gradient using the chosen interpolation method and writes it to the output file.
 */
void Generator::run() {
    fileHandler.writeResults(interpolator->generate(), args->getImageHeight(), args->getImageWidth());
}
