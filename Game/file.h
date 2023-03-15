// RPS Pro: file.h
// Contains the definitions of the File module's functions
// and data structures
//
// Module managed by Luna Parker

#ifndef RPS_PRO_GAME_FILE_H
#define RPS_PRO_GAME_FILE_H

#include "leaderboard.h"
#include <stdio.h>
#include <stdbool.h>

bool doesFileExist(const char[]);
FILE* tryToOpenFile(const char[], const char[], bool*);
void convertStringToBinary(const char[], char[], int);
void interpretLeaderboardLine(const char[], unsigned int, char[], int);
void insertUserFromLeaderboardLine(const char[], LEADERBOARD*);
void convertUserToLeaderboardLine(const USER*, char[]);
void saveLeaderboardToFile(LEADERBOARD*);
void readLeaderboardFromFile(LEADERBOARD*);

#endif
