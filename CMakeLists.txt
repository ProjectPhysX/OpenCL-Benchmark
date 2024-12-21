cmake_minimum_required(VERSION 3.10)

project(OpenCL-Benchmark)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCL REQUIRED)

if(OpenCL_FOUND)
    message(STATUS "Using OpenCL include directory: ${OpenCL_INCLUDE_DIRS}")
    message(STATUS "Using OpenCL library: ${OpenCL_LIBRARY}")
else()
    message(FATAL_ERROR "OpenCL not found")
endif()

add_executable(OpenCL-Benchmark
    src/main.cpp
    src/kernel.cpp
)

target_compile_options(OpenCL-Benchmark PRIVATE -O -Wno-comment)

target_include_directories(OpenCL-Benchmark PRIVATE src src/OpenCL/include ${OpenCL_INCLUDE_DIRS})

target_link_libraries(OpenCL-Benchmark OpenCL::OpenCL)
