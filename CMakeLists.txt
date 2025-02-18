cmake_minimum_required(VERSION 3.30)

set(project "lab1_demo")
project(${project})
set(project_libs_dir ${CMAKE_SOURCE_DIR}/libs)

set(CMAKE_CXX_STANDARD 20)

set(project_sources
        main.cpp
)

set(project_headers
        include/mymath.h
        include/matrixhelper.h
)

set(project_libs
        ${project_libs_dir}/libmatrixhelper.a
        ${project_libs_dir}/libmymath.a
)

add_executable(${project}
        ${project_sources}
        ${project_headers}
)

target_link_libraries(${project} ${project_libs})
