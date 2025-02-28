cmake_minimum_required(VERSION 3.30)

project("lab3")

set(PROJECT_SOURCES
        main.cpp
)

add_executable("lab3"
        ${PROJECT_SOURCES}
)

add_subdirectory(fraction)

target_include_directories("lab3" PRIVATE fraction)
target_link_libraries("lab3" fraction)
