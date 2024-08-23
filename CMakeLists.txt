cmake_minimum_required(VERSION 3.11.0)

project(student_database)

add_executable(${PROJECT_NAME} source/main.cpp source/peselValidator.cpp source/dataBase.cpp source/student.cpp)

