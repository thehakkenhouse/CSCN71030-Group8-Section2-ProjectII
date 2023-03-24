// RPS Pro: authentication.h
// Contains the definitions of the Authentication module's functions
// and data structures
//
// Module managed by Saba Berenji

#ifndef RPS_PRO_GAME_AUTHENTICATION_H
#define RPS_PRO_GAME_AUTHENTICATION_H

#define USER_NAME_LENGTH 30
#define PASSWORD_LENGTH 20

typedef struct user {
	char userName[USER_NAME_LENGTH];
	char password[PASSWORD_LENGTH];
	int score;
} USER;

void copyUserName(const USER*, char[]);

#endif
