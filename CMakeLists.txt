cmake_minimum_required(VERSION 3.30)

project(lab_5)

set(PROJECT_SOURCES
        main.cpp
)

set(PROJECT_HEADERS
        mylibs/vector.h
        mylibs/set.h
)

add_executable(lab_5
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

add_subdirectory(mylibs)
target_link_libraries(lab_5 myset)
target_link_libraries(lab_5 myvector)

target_include_directories(lab_5 PRIVATE mylibs)
