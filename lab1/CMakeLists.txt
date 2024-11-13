cmake_minimum_required(VERSION 3.5.0)
project(circularbuffer VERSION 0.1.0 LANGUAGES C CXX)

add_executable(circularbuffer scr/main.cpp scr/circularbuffer.h scr/circularbuffer.cpp) 

add_executable(Circularbuffer_test test/Circularbuffer_test.cpp scr/circularbuffer.h scr/circularbuffer.cpp)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(Circularbuffer_test GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(Circularbuffer_test)
enable_testing()