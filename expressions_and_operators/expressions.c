//
// Created by Jonathan Moallem on 10/8/20.
//
#include <stdio.h>
#include "expressions.h"

#ifndef rValue
#define rValue 1
#endif

struct Values {
    int one;
    int two;
    double three;
};

void runExpressions() {
    // All expressions must resolve to a type
    // In the case it yields no result, the type is void

    endlessVoid(); // Returns type of void

    // There are lValues and rValues
    int lValue /* this is the LEFT value */ = 1 + rValue; /* And this is the RIGHT value */
    printf("\n%i", lValue);

    // Anything with a location in memory may be an lValue
    int lArray[] = {0, 2, 4};
    lArray[0] = lValue;
    int* lPtr = &lArray[0];
    *lPtr = 5;
    // Mainly references do not resolve to locations
    *lPtr++; // Both the increment
    *lPtr--; // and deincrement operators require a modifiable lValue
    printf("\n%i", *lPtr);

    // Associativity on unary operators is higher than binary
    int b = *lPtr * *lPtr;
    printf("\n%i", b);

    // Expressions allow for arithmetic to be performed on pointers
    int* arrayPtr = lArray;
    printf("\n%i", *(arrayPtr + 2));

    // Prefix and postfix increment have the same side effects
    int inc = 0;
    printf("\nvar = 0");
    printf("\n++var: %i", ++inc); // But different return values
    printf("\nvar++: %i", inc++);

    // Pointers may be equal when they either point to the same address or null
    int* endPtr = &lArray[2];
    int* anotherPtr = lArray;
    if (endPtr == anotherPtr + 2) {
        printf("\nSame location!");
    }

    // Arrays may be indexed either way
    printf("\n%i", 2[lArray]);

    // The & and * operators are complementary and thus cancel each other out
    int* newPtr = &*endPtr;

    // The . and -> operators can be used to access members of a struct or union
    struct Values e = {0, 1, 2};
    e.one = 1;
    e.two = 2;
    printf("\n%i", e.one); // The . accesses a member directly
    struct Values* v = &e;
    printf("\n%i", v->two); // The -> accesses a member via indirection
    printf("\n%i", (*v).two); // And is roughly equivalent to this

    // The compound literal operator can be used to declare unnamed
    // structs, unions and arrays
    void* anon = (int []) {1, 2, 3};
    processArray(anon);

    // The ternary operator can be used to simplify branching logic
    printf("\n%i", (v ? 1 : 2));

    // The comma operator may be used to run expressions sequentially
    newPtr++, --newPtr, newPtr++, --newPtr;
    printf("\n%i", *newPtr);
}

void endlessVoid() {}

void processArray(int hello[]) {
    printf("\n%i", hello[0]);
}