cmake_minimum_required(VERSION 3.29)
project(lin_sys C)

set(CMAKE_C_STANDARD 11)

add_executable(lin_sys main.c
        matrix.c
        matrix.h)
