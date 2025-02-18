cmake_minimum_required(VERSION 3.30)

set(project "matrixhelper")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        matrixhelper.cpp)

set(${project}_HEADERS
        matrixhelper.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
