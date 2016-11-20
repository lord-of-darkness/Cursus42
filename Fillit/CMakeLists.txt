cmake_minimum_required(VERSION 3.6)
project(Fillit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c includes/includes.h)
add_executable(Fillit ${SOURCE_FILES})