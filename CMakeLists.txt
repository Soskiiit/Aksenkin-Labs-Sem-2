cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)


project("lab_6")

set(PROJECT_SOURCES
        main.cpp
        src/polynom.cpp
        src/term.cpp
)

set(PROJECT_HEADERS
        include/polynom.h
        include/term.h
)

add_executable(lab_6
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(lab_6 PRIVATE include)
