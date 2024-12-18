cmake_minimum_required(VERSION 3.29)
project(lin_sys)

set(CMAKE_CXX_STANDARD 20)

add_executable(lin_sys main.cpp
        Matrix.cpp
        Matrix.h)
