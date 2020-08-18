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
    type_conversions/conversions.c
    expressions_and_operators/expressions.c
    statements/statements.c
    functions/functions.c
    arrays/arrays.c
    pointers/pointers.c
    structures_unions_bitfields/records.c
    declarations/declarations.c
    dynamic_memory_management/memory.c)