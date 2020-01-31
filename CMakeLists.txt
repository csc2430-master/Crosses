cmake_minimum_required(VERSION 3.10)
project(Crosses)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Crosses
        canvas.cpp
        canvas.h
        main.cpp)
