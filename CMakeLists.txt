cmake_minimum_required(VERSION 3.25)
project(lab8)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(PROJECT_HEADERS
    include/lab8_tasks.h
)  

set(PROJECT_SOURCES
    src/main.cpp
    src/task1_strings.cpp
    src/task2_strings.cpp
    src/task3_files.cpp
    src/task4_vector.cpp
    src/task5_point_vector.cpp
    src/task6_list.cpp
    src/task7_planet_list.cpp
    src/task8_char_int_map.cpp
    src/task9_map.cpp
)

add_executable(lab8_main
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_link_libraries(lab8_main)
