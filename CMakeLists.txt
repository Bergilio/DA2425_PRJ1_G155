cmake_minimum_required(VERSION 3.22.1)
project( DA2425_PRJ1_G155)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}" )
set( CMAKE_BUILD_TYPE "Release" )
include_directories(Main)

set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP} )

add_executable(main main.cpp
        data_structures/GraphMap.cpp)
