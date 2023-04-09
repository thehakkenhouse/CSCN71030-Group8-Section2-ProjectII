// RPS Pro: input.c
// Contains the implementations of the Input module's
// functions
//
// Module managed by Luna Parker

#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define CHAR_INPUT_LENGTH 1000
#define WAIT_BUFFER_LENGTH 500

void getStringFromUser(char inputString[], int maxLength) {
	// Get the input from the user using fgets
	fgets(inputString, maxLength, stdin);

	// Since fgets always returns a \n at the end of the input,
	// we'll remove it before returning from the function
	endStringAtNewLine(inputString);
}

bool isStringMinimumLength(const char inputString[], int minimumLength) {
	// Checks whether a string's number of characters is
	// greater than or equal to the given minimum length
	return strlen(inputString) >= minimumLength;
}

bool isStringSpecificChar(const char inputString[], char searchChar) {
	// Strings must be exactly 1 character long in order to satisfy
	// the condition that the string matches the character
	if(strlen(inputString) != 1)
	{
		return false;
	}

	return inputString[0] == searchChar;
}

bool getStringUpToChar(char stopChar, const char inputString[], char outputString[], int maxOutputStringSize) {
	bool stopCharExists = false;
	int numberOfOutputCharacters = 0;

	// We'll loop through each of the characters of the
	// input string until we either get to the line separator,
	// or the end of the string
	for(int i = 0; i < strlen(inputString); i++)
	{
		// If the character matches, we'll stop here
		// and flag that we've reached the line separator
		if(inputString[i] == stopChar)
		{
			stopCharExists = true;
			break;
		}

		// If the output string is too long to contain the
		// current input string, we'll stop here
		if(i >= (maxOutputStringSize - 2))
		{
			break;
		}

		// Otherwise, we'll update the output string to correspond
		// to the current input string's character
		outputString[i] = inputString[i];
		numberOfOutputCharacters++;
	}

	// Add a null terminator to the end of the new string 
	outputString[numberOfOutputCharacters] = '\0';

	return stopCharExists;
}

void getStringUpToSeparator(const char inputString[], char outputString[], int maxOutputStringLength)
{
	getStringUpToChar(LINE_SEPARATOR_CHARACTER, inputString, outputString, maxOutputStringLength);
}

void endStringAtNewLine(char inputString[]) {
	// We'll loop through until we find a new line, and if we do,
	// we'll make it the new end of the string
	for(int i = 0; i < strlen(inputString); i++)
	{
		if(inputString[i] == '\n')
		{
			inputString[i] = '\0';
			return;
		}
	}
}

char getCharFromUser(bool* successful) {
	*successful = false;

	// First we'll get a string from the user
	char userInputString[CHAR_INPUT_LENGTH];
	getStringFromUser(userInputString, CHAR_INPUT_LENGTH);

	// Then, we'll check whether they provided a valid input
	// A character string should only have 1 character
	if(strlen(userInputString) != 1)
	{
		// If they didn't provide a character, we'll indicate that
		// the request was unsuccessful and return a placeholder char
		return '\0';
	}

	// Otherwise, they did provide a valid input!
	// We'll return the 0th index of the string
	*successful = true;
	return userInputString[0];
}

char getValidCharFromUser(const char invalidInputMessage[]) {
	bool validCharProvided = false;
	char userInputChar = getCharFromUser(&validCharProvided);

	// If the user didn't provide a valid char, then we need
	// to keep prompting them until they provide one
	while(!validCharProvided)
	{
		// Tell the user that their input was invalid
		printf("%s", invalidInputMessage);

		// Prompt them again
		userInputChar = getCharFromUser(&validCharProvided);
	}

	return userInputChar;
}

bool isCharInArray(char inputChar, const char allowedChars[], int numberOfAllowedChars) {
	for(int i = 0; i < numberOfAllowedChars; i++)
	{
		// If the character matches the current index,
		// we know the character is in the array!
		if(allowedChars[i] == inputChar)
		{
			return true;
		}
	}

	return false;
}

char getAllowedCharFromUser(const char allowedChars[], int numberOfAllowedChars, const char invalidInputMessage[]) {
	// First, we'll get a valid character from the user
	char userInputChar = getValidCharFromUser(invalidInputMessage);

	// We'll see whether it's an allowed one
	bool isCharacterAllowed = isCharInArray(userInputChar, allowedChars, numberOfAllowedChars);

	// If the user didn't provide a character in the allowed list, we'll
	// tell them and prompt them again for a valid one until they provide
	// a valid one
	while(!isCharacterAllowed)
	{
		printf("%s", invalidInputMessage);
		userInputChar = getValidCharFromUser(invalidInputMessage);

		isCharacterAllowed = isCharInArray(userInputChar, allowedChars, numberOfAllowedChars);
	}

	// We know that we now have a valid character, and
	// we'll return it
	return userInputChar;
}

int attemptToConvertStringToInteger(const char possibleIntegerString[], bool* successful) {
	// This function tries, as safely as possible, to convert a
	// given input string to an integer
	//
	// Built with help from:
	// https://stackoverflow.com/questions/7021725/how-to-convert-a-string-to-integer-in-c#answer-12923949
	//
	// Note that strange behaviour happens with type casting of
	// characters - so using the isStringAllDigits function is
	// strongly recommended before using this function
	*successful = false;

	// We set the errno bit to 0 so that we can accurately
	// determine errors based on if it is not 0 after using
	// the strtol function
	errno = 0;
	// The finalPointer is used so that we can determine whether
	// it read through *all* of the string
	char* finalCharPointer;

	long possibleLongInteger = strtol(possibleIntegerString, &finalCharPointer, 10);

	// If errno is not 0 (indicating a conversion error), or
	// the finalCharPointer is not the null terminator, we know
	// a conversion error happened and should not interpret
	// the input further
	if (errno != 0 || (*finalCharPointer) != '\0') {
		return 0;
	}

	// If the user did provide a valid long integer, but it's
	// out of the range of a regular integer, we're no better
	// off and this also should count as an error
	if (possibleLongInteger < INT_MIN || possibleLongInteger > INT_MAX) {
		return 0;
	}

	// Otherwise, all is good, and we have a valid integer
	// from the given string
	*successful = true;
	return (int)possibleLongInteger;
}

void waitForKeyToContinue(const char promptMessage[]) {
	// Display a message asking the user to continue
	printf("%s", promptMessage);

	// Then wait for them to enter something...
	char tempBuffer[WAIT_BUFFER_LENGTH];
	fgets(tempBuffer, WAIT_BUFFER_LENGTH, stdin);
}
