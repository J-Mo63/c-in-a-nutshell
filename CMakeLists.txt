cmake_minimum_required(VERSION 3.16)
project(c_in_a_nutshell)

set(CMAKE_C_STANDARD 99)

add_executable(
    the_nutshell main.c
    language_basics/circle.c
    types/limits.c
    types/void.c
    types/enums.c
    literals/literals.c
)