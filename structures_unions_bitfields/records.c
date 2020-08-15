//
// Created by Jonathan Moallem on 15/8/20.
//

#include <stdio.h>
#include <stddef.h>
#include "records.h"

// Unions define types that may be interpreted as multiple types, they
// share the same bit space, and are as long as their longest member
union ID {
    _Bool isSet: 1;
    char name[2];
    int serial;
};

void runRecords() {
    // Structs can be declared and defined in the following ways using
    // either the struct tag or typedef in the declaration
    struct Node node1 = {7, NULL}, * node1Ptr = &node1;
    Node_t node2 = {12, node1Ptr}, * node2Ptr = &node2;

    // Structs using automatic storage do not have their fields
    // initialised and must otherwise use an initialisation list
    // where missing fields are initialised to 0
    NodeList_t nodeList = {
            node2Ptr,
            .version = 1 // The member designator can be used to specify a particular field
    };
    nodeList.listName = "NODES";
    printNodes(nodeList, &nodeList);

    // The following macro can provide the exact byte-offset of a struct field
    printf("\nStruct field offset: %lu", offsetof(NodeList_t, version));

    // Unions are used in almost exactly the same way as structs
    union ID id = { .serial = 30049 };
    printf("\nID value: %s", id.name);

    union ID blankId = {};

    if (!blankId.isSet) {
        printf("\nThe id is unset");
    }
}

// While structs can be copied by value, it is more common to
// pass structs by reference, both methods are shown below
void printNodes(NodeList_t nodeList, const NodeList_t* nodeListPtr) {
    // Struct member fields can be accessed with the . operator, or
    // the -> operator when accessing them through a pointer
    printf("\nFirst node: %i", (*nodeList.root).value);
    printf("\nLast node: %i", nodeListPtr->root->next->value);
}