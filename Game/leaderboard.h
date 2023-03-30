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


void printLeaderboardByHighestScore(const LEADERBOARD* leaderboard);
// this function will print leaderboard in a sorted order from lowest to highest (max of 10?)
// communicates with file 
//  const char username[], int newScore


void doesUsernameExistInDatabase(const LEADERBOARD* leaderboard, const char username[]);
// this function will check if username exists in the leaderboard linked list. will use a while loop
// communicates with file and authentication?

void insertUserIntoLeaderboard(LEADERBOARD* leaderboard, USER* newUser);
// this function will help with new user registration and will insert a new user into the leaderboard
// communicates with file and authentication?                                                        // is this the same as addUserToLeaderboard?

void addUserToLeaderboard(LEADERBOARD* leaderboard, USER* newUser);
// Authentication module sends new user to this function

void exitToMainMenu();
// player uses to exit leaderboard and go to menu
// communicates with menu 

void updateUserScore(USER* userToUpdate, int newScore);
// Game module sends new score to this function
// this function will take a USER pointer to change the score
// communicates with game and file?

USER* getUserByUsernameInLeaderboard(const LEADERBOARD* leaderboard, const char username[]);
// Authentication module sends username and this function returns either a pointer to a user in the leaderboard, or NULL if the username isn't  in the leaderboard

USER* displayLeaderboard(const LEADERBOARD* leaderboard);
//  user will use to go from menu to leaderboard , leaderboard and menu communicate



#endif


