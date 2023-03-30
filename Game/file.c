#define _CRT_SECURE_NO_WARNINGS 1

// RPS Pro: file.c
// Contains the implementations of the File module's
// functions
//
// Module managed by Luna Parker

#include "file.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DATA_SEPARATOR_CHAR '|'
#define FILE_READ_MODE "r"
#define FILE_WRITE_MODE "w"
#define BITS_IN_CHAR 8
#define NULL_TERMINATOR '\0'
#define NULL_TERMINATOR_SIZE 1

/**
 * @brief Tries to open and return a file pointer.
 * @param fileName The relative/absolute path of the file to try to open.
 * @param fileAccessType What permissions you want to have with the file ("r" = read-only, "w" = clear and then write)
 * @param fileOpenedSuccessfully A boolean pointer that will be updated with whether the file could be opened
 * @return A file pointer corresponding with the file and access type requested, or NULL if it could not be opened
 *
 * @author Luna Parker
 */
FILE* tryToOpenFile(const char fileName[], const char fileAccessType[], bool* fileOpenedSuccessfully) {
    *fileOpenedSuccessfully = false;
    FILE* filePointer = fopen(fileName, fileAccessType);

    // If the pointer is not null, we know that the file could be opened
    // with requested permissions successfully
    if (filePointer != NULL) {
        *fileOpenedSuccessfully = true;
    }

    return filePointer;
}

void closeFile(FILE* fileToClose) {
    fclose(fileToClose);
}

/**
 * @brief Checks whether a file exists and can be opened.
 * @param fileName The name of the file or path to try to open.
 * @return A boolean indicating whether the file exists and could be opened
 *
 * @author Luna Parker
 */
bool doesFileExist(const char fileName[]) {
    bool fileOpenedSuccessfully;

    // Check if the file is able to open successfully
    FILE* possibleFile = tryToOpenFile(fileName, FILE_READ_MODE, &fileOpenedSuccessfully);

    // If the file did open successfully, we'll need to close it before returning
    if (fileOpenedSuccessfully) {
        closeFile(possibleFile);
    }

    return fileOpenedSuccessfully;
}

/**
 * @brief Calculates the length of a binary-string equivalent of an ASCII string
 * @param inputString The ASCII string which you want the size of as a binary string
 * @return The length of the equivalent binary string in bytes
 *
 * @author Luna Parker
 */
size_t calculateAsciiStringSizeAsBinaryString(const char inputString[])
{
    // First we'll get the original length of the string
    size_t lengthOfString = strlen(inputString);

    // Then we'll return the equivalent as a binary string
    // As a reminder, each character in C is represented by 1 byte (8 bits)
    // Therefore, the corresponding string will be 8x as long as the ASCII string.
    // We also need the null terminator at the end of the string.
    return lengthOfString * BITS_IN_CHAR + NULL_TERMINATOR_SIZE;
}

/**
 * @brief Calculates the length of an ASCII-string equivalent of a binary string
 * @param inputBinaryString The binary string which you want the size of in ASCII
 * @return The length of the equivalent ASCII string in bytes
 *
 * @author Luna Parker
 */
size_t calculateBinaryStringSizeAsAsciiString(const char inputBinaryString[])
{
	// First we'll get the length of the binary string
    size_t lengthOfBinaryString = strlen(inputBinaryString);

    // Then we'll return the equivalent as an ASCII string
    // Since a character is represented by 8 bits, we only need 1/8 of
    // the space in the new string
    return lengthOfBinaryString / BITS_IN_CHAR + NULL_TERMINATOR_SIZE;
}

/**
 * @brief Converts a given string into its binary equivalent string
 * @param inputString The ASCII string which should be converted into a binary-equivalent string
 * @return A binary string pointer if it could be converted and assigned, or NULL if it could not
 *
 * @author Luna Parker
 */
 char* convertAsciiStringToBinary(const char inputString[]) {
    // Note: this function is adapted from:
    // https://stackoverflow.com/questions/41384262/convert-string-to-binary-in-c#answer-41384915

    char* binaryStringPointer = tryToGetAndAssignMemorySafely(calculateAsciiStringSizeAsBinaryString(inputString));

    // We'll put the null terminator at the beginning of the string, but
    // it will move back as we iterate through each character
    binaryStringPointer[0] = NULL_TERMINATOR;

    // We'll loop through each of the characters from the input string
    for(int i = 0; i < strlen(inputString); i++)
    {
	    for(int j = 7; j >= 0; --j)
	    {
		    if(inputString[i] & (1 << j))
		    {
                strcat(binaryStringPointer, "1");
		    } else
		    {
                strcat(binaryStringPointer, "0");
		    }
	    }
    }

    return binaryStringPointer;
}

/**
 * @brief Gets a character from a given character index of the binary string
 * @param inputBinaryString The binary string
 * @param charIndex The character-based index to convert
 * @return The character corresponding with the given character index
 *
 * @author Luna Parker
 */
char getCharacterFromBinaryStringIndex(const char inputBinaryString[], int charIndex)
{
    char currentBinaryString[BITS_IN_CHAR + NULL_TERMINATOR_SIZE];
    int startingByteIndex = charIndex * BITS_IN_CHAR;

    // Loop through all of the characters of the current segment of the binary string
    for(int i = 0; i < BITS_IN_CHAR; i++)
    {
        currentBinaryString[i] = inputBinaryString[startingByteIndex + i];
    }

    // Add a null terminator at the end of the new string
    currentBinaryString[BITS_IN_CHAR] = NULL_TERMINATOR;

    // Then, convert this subset of the string into a corresponding integer
    long int byteAsInt = strtol(currentBinaryString, 0, 2);

    return (char)byteAsInt;
}

/**
 * @brief Converts a given string of binary into its ASCII equivalent string
 * @param inputBinaryString The binary string
 * @return An ASCII string pointer if it could be converted and assigned, or NULL if it could not
 *
 * @author Luna Parker
 */
char* convertBinaryStringToAscii(const char inputBinaryString[])
{
    size_t numberOfBytesInNewString = calculateBinaryStringSizeAsAsciiString(inputBinaryString);
    char* asciiStringPointer = tryToGetAndAssignMemorySafely(numberOfBytesInNewString);

    // We'll loop through each "final" ASCII character
    for(int i = 0; i < (numberOfBytesInNewString - 1); i++)
    {
	    // We'll get the current character from the corresponding original 8 bits in the input string
        char currentChar = getCharacterFromBinaryStringIndex(inputBinaryString, i);

        asciiStringPointer[i] = currentChar;
    }

    // Add a null terminator at the end of the string
    asciiStringPointer[numberOfBytesInNewString - NULL_TERMINATOR_SIZE] = NULL_TERMINATOR;

    return asciiStringPointer;
}

void interpretLeaderboardLine(const char inputLine[], unsigned int userId, char userName[], int userScore) {
	// TODO: implement this function
}

void insertUserFromLeaderboardLine(const char inputLine[], LEADERBOARD* leaderboard) {
	// TODO: implement this function
}

/**
 * @brief Removes any data separators from the given string
 * @param inputString The unclean/unsafe string that will be updated to be clean
 *
 * @author Luna Parker
 */
void cleanStringOfSeparators(char inputString[])
{
    // Loop through each character until the end of the string
    for(int i = 0; i < strlen(inputString); i++)
    {
	    // If the string is our data separator, then it will be replaced
        // with a space
        if(inputString[i] == DATA_SEPARATOR_CHAR)
        {
            inputString[i] = ' ';
        }
    }
}

void convertUserToLeaderboardLine(const USER* user, char formattedLeaderboardLine[]) {
	// TODO: implement this function
}

void saveLeaderboardToFile(LEADERBOARD* leaderboard) {
	// TODO: implement this function
}

void readLeaderboardFromFile(LEADERBOARD* leaderboard) {
	// TODO: implement this function
}
