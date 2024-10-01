cmake_minimum_required(VERSION 3.5.0)
project(lab0b VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
add_executable(lab0b CSV.cpp TextFile.cpp WordCounter.cpp main.cpp)

