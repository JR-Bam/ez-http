cmake_minimum_required(VERSION 3.5.0)
project(ez-http VERSION 0.1.0 LANGUAGES C CXX)

include_directories(dependencies)

add_executable(ez-http main.cpp)

