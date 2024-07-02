cmake_minimum_required(VERSION 3.28)
project(c_module_02)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(fixed0
        ex00/main.cpp
        ex00/Fixed.cpp
        ex00/Fixed.hpp)
