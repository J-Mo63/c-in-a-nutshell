#include "language_basics/circle.h"
#include "types/limits.h"
#include "types/enums.h"
#include "types/void.h"
#include "literals/literals.h"
#include "type_conversions/conversions.h"
#include "expressions_and_operators/expressions.h"
#include "statements/statements.h"
#include "functions/functions.h"
#include "arrays/arrays.h"
#include "pointers/pointers.h"

typedef void (*emptyMethod)();

void (*funcArr[])() = {
        generateCircle,
        getLimits,
        viewEnums,
        useVoid,
        runLiterals,
        runConversions,
        runExpressions,
        runStatements,
        runFunctions,
        runArrays,
        runPointers,
};

int main() {
    for (int i = 0; i < (sizeof(funcArr) / sizeof(emptyMethod)); i++) {
        funcArr[i]();
    }
    return 0;
}
