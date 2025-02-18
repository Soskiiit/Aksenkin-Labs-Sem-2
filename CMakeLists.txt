cmake_minimum_required(VERSION 3.30)

set(project "lab1")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        main.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

add_subdirectory(mymath)
target_link_libraries(${project} mymath)

add_subdirectory(matrixhelper)
target_link_libraries(${project} matrixhelper)
