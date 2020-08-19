//
// Created by Jonathan Moallem on 19/8/20.
//

// Includes allow for the insertion of header files
#include <stdio.h> // Angle brackets are used for standard libraries
#include "preprocessing.h" // Quotes are used for project files

// The define directive can be used to create macros that will replace all
// occurrences within the source code of the program
#define RUN_TEXT "\nRunning preprocessing... " // Macros may be used within others
// Paramseters may be used in macros for variables to be passed in
#define DISPLAY_RUN(text, ...) printf(RUN_TEXT text __VA_ARGS__);
// VA_ARGS allows for multiple arguments to be passed

void runPreprocessing() {
    DISPLAY_RUN("now", "!")
}

// Condition compilation directives may be used to modify the contents of source
// files ahead of compile time, and may use defined macros for concepts such as OS
#ifdef BIG_ERROR
// The error directive simply aborts preprocessing and outputs a given message
#error hello!
#endif
