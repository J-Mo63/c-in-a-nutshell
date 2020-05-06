cmake_minimum_required(VERSION 3.16)
project(c_in_a_nutshell)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        the_nutshell main.c
        language_basics/circle.c
)