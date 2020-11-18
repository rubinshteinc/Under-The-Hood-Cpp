cmake_minimum_required(VERSION 3.15)
project(Under_The_HoodIn_heritance C)

set(CMAKE_C_STANDARD 90)

include_directories(.)

add_executable(Under_The_HoodIn_heritance
        encapsulation/c_encapsulation_def.c
        encapsulation/c_encapsulation_defs.h
        encapsulation/c_encapsulation.c
        inheritance/c_inheritance.c
        inheritance/c_inheritance_defs.c
        inheritance/c_inheritance_defs.h
        polymorphism/c_polymorphism.c
        polymorphism/c_polymorphism_defs.h
        polymorphism/c_polymorphism_defs.c)
