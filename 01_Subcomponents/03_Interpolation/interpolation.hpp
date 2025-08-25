/**
 * @file interpolation.hpp
 * @brief Defines the Interpolation base class, BilinearInterpolation derived class, and InterpolationFactory.
 */

#pragma once

#include <argparser.hpp>
#include <memory>
#include <types.hpp>
#include <vector>

/**
 * @class Interpolation
 * @brief Abstract base class for various interpolation methods.
 *
 * Provides an interface for generating interpolated color gradients.
 */
class Interpolation {
public:
    virtual ~Interpolation() = default;
    virtual ResultGradient generate() = 0;
protected:
    std::shared_ptr<ArgParser> args;
    explicit Interpolation(const std::shared_ptr<ArgParser>& argParser);
};

/**
 * @class BilinearInterpolation
 * @brief Derived class implementing bilinear interpolation for color gradient generation.
 *
 * Uses bilinear interpolation to create a color gradient based on four corner colors.
 */
class BilinearInterpolation : public Interpolation {
public:
    explicit BilinearInterpolation(const std::shared_ptr<ArgParser>& argParser);
    [[nodiscard]] ResultGradient generate() override;
};

/**
* @class InterpolationFactory
* @brief Factory class for creating instances of various Interpolation types.
*
* Uses the Factory Pattern to instantiate different interpolation methods at runtime.
*/
class InterpolationFactory {
public:
    static std::shared_ptr<Interpolation> get(const std::shared_ptr<ArgParser>& parser, InterpolationType type);
};
