cmake_minimum_required(VERSION 3.30)
project(lab_2_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_2_3 main.cpp
        Circle.h
        Circle.cpp
        Rectangle.h
        Rectangle.cpp
        Figure.h)
