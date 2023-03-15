// RPS Pro: input.c
// Contains the implementations of the Input module's
// functions
//
// Module managed by Luna Parker

#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void getStringFromUser(char inputString[], int maxLength) {
	// TODO: implement this function using fgets
}

bool isStringMinimumLength(const char inputString[], int minimumLength) {
	// TODO: implement this function
	return false;
}

bool isStringSpecificChar(const char inputString[], char searchChar) {
	// TODO: implement this function
	return false;
}

bool getStringUpToLineSeparator(const char inputString[], char outputString[], int maxOutputStringSize) {
	// TODO: implement this function
	return false;
}

void removeNewLineFromString(const char inputString[], char outputString[], int maxOutputStringSize) {
	// TODO: implement this function
}

char getCharFromUser(bool* successful) {
	// TODO: implement this function
	return false;
}

char getValidCharFromUser(const char invalidInputMessage[]) {
	// TODO: implement this function
	return '\0';
}

bool isCharInArray(char inputChar, const char allowedChars[], int numberOfAllowedChars) {
	// TODO: implement this function
	return false;
}

char getAllowedCharFromUser(const char allowedChars[], int numberOfAllowedChars, const char invalidInputMessage[]) {
	// TODO: implement this function
	return '\0';
}
