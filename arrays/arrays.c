//
// Created by Jonathan Moallem on 13/8/20.
//

#include <stdio.h>
#include "arrays.h"

typedef float Transform[3][3];
typedef float Vector3[3];

// Arrays can be defined outside of functions, and can be static
int globalArray[5];
static int privateArray[5];

// While structs may contain arrays, they may not contain those of
// variable length and must have a static length
struct SoA {
    char charArray[2];
};

void runArrays() {
    // Arrays are defined as follows, where a type, name and
    // length is described for the given array
    int intArray[5];

    // Array's sizes are always equal to their type's size multiplied by length
    printf("\nArray size: %lu", sizeof(intArray));
    printf("\nint*length size: %lu", sizeof(int) * 5);

    // Conversely the length can be found with a similar calculation
    printf("\nThe array has a length of %lu", sizeof(intArray) / sizeof(int));

    for (int i = 0; i < 3; i++) {
        staticArray();
    }

    // The length of the array may be omitted if there in an initialisation list present
    int initialisedArray[] = {0, 7, intArray[0]}; // They may contain variables

    // Element designators can be used to reference specific elements in the initialisation list
    // They will automatically size to fit the largest specified index element
    int brokenUpArray[] = {0, [10] = 4, 2}; // In this case, 2 would be the 12th element after 1
    // Elements in between (indexes 1-10) will all be initialised to 0

    struct Node {
        int i;
        char c;
    };

    // An array of structs or arrays can use nested initialisation lists
    struct Node structArray[] = {{0, 'a'}, {1,'b'}};
    int aArray[][2] = {{0, 1}, {1, 0}};

    // Multidimensional arrays can be accessed as follows
    aArray[0][0] = 10;

    // Because strings are represented as arrays of chars, the following two variables
    // are equal, as the first specifies a terminating character at the end
    char simpleString[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char funString[] = "Hello";
    printf("\nString length: %lu", sizeof(funString));

    int* returnedArray = passingArrays(initialisedArray, aArray, brokenUpArray);
    printf("\nReturned array: %i", returnedArray[1]);

    // It is often advisable to use typedefs for categorising different kinds of array lengths and setups
    Vector3 vec3 = {0, 1, 2};
    Transform trans = {{[1] = 5.f}, {}};
    printf("\nVector3 contents: %f, %f, %f", vec3[0], vec3[1], vec3[2]);
    printf("\nTransform y position: %f", trans[0][1]);
}

int staticArray() {
    // While non-static arrays may be defined with a non-constant expression
    // this may not be done with statically allocated arrays
    int a = 5;
    int nonStaticArray[a * 5]; // Non-static arrays will have their elements uninitialised, resulting in garbage
    static int staticArray[1]; // Statically allocated arrays will have their elements initialised to 0

    // Array elements can be indexed with the subscript operator []
    printf("\nNon-static array: %i", ++nonStaticArray[0]);
    printf("\nStatic array: %i", ++staticArray[0]);

    // Alternatively arrays can be accessed with pointer arithmetic
    int* secondIndex = staticArray+2;
    return *secondIndex;
}

// Passed arrays are implicitly cast to pointers of their element
// type and may only be returned as a pointer
static int* passingArrays(int array1[], int multiArray[][2], int* ptrArray) {
    // Multidimensional arrays must specify all dimensions they contain
    printf("\nPassed array: %i", array1[1]);
    printf("\nPassed multi-array: %i", multiArray[0][0]);
    printf("\nPassed pointer-array: %i", ptrArray[10]);
    return array1;
}