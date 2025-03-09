cmake_minimum_required(VERSION 3.30)

project(lab_5)

set(PROJECT_SOURCES
        main.cpp
)

set(PROJECT_HEADERS
        include/vector.h
        include/set.h
)

add_executable(lab_5
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(lab_5 PRIVATE include)
