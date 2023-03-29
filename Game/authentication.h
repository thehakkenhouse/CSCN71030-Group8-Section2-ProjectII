// RPS Pro: authentication.h
// Contains the definitions of the Authentication module's functions
// and data structures
//
// Module managed by Saba Berenji

#pragma once
#define CRT_SECURE_NO_WARNINGS


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "menu.h"
#include "leaderboard.h"

#define USER_NAME_LENGTH 30
#define PASSWORD_LENGTH 20

typedef struct user {
	char userName[USER_NAME_LENGTH];
	char password[PASSWORD_LENGTH];
	int score;
} USER;

void copyUserName(const USER*, char[]);
bool login(const LEADERBOARD leaderboard, USER* currentUser);
bool signUp(LEADERBOARD leaderboard, USER* newUser);
bool doesPasswordMatch(const USER* leaderboardUser, const char inputPassword[]);
