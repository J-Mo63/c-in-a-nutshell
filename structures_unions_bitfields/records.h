//
// Created by Jonathan Moallem on 15/8/20.
//

#ifndef C_IN_A_NUTSHELL_RECORDS_H
#define C_IN_A_NUTSHELL_RECORDS_H

// A struct is defined using the struct keyword followed by a tag name
struct Value {
    // They contain any number of fields of data types
    int value;

    // They cannot store themselves, but pointers to their type
    struct Value* next;
};

// Structs are often given a typedef to remove the need to prefix their
// tag with struct, instead suffixing the tag name with _t
typedef struct Value Value_t;

// Structs can also be defined without a tag, directly in a typedef
typedef struct {
    Value_t* root;
    char* listName;
    int version;
} NodeList_t;

void runRecords();

void printNodes(NodeList_t nodeList, const NodeList_t* nodeListPtr);

#endif //C_IN_A_NUTSHELL_RECORDS_H
