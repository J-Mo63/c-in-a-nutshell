//
// Created by Jonathan Moallem on 18/8/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void runMemory()
{
    // Malloc can be used to allocate uninitialised memory the size of its param
    Node_t* unknownData = malloc(sizeof(Node_t));
    // Calloc can be used to allocate initialised memory (to 0) the size of its
    // param multiplied by count
    Node_t* knownData = calloc(1, sizeof(Node_t));

    // Pointers to heap memory may be null, and should be checked before use as
    // a null pointer indicates that memory is at capacity
    if (unknownData) {
        unknownData->value = 0;
        unknownData->next = knownData;
    }

    // Realloc can be used to resize the allocated memory block by a give pointer
    knownData->value = 10;
    knownData = realloc(knownData, sizeof(int));
    printf("\nKnown data: %i", knownData->value);

    // Heap memory will remain allocated until explicitly freeing it
    // or the end of the program has been reached calling it on null
    // has no negative consequences
    free(unknownData);
    free(knownData);

    int a[] = {1, 2, 3, 4, 5};

    // The heap is most often used for dynamic data structures such as trees and
    // lists, below is a simple implementation of a linked list
    Node_t* root = newNode(0);
    Node_t* current = root;
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++) {
        current->next = newNode(a[i]);
        current = current->next;
    }
    current->next = NULL;

    current = root;
    while(current) {
        Node_t* prev = current;
        printf("\nNode: %i", current->value);
        current = current->next;
        free(prev);
    }
}

Node_t* newNode(int value) {
    Node_t* newNode = malloc(sizeof(Node_t));
    newNode->value = value;
    return newNode;
}
