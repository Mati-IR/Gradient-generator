#include <iostream>
#include "display.hpp"


void display::help() {
    std::cout <<"The program should be invoked by the following command line:\n" <<
                "program.exe <image_width> <image_height> <tl> <tr> <bl> <br> <output_path>\n" <<
                "where:\n" <<
                "<tl> is the top left pixel color value\n" <<
                "<tr> is the top right pixel color value\n" <<
                "<bl> is the bottom left pixel color value\n" <<
                "<br> is the bottom right pixel color value\n" <<
                "Values can be provided both as hex or decimal;\n" <<
                "Example of program calls:\n" <<
                "program.exe 16 16 0x0 0xf 0x0 0xf ./file.txt\n" <<
                "program.exe 32 32 3000 6000 9000 12000 ./file.txt\n";
}

void display::error(const std::string& message) {
        std::cerr << message << std::endl;
}