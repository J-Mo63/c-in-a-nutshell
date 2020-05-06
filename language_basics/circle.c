//
// Created by Jonathan Moallem on 6/5/20.
//

// Includes the declarations of io functions from the standard (std) header file
#include <stdio.h>

/* A prior-declaration/include of header file is required to run the below functions without
 * a predefined order */
#include "circle.h"

struct Node {
    char c;
    struct Node* nodePtr; // Structs register scope on creation so they can reference themselves
};

/* While functions can nest local variables declarations, they cannot house local
 * function definitions (however declarations are available however superfluous) */
void generateCircle() {
    // You can assign two variables to the same type in a single line
    double radius = 1.0, area;

    // Strings can be separated over two lines in separate quotes
    print("/*som//e" "value*/\n"); // Commenting flags do not work inside string literals
    printf("Areas of circles\n\n"); // As you can see, comments can also be added on the right
    printf("     Radius             Area\n"
           "----------------------------\n");

    // String formatting with printf can be quite expressive
    area = circularArea(radius);
    printf("%10.1f        %10.2f\n", radius, area);

    radius = 5.0;
    area = circularArea(radius);
    printf("%10.1f        %10.2f\n", radius, area);

    char arr<::> = {'d'}; // The "<::>" is the same as "[]" here
    printf("<:%cigraphs:> can be used when you cannot find the appropriate keyboard\n", arr<:0:>);

    printf("The name of the calling function is %s()\n", __func__);

    struct Node node;
    node.nodePtr = &node;
    node.c = 'b';
    printf("The node is at %p, and the char is: %c\n", node.nodePtr, node.c);

    /* It is also possible to create local scope identifies like the below Node struct that
     * "hide" the variable of a greater scope (in this case, file-scope) */
    struct Node { int i; };
    struct Node newNode;
    newNode.i = 1;

#if 0 // Preprocessor directives can also be used to control the compilation of code
    print("this will not be printed");
#endif
    int a = 1;
    int b = 3; // Due to the way that the preprocessor works, the below expression is read
    int c = a+++b; // as `int c = a++ + b`, incrementing a and then adding b before assignment
    printf("%i %i\n", c, a);
}

double circularArea(double r) {
    const double pi = 3.1415926536;
    return pi * r * r;
}

void print(char* str /* these kinds of comments can be used between tokens */) {
    printf("%s", str);
}