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


doesUsernameExistInDatabase();
// this function will check if username exists in the leaderboard linked list. will use a while loop

insertUserIntoLeaderboard();
// this function will help with new user registration and will insert a new user into the leaderboard


updateUserScore();
//this function will take a USER pointer to change the score


// luna said this, but it's not in the game or authentication module. 
// 
//void updateUserScore(USER* userToUpdate, int newScore);
//->Game module sends new score to this function
//
//void addUserToLeaderboard(LEADERBOARD* leaderboard, USER* newUser);
//->Authentication module sends new user to this function
//
//USER* getUserByUsernameInLeaderboard(const LEADERBOARD* leaderboard, const char username[]);
//->Authentication module sends username and this function returns either a pointer to a user in the leaderboard, or NULL if the username isn't  in the leaderboard




#endif


