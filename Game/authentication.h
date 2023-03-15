// RPS Pro: authentication.h
// Contains the definitions of the Authentication module's functions
// and data structures
//
// Module managed by Saba Berenji

#ifndef RPS_PRO_GAME_AUTHENTICATION_H
#define RPS_PRO_GAME_AUTHENTICATION_H

#define USER_NAME_LENGTH 30

typedef struct user {
	// TODO: write user struct
	unsigned int id;
	const char userName[USER_NAME_LENGTH];
	int score;
} USER;

#endif
