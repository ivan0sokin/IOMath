cmake_minimum_required(VERSION 3.0)

add_executable(TestVector2.out TestVector2.cpp)

include(CTest)
enable_testing()

add_test(TestVector2 TestVector2.out)