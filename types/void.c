//
// Created by Jonathan Moallem on 7/5/20.
//

#include "void.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum {ARR_LEN = 100};

void useVoid() {
    testRecursive(0);
    (void) returnInt(); // Casting to void masks the return value of the function
    testVoid();
}

void testVoid() {
    // Create a space in memory the size of 100 integer values
    int i, *pNumbers = malloc(ARR_LEN * sizeof(int));

    if (pNumbers == NULL) {
        fprintf(stderr, "Insufficient memory.\n");
        exit(1);
    }

    srand((unsigned)time(NULL));

    for (i = 0; i < ARR_LEN; ++i) {
        // Assign them random integers
        pNumbers[i] = rand() % 10000; // Assign to the int* as AN ARRAY
    }

    printf("\n%d random numbers between 0 and 9999:\n", ARR_LEN);
    for (i = 0; i < ARR_LEN; ++i) {
        printf("%6d", pNumbers[i]); // Access the int* as AN ARRAY
        if (i % 10 == 9) putchar('\n');
    }
    free(pNumbers);
}

void testRecursive(int testVal) {
    void ((*fn)(int)) = testRecursive;
    testVal++;
    if (testVal <= 3){
        printf("\nRecursive test: %d", testVal);
        fn(testVal);
    }
}

int returnInt() {
    return 1;
}