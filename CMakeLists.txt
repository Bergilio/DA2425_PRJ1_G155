cmake_minimum_required(VERSION 3.22.1)
project(DA2425_PRJ1_G155)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Release")

# Include directory for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add all source files
file(GLOB SOURCES "src/*.cpp")

# If main.cpp is in the root directory, add it explicitly
add_executable(main main.cpp ${SOURCES})