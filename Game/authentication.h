

// RPS Pro: authentication.h
// Contains the definitions of the Authentication module's functions
// and data structures
//
// Module managed by Saba Berenji

#ifndef RPS_PRO_GAME_AUTHENTICATION_H
#define RPS_PRO_GAME_AUTHENTICATION_H

#include "leaderboard.h"
#include "input.h"
#include "menu.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define USER_NAME_LENGTH 30
#define PASSWORD_LENGTH 20

typedef struct user {                             // USER 
	char userName[USER_NAME_LENGTH];
	char password[PASSWORD_LENGTH];
	int score;
} USER;

// prototypes for authentication.h 
USER* createUser(const char[], const char[], int);
void copyUserName(const struct user*, char[]);
bool login(const struct leaderboard* leaderboard, struct user** currentUser);
bool signUp(struct leaderboard* leaderboard, struct user** user);
bool doesPasswordMatch(const struct user* leaderboardUser, const char inputPassword[]);

#endif