//
// Created by Jonathan Moallem on 7/5/20.
//

#ifndef C_IN_A_NUTSHELL_ENUMS_H
#define C_IN_A_NUTSHELL_ENUMS_H

enum number {ONE, TWO, THREE, ALSO_THREE = THREE /* enums may also have the same value */,
             FOUR = 7 /* specific int values may be assigned */, FIVE}; // Enums are stored as ints

void viewEnums();

char* getEnum(enum number num);

#endif //C_IN_A_NUTSHELL_ENUMS_H
