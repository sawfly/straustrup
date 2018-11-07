cmake_minimum_required(VERSION 3.12)
project(straustrup)

set(CMAKE_CXX_STANDARD 14)

add_executable(straustrup_4_1 src/4.1.cpp)
add_executable(straustrup_4_2 src/4.2.cpp src/4_2_extern.cpp)
add_executable(straustrup_4_3 src/4.3.cpp)
