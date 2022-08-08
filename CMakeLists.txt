cmake_minimum_required(VERSION 3.19)
project(SimpleTrieTemplate)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(SimpleTrieTemplate
        include/DefaultParameters.h
        src/Iterator.cpp
        src/Node.cpp
        src/SimpleTrieTemplate.cpp
        test/test.cpp)
