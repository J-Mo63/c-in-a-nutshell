//
// Created by Jonathan Moallem on 9/8/20.
//

#include <stdio.h>
#include "conversions.h"

#ifndef print
#define print(text, ...) printf("\n"#text, ##__VA_ARGS__)
#endif

void runConversions() {
    // Different types can be used together in operations
    double dVar = 2.5;
    dVar *= 3;
    if (dVar < 10L) {
        // If necessary they can be cast to specific types
        printf("\nHere is a float: %f", dVar);
        printf("\nHere is an int: %i", (int) dVar);
        // And it is recommended to use the cast operator wherever possible
    }

    // Conversions will take an order of precedence, defaulting to
    // the most complex types in "integer promotion"
    int integer = 1;
    long long longLong = 2;
    uintptr_t ptr = 0;
    unsigned long long uLl = integer * longLong * ptr;
    printf("%llu", uLl);

    // Operations with complex types will always result in
    // conversion to the complex type
    short s = 2;
    float _Complex complexFloat = 1.0;
    float convertsTo = complexFloat * s;

    // Passed params will attempt to convert to the type of the receiving method
    short finalValue = convertMe(5);

    // Bools are converted on a non-zero basis
    _Bool b = 5;

    // Arrays can also be converted to pointers implicitly
    int iArray[] = {1, 2, 3};
    int len = sizeof(iArray) / sizeof(int); // Array used as array
    int* value = iArray; // Array used as pointer
    printf("\nPointer to: %i", *(value + len - 1));

    // void* acts as an ANY pointer, and can be converted into any pointer type
    int something = 5;
    int* ptrSomething = &something;
    void* nothing = ptrSomething;
    ptrSomething = nothing;
    something = *ptrSomething;

    // Checking for null pointers will implicitly convert to an int pointer
    long* lPtr = NULL;
    if (lPtr == (void*) 0) {
        print(Still nothing);
    }

    // Implicit conversion can be simplified
    int intVar = 5, *intPtr = &intVar;
}

short convertMe(long long longBoi) {
    // Return values are also converted to match the declaration
    return longBoi;
}