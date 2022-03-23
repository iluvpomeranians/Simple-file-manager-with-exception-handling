cmake_minimum_required(VERSION 3.20)
project(newass3)

set(CMAKE_CXX_STANDARD 14)

add_executable(newass3 main.cpp File_Manager.cpp File_Manager.h TA.cpp TA.h CurrentExceptions.h)
