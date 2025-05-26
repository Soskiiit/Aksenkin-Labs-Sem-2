add_library(lab7_classes STATIC
    src/person.cpp
    src/student.cpp
    src/teacher.cpp
    src/head_of_department.cpp
    src/container_functions.cpp
)

target_include_directories(lab7_classes 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(lab_7 main.cpp)

target_link_libraries(lab_7 
    PRIVATE 
        lab7_classes 
        myvector
)
