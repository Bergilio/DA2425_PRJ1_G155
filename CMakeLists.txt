cmake_minimum_required(VERSION 3.22)
project(DA2425_PRJ1_G155)

set(CMAKE_CXX_STANDARD 17)

# Include all .cpp files
add_executable(main
        main.cpp
        Graph.cpp
        dataParser.cpp
        inputHandler.cpp
        menu.cpp
        algorithms.cpp
        route.cpp
)
