cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestVector2.out TestVector2.cpp)

include(CTest)
enable_testing()

add_test(TestVector2 TestVector2.out)