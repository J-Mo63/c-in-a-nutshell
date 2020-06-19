//
// Created by Jonathan Moallem on 18/6/20.
//
#include <stdio.h>

#include "literals.h"

void runLiterals() {
    // C supports decimal, octal and hexadecimal notations
    int dec = 255;
    int oct = 0377;
    int hex = 0xFF;
    if (dec == oct && oct == hex) {
        printf("All values are equal for %d, %d, and %d\n", dec, oct, hex);
    }

    // Suffixes may be used to indicate the type of literals
    int lengthyBoi = 32L;
    float floatyBoi = .1F;

    // Exponents may be represented as follows
    double bigFloat = 50000000000;
    double exponent = 5e10;
    if (bigFloat == exponent) {
        printf("The floats of %f and %f are equal!\n", bigFloat, exponent);
    }

    // Character constants are suffixed with "L" and can be referenced as ints
    int c = 'd';
    if (c > 'a' && c < 'f') {
        printf("Char is between a and f\n");
    }

    // The backslash is used for escape sequence literals
    printf("\"quoted text\" some more \b\b\b\b\b\bthing is wrong \a");

    // String literals are parsed as an array of characters, otherwise a pointer to the first character, ending in \0
    char aStr[] = "This is a string??" " This is the same string"; // Adjacent strings are concatenated by the compiler
    char* pStr = aStr;
}