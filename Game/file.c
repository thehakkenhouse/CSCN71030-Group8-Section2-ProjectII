// RPS Pro: file.c
// Contains the implementations of the File module's
// functions
//
// Module managed by Luna Parker

#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILE_READ_MODE "r"
#define FILE_WRITE_MODE "w"

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
 * @brief Converts a given string into its binary equivalent string
 * @param inputString The ASCII string which should be converted into a binary-equivalent string
 * @return A binary string pointer if it could be converted and assigned, or NULL if it could not
 *
 * @author Luna Parker
 */
 char* convertStringToBinary(const char inputString[]) {
	 char* returnPointer = NULL;

}

void interpretLeaderboardLine(const char inputLine[], unsigned int userId, char userName[], int userScore) {
	// TODO: implement this function
}

void insertUserFromLeaderboardLine(const char inputLine[], LEADERBOARD* leaderboard) {
	// TODO: implement this function
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
