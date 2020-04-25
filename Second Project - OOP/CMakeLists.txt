cmake_minimum_required(VERSION 3.15)
project(Sklad)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sklad main.cpp Product.cpp Product.h Vector.h Date.cpp Date.h Location.cpp Location.h)