#include <iostream>
#include <memory>
#include "display.hpp"
#include "generator.hpp"
#include "types.hpp"


int main(int argc, char *argv[]) {
    try {
        Generator generator(argc, argv, InterpolationType::BILINEAR);
        generator.run();
    }
    catch(const std::exception& e) {
        display::error(e.what());
        display::help();
        return -1;
    }

    return 0;
}
