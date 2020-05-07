//
// Created by Jonathan Moallem on 7/5/20.
//

#include "limits.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <float.h>
#include <complex.h>

// Values can be made into macros using the define preprocessor directive
#define TRUE  1
#define FALSE 0

void getLimits() {
    testBools();
    testChars();
    testIntLengths();
    testLimits();
    intWidths();
    floatPrecision();
    complexFloats();
}

void testBools() {
    int alwaysOne = TRUE + FALSE;
    // While one may define these types, it is common to use the stdbool.h implementation which provides
    // true and false operands, representing 1 and 0 respectively
    bool isValid = 1 == alwaysOne;
    if (isValid) {
        printf("The thing was valid!\n");
    }
}

void testChars() {
    // Character types are integers representing character codes
    char ch = 'A';
    printf("The character %c has the character code %d.\n", ch, ch);
    for (; ch <= 'D'; ++ch) // Control structures may omit braces
        printf("%c", ch);   // when there is only one statement
    if (ch == 'E') { // However braces are highly recommended in all scenarios
        printf("\n%c is the thing\n", ch); // as they assist with readability and reduce potential errors
    }
    printf("%lu\n", strlen("hello")); // To find the length of a char* (string) use the string.h standard header
}

void testIntLengths() {
    printf("Short(%lu) <= Int(%lu) <= Long(%lu) <= Long Long(%lu)\n",
            sizeof(short), sizeof(int), // The sizeof function will show the storage length of the
            sizeof(long), sizeof(long long)); // value in memory in bytes
}

void testLimits() {
    int minimumOfChar = CHAR_MIN;
    printf("Storage sizes and value ranges of the types char and in\n\n");
    printf("The type char is %s.\n\n", minimumOfChar < 0 ? "signed" : "unsigned"); // Ternary expressions are available
    printf(" Type   Size (in bytes)     Minimum         Maximum\n");
    printf("---------------------------------------------------\n");
    printf(" char %8lu %20d %15d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf(" int  %8lu %20d %15d\n", sizeof(int), INT_MIN, INT_MAX);
}

void intWidths() {
    // Integers can have their widths defined explicitly in the type
    int8_t int8bytes = 100;
    u_int8_t unsignedint8bytes = 200;
    int16_t int16bytes = 10000;
    int_least8_t smallestInt = 100; // Smallest possible width for the allocated value
    int_fast8_t fastestInt = 100; // This int will process the fastest in runtime
    intmax_t biggestInt = 1000000000000000000; // Biggest possible width
    intptr_t smallestIntForPointer = 0; // Smallest int for storing pointers

    int arr[] = {int8bytes, unsignedint8bytes, int16bytes, smallestInt, fastestInt, biggestInt, smallestIntForPointer};
    size_t n = sizeof(arr) / sizeof(int); // The length of an array is the byte size divided
    for (int i = 0; i < n; i++) {         // by the width of each element
        printf("Integer %i\n", arr[i]);
    }
}

void floatPrecision() {
    puts("\nCharacteristics of the type float\n");
    printf("Storage size: %lu bytes\n"
           "Smallest positive value: %E\n"
           "Greatest positive value: %E\n"
           "Precision: %d decimal digits\n",
           sizeof(float), FLT_MIN, FLT_MAX, FLT_DIG);

    puts("\nAn example of float precision\n");
    double d_var = 12345.6;
    float f_var = (float) d_var;
    printf("The floating point number     "
           "%18.10f\n", d_var);
    printf("Has been stored in a variable\n"
           "of type float as the value    "
           "%18.10f\n", f_var);
    printf("The rounding error is         "
           "%18.10f\n", d_var - f_var);
}

void complexFloats() {
    double complex z = 1.0 + 2.0 * I; // The complex.h header allows for complex values and the use of csin and ctan
    z *= I; // Rotating the value clockwise around the origin by 90 degrees
}