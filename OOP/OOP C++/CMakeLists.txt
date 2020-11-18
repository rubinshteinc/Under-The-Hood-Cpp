cmake_minimum_required(VERSION 3.15)
project(Under_The_Hood_c++_1)

set(CMAKE_CXX_STANDARD 98)

add_executable(Under_The_Hood_c++_1 cpp2c_encapsulation.cpp cpp2c_encapsulation_defs.cpp
        cpp2c_encapsulation_defs.h
        cpp2c_inheritance_defs.h cpp2c_inheritance_defs.cpp cpp2c_inheritance.cpp
        cpp2c_polymorphism_defs.h cpp2c_polymorphism_defs.cpp cpp2c_polymorphism.cpp)