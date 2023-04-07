// RPS Pro: input.h
// Contains the definitions of the Input module's functions
// and data structures
//
// Module managed by Luna Parker

#ifndef RPS_PRO_GAME_INPUT_H
#define RPS_PRO_GAME_INPUT_H

#include <stdbool.h>

#define LINE_SEPARATOR_CHARACTER '|'

// prototypes for input.h 
void getStringFromUser(char[], int);
bool isStringMinimumLength(const char[], int);
bool isStringSpecificChar(const char[], char);
bool getStringUpToChar(char, const char[], char[], int);
void getStringUpToSeparator(const char inputString[], char outputString[], int maxOutputStringLength);
void endStringAtNewLine(char[]);
char getCharFromUser(bool*);
char getValidCharFromUser(const char[]);
bool isCharInArray(char, const char[], int);
char getAllowedCharFromUser(const char[], int, const char[]);
int attemptToConvertStringToInteger(const char[], bool*);
void waitForKeyToContinue(const char[]);

#endif
