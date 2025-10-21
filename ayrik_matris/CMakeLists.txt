cmake_minimum_required(VERSION 3.10)
project(AyrikMatris)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(ayrik_matris
    src/main.cpp
    src/create_matrix.cpp
    src/print_matrix.cpp
    src/sadeles.cpp
)
