//
// Created by Jonathan Moallem on 11/8/20.
//
#include <stdio.h>
#include "statements.h"

void runStatements() {
    // There a different classifications of expression statements
    int a = 2; // Assignment
    a = 2 + 2; // Assignment and calculation
    printf("\nA function call"); // Function calls

    // Their type and value are discarded before the next statement
    // The following are all valid, but are useless
    1 + 2;
    100;
    a > 3;

    // Blocks can be used to group statements so that they can
    // be executed in places where a single statement is expected
    {
        // Functions can be cast to void to ignore return values
        (void)printf("\nRan floating block");
        int local;
    }
    int local = 1; // Variables declared in a block are automatically given that scope

    ; // A null statement
    for (int i = 0; i < 5; i++); // This loop is given a null statement

    // While loops will execute a statement (or block) for each
    // time that the controlling expression evaluates to non-zero
    while (local) {
        local = 0;
    }

    // For loops contain looping logic in their definition as a set of three statements
    for (
            int i = 0; // Runs once before the first loop
            i < 3; // Runs before each loop to test the controlling expression
            i++ // Runs just before the controlling expression to adjust values
    ) {
        printf("\nRunning for loop...");
    }

    // Omitting expressions would form an endless loop as so
    for (;;) {
        break; // Exits the current control structure
    }

    // The comma operator may be used to add additional expressions
    // to the statements of the for loop
    for (int i = 0, j = 0; i < 2; i++, j++) {
        // The continue statement can be used to skip the rest of the
        // statements in a given loop iteration
        if (j > 0) continue;
        printf("\nPls don't skip me!");
    }

    // Do-while statements effectively operate in the opposite way to the while
    // statements, testing the value at the end of the loop
    do {
        // Loops can also be nested, with inner loops making use
        // of variables declared external to them
        int outerVar = local;
        // They take a single statement (or block statement)
        do outerVar *= 1; while (outerVar);
    } while (local);

    // If and else control structures take a controlling expression
    // and a single statement (or block) and execute them once
    if (local) printf("Local was true");
    // The else is optional
    else if (!local) {
        // Else and if statements can be chained together
        //  as they act as a single statement
        printf("\nLocal was not true");
    }
    else {
        // If a previous if statement is run, all those below it
        // will be skipped over as they belong to the previous chain
        printf("Local was not true after all!");
    }

    // Switch statements are used to jump to a constant expression
    // where all sequential code below will run accordingly
    switch (local) {
        case 0: // This will cascade into the next case
        case 1:
            printf("\nThe value is boolean");
            break; // Break statements must be used to exit the case
        default: {
                // Blocks may be used inside cases
                printf("The value has more than two values!");
            }
            break;
    }


    local = 0;
    // Labels can be used to mark points for goto statements to
    // move to, destroying all local variables that go out of scope
    // and may only jump within the same function
    some_historical_point:
    local++;
    printf("\nRunning historical event");
    if (local < 2) goto some_historical_point;
    // NEVER jump into a loop

    // Return statements end the current function and return a value
    return; // In this case, the function returns a void type value
    printf("\nI won't get the chance to run...");
}