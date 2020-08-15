//
// Created by Jonathan Moallem on 14/8/20.
//

#include <stdio.h>
#include "pointers.h"

void runPointers() {

    // Pointers can be declared using the star operator
    int num = 5;
    int* numPtr = &num; // They are assigned with the & operator

    // Printf provides a pointer formatter
    printPtr("num", &num);
    printPtr("numPtr", numPtr);

    // If a pointer is immediately required, they can
    // be assigned in the following way
    int num1 = 5, * num1Ptr = &num1;

    // Getting the reference of a poiter refers to the pointer's location in memory
    printf("\nAddress for num1Ptr: %p\nAddress for num1Ptr value: %p", &num1Ptr, num1Ptr);

    // A void pointer can be used to refer to any type of pointer
    void* anyPointer = num1Ptr;

    // While automatic pointers have undefined behaviour,
    // static pointers are initialised to NULL
    int* undefined;
    static int* defined;

    // The NULL macro can be used to create a null value, which is a cast of 0 to pointer
    if (undefined == NULL) {
        printf("\nUndefined value NULL");
    }
    if (defined == NULL) {
        printf("\nDefined value NULL");
    }

    // A pointer to another pointer can be defined as follows
    int** ptrPtr = &numPtr;

    // Pointer arithmetic can be quickly used to iterate through values in an array
    int arry[] = {0, 1, 2};
    int len = sizeof(arry)/ sizeof(int), * lastIdx = arry;
    printf("\nIndex value is %i", *(lastIdx+len-1));

    // Pointers to arrays may be defined in the following way
    int (* arryPtr)[len] = &arry;
    printf("\nArray value: %i", (*arryPtr)[2]); // And accessed like this

    int* const var0; // While this one declares a constant pointer to integer
    const int* var; // This statement is declaring a pointer to constant integer
    const int* const var1; // This one declares a constant pointer to constant integer

    // The restrict qualifier is a promise to the compiler that only that pointer will be
    // used to refer to the object for the pointer's lifetime, allowing for optimisations
    struct Data {
        int field;
    };
    struct Data d = {7}, * restrict dPtr = &d;

    // Volatile pointers inform the compiler that it may be accessed
    // and modified by external programs
    int* volatile vol = 0;

    // Arrays of pointers may also be defined, and can often be more efficient than
    // using multidimensional arrays, especially for storing lengthy data types
    int* ptrArry[] = {*ptrPtr, &num1, vol};
    printf("\nPointer array value: %p", ptrArry[1]);

    float (*floatyFunc)(float) = floaty;
    printf("\nValue of function pointer cal: %f", floatyFunc(4));
}

// Void pointers are converted in function params
void printPtr(char* str, void* ptr) {
    printf("\nAddress of %s: %p", str, ptr);
}

float floaty(float f) {
    return f;
}