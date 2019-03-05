cmake_minimum_required(VERSION 3.13)
project(Implementation_Scanner_)


set(CMAKE_CXX_STANDARD 14)
find_library(libconfig libconfig)
add_executable(Implementation_Scanner_ src/main.cpp)

target_link_libraries(Implementation_Scanner_ config)