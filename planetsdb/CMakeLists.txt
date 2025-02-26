cmake_minimum_required(VERSION 3.30)

set(project "planetsdb")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        src/planets.cpp)

set(${project}_HEADERS
        include/planets.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})

target_include_directories(${project} PRIVATE include)
