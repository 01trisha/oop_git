cmake_minimum_required(VERSION 3.5.0)
project("CSVparser")

set(CMAKE_CXX_STANDARD 20)

add_executable(CSVparser src/main.cpp
    src/CSVparser.h 
    src/Printer.h)

