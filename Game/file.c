// RPS Pro: file.c
// Contains the implementations of the File module's
// functions
//
// Module managed by Luna Parker

#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool doesFileExist(const char fileName[]) {
	// TODO: implement this function
	return false;
}

FILE* tryToOpenFile(const char fileName[], const char fileAccessMode[], bool* successful) {
	// TODO: implement this function
	*successful = false;
	return NULL;
}

void convertStringToBinary(const char inputString[], char binaryOutputString[], int outputMaxLength) {
	// TODO: implement this function
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
