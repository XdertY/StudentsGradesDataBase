cmake_minimum_required(VERSION 3.14)
project(Data_Base_Students_Grades)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Base_Students_Grades main.cpp Student.cpp Student.h StudentList.cpp StudentList.h Functions.cpp Functions.h)