cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(program VERSION 1.0)

add_executable(program
        01_Subcomponents/00_Common/rgb565.cpp
        01_Subcomponents/01_Generator/generator.cpp
        01_Subcomponents/02_ArgParser/argparser.cpp
        01_Subcomponents/03_Interpolation/interpolation.cpp
        01_Subcomponents/04_Display/display.cpp
        01_Subcomponents/05_FileHandler/filehandler.cpp
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "program")

target_include_directories(program PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/01_Subcomponents/00_Common
        ${CMAKE_CURRENT_SOURCE_DIR}/01_Subcomponents/01_Generator
        ${CMAKE_CURRENT_SOURCE_DIR}/01_Subcomponents/02_ArgParser
        ${CMAKE_CURRENT_SOURCE_DIR}/01_Subcomponents/03_Interpolation
        ${CMAKE_CURRENT_SOURCE_DIR}/01_Subcomponents/04_Display
        ${CMAKE_CURRENT_SOURCE_DIR}/01_Subcomponents/05_FileHandler
)

target_include_directories(program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(program PRIVATE -std=c++20)