cmake_minimum_required(VERSION 3.20)

project(opencl-mandlebrot LANGUAGES C CXX CUDA)
add_compile_definitions(CL_TARGET_OPENCL_VERSION=200)
find_package(OpenCL REQUIRED)

file(READ mandelbrot.cl FILE_CONTENT)
configure_file(mandelbrot_data.c.in mandelbrot_data.c @ONLY)

add_executable(mandelbrot-opencl main.cpp cl_helper.c mandelbrot_data.c $<TARGET_OBJECTS:shared>)
target_link_libraries(mandelbrot-opencl OpenCL::OpenCL)
