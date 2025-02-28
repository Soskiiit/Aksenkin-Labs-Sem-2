cmake_minimum_required(VERSION 3.30)

set(project "fraction")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        fractions.cpp)

set(${project}_HEADERS
        fractions.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
