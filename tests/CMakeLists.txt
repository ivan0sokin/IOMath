cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_executable(TestVector2 TestVector2.cpp)
  add_executable(TestVector3 TestVector3.cpp)
  
  add_test(TestVector2 TestVector2)
  add_test(TestVector3 TestVector3)
endif()