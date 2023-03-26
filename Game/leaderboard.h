// RPS Pro: leaderboard.h
// Contains the definitions of the Leaderboard module's functions
// and data structures
//
// Module managed by Michelle Novar

#ifndef RPS_PRO_GAME_LEADERBOARD_H
#define RPS_PRO_GAME_LEADERBOARD_H

#include "authentication.h"

typedef struct leaderboardNode {
	USER* data;
	struct leaderboardNode* next;
} LEADERBOARD_NODE;

typedef struct leaderboard {
	struct leaderBoardNode* firstNode;
} LEADERBOARD;


printLeaderboardByHighestScore();
// this function will print leaderboard in a sorted order from lowest to highest (max of 10?)


doesUsernameExostInDatabase();
// this function will check if username exists in the leaderboard linked list. will use a while loop

insertUserIntoLeaderboard();
// this function will help with new user registration and will insert a new user into the leaderboard


updateUserScore();
//this function will take a USER pointer to change the score



#endif


