cmake_minimum_required(VERSION 3.19)
project(triemplate)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(triemplate
        include/DefaultParameters.h
        src/Iterator.cpp
        src/Node.cpp
        src/triemplate.cpp
        test/test.cpp)
