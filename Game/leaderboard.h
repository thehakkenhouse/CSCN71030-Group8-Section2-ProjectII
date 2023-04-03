// RPS Pro: leaderboard.h
// Contains the definitions of the Leaderboard module's functions
// and data structures
//
// Module managed by Michelle Novar

#ifndef RPS_PRO_GAME_LEADERBOARD_H
#define RPS_PRO_GAME_LEADERBOARD_H

#include "authentication.h"   
#include <stdbool.h>

// please see leaderboard.c for the function definitions

typedef struct leaderboardNode {
	struct user* data;
	struct leaderboardNode* next;
} LEADERBOARD_NODE;

typedef struct leaderboard {
	struct leaderboardNode* firstNode;
} LEADERBOARD;

struct user* searchByUsername(struct leaderboard*, char[]); // this is the searchByUserName function prototype
struct leaderboardNode* createLeaderboardNode(const struct user*);    // this is the createLeaderboardNode function prototype
void insertUserIntoLeaderboard(struct leaderboard*, const struct user*); // this is the insertUserIntoLeaderboard function prototype
bool IsEmpty(struct leaderboard*); // isEmpty function prototype, checks to see if leaderboard is empty or not.
LEADERBOARD* initializeNewLeaderboard(void);
void clearLeaderboardFromMemory(struct leaderboard*);
void sortLeaderboardByScore(struct leaderboard*);
void printLeaderboardUser(const struct user*);
void printLeaderboardByHighestScore(struct leaderboard*);

// this function will print leaderboard in a sorted order from lowest to highest (max of 10?)
// communicates with file 
//  const char username[], int newScore



// i believe these can go?
// 
// USER* getUserByUsernameInLeaderboard(const LEADERBOARD* leaderboard, const char username[]);               // i believe this is search?
// Authentication module sends username and this function returns either a pointer to a user in the leaderboard, 
// or NULL if the username isn't  in the leaderboard



// USER* displayLeaderboard(const LEADERBOARD* leaderboard);
//  user will use to go from menu to leaderboard , leaderboard and menu communicate                           // i believe this is same as print?


//void doesUsernameExistInDatabase(const LEADERBOARD* leaderboard, const char username[]);                         // i believe this is search?
//// this function will check if username exists in the leaderboard linked list. will use a while loop
//// communicates with file and authentication?

//void insertUserIntoLeaderboard(LEADERBOARD* leaderboard, USER* newUser);                                             // i believe this is create?
//// this function will help with new user registration and will insert a new user into the leaderboard
//// communicates with file and authentication?                                                        
//
//void addUserToLeaderboard(LEADERBOARD* leaderboard, USER* newUser);                                                   // i believe this is insert?
//// Authentication module sends new user to this function

//void exitToMainMenu();                                                                                                   // is this needed? is it in main?
//// player uses to exit leaderboard and go to menu
//// communicates with menu 

//void updateUserScore(USER* userToUpdate, int newScore);                                                           // is this needed? is it in game?
//// Game module sends new score to this function
//// this function will take a USER pointer to change the score
//// communicates with game and file?

#endif


