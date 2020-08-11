//
// Created by Jonathan Moallem on 7/5/20.
//

#include "enums.h"
#include <stdio.h>

void viewEnums() {
    enum number one = ONE, three = ALSO_THREE;
    int arr[] = {one, TWO, three, FOUR, FIVE};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("The enum value is: %i\n", arr[i]);
    }
    printf("\n%s", getEnum(THREE));
}

char* getEnum(enum number num) {
    char* name;
    // Switch statements cascade if no break is used
    // Enums can be used easily as int const values
    switch (num) {
        case ONE:
            name = "One";
            break;
        case TWO:
            name = "Two";
            break;
        case THREE:
            name = "Three";
            break;
        case FOUR:
            name = "Four";
            break;
        case FIVE:
            name = "Five";
            break;
        default:
            name = "undefined"; // Default should always be present
    }
    return name;
}