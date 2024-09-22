cmake_minimum_required(VERSION 3.11.0)
project(univesity_database)

set(CMAKE CMAKE_CXX_STANDARD 17)
set(CMAKE CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    source/dataBase.cpp
    source/peselValidator.cpp
    source/student.cpp
    source/person.cpp
    source/employee.cpp
    )   

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} source/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)


