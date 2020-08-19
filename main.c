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
#include "structures_unions_bitfields/records.h"
#include "declarations/declarations.h"
#include "dynamic_memory_management/memory.h"
#include "input_and_output/io.h"
#include "preprocessing_directives/preprocessing.h"

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
        runRecords,
        runDeclarations,
        runMemory,
        runIo,
        runPreprocessing,
};

int main() {
    for (int i = 0; i < (sizeof(funcArr) / sizeof(emptyMethod)); i++) {
        funcArr[i]();
    }
    return 0;
}
