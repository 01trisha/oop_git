cmake_minimum_required(VERSION 3.20)

project("SoundProcessor")

set(CMAKE_CXX_STANDARD 20)
add_executable(SoundProcessor
        src/View.h
        src/Config.h
        src/Processor.h
        src/Converter.h
        src/MuteConverter.h
        src/MixConverter.h
        src/ReverseConverter.h
        src/Factory.h
        src/main.cpp
        src/View.cpp
        src/Config.cpp
        src/Processor.cpp
        src/Context.h 
        src/Context.cpp 
        src/MuteConverter.cpp
        src/MixConverter.cpp
        src/ReverseConverter.cpp)


add_executable(Sound_processor_test tests/tests.cpp
        src/View.h
        src/Config.h
        src/Processor.h
        src/Converter.h
        src/MuteConverter.h
        src/MixConverter.h
        src/ReverseConverter.h
        src/Factory.h
        src/View.cpp
        src/Config.cpp
        src/Processor.cpp
        src/Context.h 
        src/Context.cpp 
        src/MuteConverter.cpp
        src/MixConverter.cpp
        src/ReverseConverter.cpp)


# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Связь с библиотекой GTest
target_link_libraries(Sound_processor_test GTest::gtest_main)

# Автоматическое обнаружение тестов
include(GoogleTest)
gtest_discover_tests(Sound_processor_test)
enable_testing()
