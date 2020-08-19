//
// Created by Jonathan Moallem on 19/8/20.
//

#include <stdio.h>
#include "io.h"

void runIo() {
    char* line = "This is a file with a line of text.";

    // To access files a buffer must be opened by gaining access to a
    // FILE pointer, which can then be operated on in the mode specified
    FILE* wf = fopen("file.txt", "w");

    // FILE pointers can be error-checked
    if (ferror(wf)) {
        fprintf(stderr, "\nError Writing");
    }

    // The following is a common idiom for writing characters to a stream
    while (*line) putc(*line++, wf);

    // The file should be closed using its FILE pointer after use
    fclose(wf);

    printf("\nBy char: ");
    FILE* rf = fopen("file.txt", "r");
    int c;
    // The getc function can be used to get the next char in the buffer
    while ((c = getc(rf)) != EOF) { // EOF indicates end of file stream
        // The printf function itself is used to provide formatted
        // output to the stdout buffer
        printf("%c", c);
    }
    fclose(rf);
    // Files may also be accessed at random rather than sequentially
}
