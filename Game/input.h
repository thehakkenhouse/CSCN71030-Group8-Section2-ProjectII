// RPS Pro: input.h
// Contains the definitions of the Input module's functions
// and data structures
//
// Module managed by Luna Parker

#ifndef RPS_PRO_GAME_INPUT_H
#define RPS_PRO_GAME_INPUT_H

#include <stdbool.h>

void getStringFromUser(char[], int);
bool isStringMinimumLength(const char[], int);
bool isStringSpecificChar(const char[], char);
bool getStringUpToLineSeparator(const char[], char[], int);
char getCharFromUser(bool*);
char getValidCharFromUser(const char[]);
bool isCharInArray(char, const char[], int);
char getAllowedCharFromUser(const char[], int, const char[]);

#endif
