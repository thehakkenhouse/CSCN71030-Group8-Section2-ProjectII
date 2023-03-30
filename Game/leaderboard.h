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


USER* searchByUsername(LEADERBOARD* leaderboard, char usernameToSearch[]) {
    // Set the current node to be the "first" node in the leaderboard
    LEADERBOARD_NODE* currentNode = leaderboard->firstNode;

    while (currentNode != NULL) {
        // Does the string username that is passed from authentication
        // match the current node's data username?

        USER* currentUser = currentNode->data;

        // If they do match...
        if (strcmp(currentUser->username, usernameToSearch) == 0) {
            // Quit early
            return currentUser;
        }

        // Otherwise, keep going to the next node
        currentNode = currentNode->next;
    }

    // There was no match
    return NULL;
}

LEADERBOARD_NODE* createLeaderboardNode(const USER* user) {
    LEADERBOARD_NODE* newNode = malloc(sizeof(LEADERBOARD_NODE));

    newNode->data = user;
    newNode->next = NULL;

    return newNode;
}

void insertUserIntoLeaderboard(LEADERBOARD* leaderboard, const USER* newUser) {
    LEADERBOARD_NODE* currentNode = leaderboard->firstNode;

    // If the leaderboard is empty
    if (leaderboard->firstNode == NULL) {
        leaderboard->firstNode = createLeaderboardNode(newUser);
        return;
    }

    // Keep going until the *next* element doesn't exist
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = createLeaderboardNode(newUser);
}


void printLeaderboardByHighestScore(const LEADERBOARD* leaderboard);                   // luna is creating this!
// this function will print leaderboard in a sorted order from lowest to highest (max of 10?)
// communicates with file 
//  const char username[], int newScore


USER* getUserByUsernameInLeaderboard(const LEADERBOARD* leaderboard, const char username[]);
// Authentication module sends username and this function returns either a pointer to a user in the leaderboard, or NULL if the username isn't  in the leaderboard

USER* displayLeaderboard(const LEADERBOARD* leaderboard);
//  user will use to go from menu to leaderboard , leaderboard and menu communicate

bool isEmpty(LEADERBOARD);



//void doesUsernameExistInDatabase(const LEADERBOARD* leaderboard, const char username[]);                         // is search one.             
//// this function will check if username exists in the leaderboard linked list. will use a while loop
//// communicates with file and authentication?

//void insertUserIntoLeaderboard(LEADERBOARD* leaderboard, USER* newUser);                                             // is create
//// this function will help with new user registration and will insert a new user into the leaderboard
//// communicates with file and authentication?                                                        
//
//void addUserToLeaderboard(LEADERBOARD* leaderboard, USER* newUser);                               // insert
//// Authentication module sends new user to this function

//void exitToMainMenu();                                          // is this needed? 
//// player uses to exit leaderboard and go to menu
//// communicates with menu 

//void updateUserScore(USER* userToUpdate, int newScore);                   // don't need? in game?
//// Game module sends new score to this function
//// this function will take a USER pointer to change the score
//// communicates with game and file?


#endif


