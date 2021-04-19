cmake_minimum_required(VERSION 3.16)
project(PA3)

set(CMAKE_CXX_STANDARD 14)

add_executable(PA3 main.cpp ChainingHash.h Hash.h ProbingHash.h)
