//
// Created by Jonathan Moallem on 16/8/20.
//

#include "declarations.h"

typedef struct { int a; } Data_t;

// Identifiers declared in global scope, including functions are
// automatically treated as extern storage class objects in linking
int GLOBALVAR;
void GLOBALFUNC();

void runDeclarations() {

    // Declarations are fundamentally composed of 3 elements:
    /* storage class */  /* type and qualifiers */    /* declarators */
    extern               int const                    name[];
    static               float volatile               * anotherName;
                         struct                       Data;

    // STORAGE CLASS SPECIFIERS

    // While the auto keyword is often redundant, it sets the object
    // to have automatic storage duration
    auto int a;

    // Indicates to the compiler that the object should be stored as
    // readily available as possible, must not be referenced
    register int reg;

    // Provides internal linkage only, preventing its usage outside the
    // current translation unit, will have static storage duration
    // independent of placement within scopes
    static int s;

    // Provides external linkage, allowing for its usage outside the
    // current translation unit, will also ave static storage
    // duration independent of placement within scopes
    extern int e;


    // TYPE QUALIFIERS

    // The constant qualifier insures that the value cannot be changed
    // after its initial definition
    const int* c;

    // Indicates to the compiler that the value may be modified
    // externally to the program and should be reread on each access
    volatile int* v;

    // The restrict qualifier may only be used on pointers, and informs
    // the compiler that a given object will only ever be referenced by
    // the pointer it refers to, allowing for certain optimisations
    int* restrict r;

    // Type qualifiers may be used on pointers, and the objects they
    // point to by placing the qualifiers to either side of the *
    // e.g. a constant pointer to a volatile integer
    volatile int* const externalInt;


    // DEFINITIONS

    // Simple types only have a definition if they include defining
    // values or specify a storage length
    int defA = 5;
    int defC[5];

    // Typedefs can be used to simplify the naming conventions of types
    Data_t defB = { 0 };
}

void func(); // Declaration
void func() {} // Definition