cmake_minimum_required(VERSION 3.30)

project("lab4")

set(PROJECT_SOURCES
        main.cpp
)

set(PROJECT_HEADERS
        include/stk.h
)
add_executable(lab4
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories("lab4" PRIVATE include)