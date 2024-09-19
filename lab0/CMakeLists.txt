cmake_minimum_required(VERSION 3.5.0)

project(lab0b VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab0b main.cpp Handler.cpp Handler.h InputReader.cpp InputReader.h OutputWriter.cpp OutputWriter.h)