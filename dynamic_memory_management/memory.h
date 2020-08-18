//
// Created by Jonathan Moallem on 18/8/20.
//

#ifndef C_IN_A_NUTSHELL_MEMORY_H
#define C_IN_A_NUTSHELL_MEMORY_H

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node_t;

void runMemory();

Node_t* newNode(int value);


#endif //C_IN_A_NUTSHELL_MEMORY_H
