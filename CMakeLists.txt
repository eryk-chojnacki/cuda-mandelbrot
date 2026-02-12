cmake_minimum_required(VERSION 3.20)

project(mandelbrot)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(shared)
add_subdirectory(cuda)
