cmake_minimum_required(VERSION 3.15)
project(Hotel_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hotel_Project main.cpp Room.cpp Room.h Hotel.cpp Hotel.h Date.cpp Date.h)