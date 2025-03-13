cmake_minimum_required(VERSION 3.30)

project("myset" CXX)
project("myvector" CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(myset
        STATIC
        set.cpp
        set.h
)

add_library(myvector
        STATIC
        vector.cpp
        vector.h
)
