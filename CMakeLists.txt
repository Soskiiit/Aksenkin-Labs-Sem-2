cmake_minimum_required(VERSION 3.30)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        main.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

add_subdirectory(planetsdb)
target_link_libraries(${project} planetsdb)
