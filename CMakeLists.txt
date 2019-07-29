

cmake_minimum_required(VERSION 3.13)
project(Implementation_Scanner_)


set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)

include_directories(include/nlohmann)
add_executable(Implementation_Scanner_ src/main.cpp src/main.h src/config.cpp src/config.h src/scan.cpp src/scan.h)
