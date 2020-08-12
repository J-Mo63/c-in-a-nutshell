//
// Created by Jonathan Moallem on 12/8/20.
//
#include <stdio.h>
#include <stdarg.h>
#include "functions.h"


// Functions are all subroutines of main(), which is a
// specially reserved function for program entry
void runFunctions() {
    yourTypicalFunction();
}

// Functions bust be declared or defined beforehand in order to be called
extern void theSameTypicalFunction(void);

// Typical functions include two components:
void yourTypicalFunction(/* parameter definitions */) { // The function head
    // And a function block
    theSameTypicalFunction(); // Functions can be executed with the () operator
}

// The register specifier requests that the compiler make the
// variable as quickly accessible in memory as possible
int quickAccess(register int a) {
    return a;
}

// Arrays can be passed as params but are essentially passed as
// pointers and they can only be returned as pointers
int* passingArrays(int a[], int matrixSize, int matrix[matrixSize][matrixSize]){
    // Arguments can be shared and multidimensional arrays are accepted
    int xPos = matrix[0][0];
    return a + xPos; // All non-void functions must have a return statement
}

// Functions can take a variable number of arguments using an ellipse
void variableArgs(int argNum, ...) {
    va_list list; // Define a new variable args list
    va_start(list, argNum); // Set it as current
    int arg1 = va_arg(list, int); // Gets the first arg as an int
    double arg2 = va_arg(list, double); // Gets the next arg as a double
    int arg3 = va_arg(list, int); // Gets the next arg as an int
    printf("\nVariable arg: %i, %f, %i", arg1, arg2, arg3);
    va_end(list); // End the list before the function ends
}

// Static declared functions can only be called within the source files
// they're defined in, keeping them private in a sense
static void staticFunc(x, y, a)
double x, y; // K&R-style notation can be used in function
int a; // definitions to reduce space used in the declaration
{
    printf("\nCalling static");
}

// Immutable values can be passed by reference using the const and pointer
// operators
void usePointers(const int* i, int* j) {
    (*j)++;
}

// Inlined functions suggest to the compiler to place the function
// body inline instead of calling the function in memory
static inline int addOne(int i) {
    // Some compilers require inlined functions to be declared as static
    // in order to be seen by the linker
    return ++i;
}

// Functions can call themselves recursively but must have an end
int recurse(int i, int j) {
    printf("\nRecursing...");
    if (i < j) return recurse(++i, j);
    return i;
}

// An empty list of parameters is equal to passing only void
// All functions are "extern" by default
extern void theSameTypicalFunction(void) {
    staticFunc(0, 0, 0);
    int a = quickAccess(0);
    variableArgs(2, 7, 2.5, 9);

    int i = 1;
    int j = 1;
    usePointers(&i, &j); // i is immutable, j is mutable
    printf("\nPointer values: %i, %i", i, j);

    i = addOne(i); // This will likely be inlined by the compiler
    recurse(i, ++j);
}