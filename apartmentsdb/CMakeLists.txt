cmake_minimum_required(VERSION 3.30)

set(project "apartmentsdb")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        src/apartments.cpp)

set(${project}_HEADERS
        include/apartments.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})

target_include_directories(${project} PRIVATE include)
