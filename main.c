#include "language_basics/circle.h"
#include "types/limits.h"
#include "types/enums.h"
#include "types/using_void.h"

typedef void (*emptyMethod)();

void (*funcArr[])() = {generateCircle, getLimits, viewEnums, useVoid};

int main() {
    for (int i = 0; i < (sizeof(funcArr) / sizeof(emptyMethod)); i++) {
        funcArr[i]();
    }
    return 0;
}
