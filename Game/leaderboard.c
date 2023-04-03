// RPS Pro: leaderboard.c
// Contains the implementations of the Leaderboard module's
// functions
//
// Module managed by Michelle Novar

#include "leaderboard.h"
#include "memory.h"
#include <stdbool.h>
#include <stdio.h>




void printLeaderboardByHighestScore(const LEADERBOARD* leaderboard)
{
	// TODO: implement this function
}
// this function will print leaderboard in a sorted order from lowest to highest (max of 10?)
// communicates with file 
//  const char username[], int newScore




bool IsEmpty(LEADERBOARD* leaderboard) // isEmpty function definition, checks to see if leaderboard is empty or not
{
    if (leaderboard == NULL)
        return true;           // true returned if leaderboard is pointing to NULL, means it is empty.
    else
        return false;         // false is returned otherwise
}

// searches through the leaderboard for username. Returns current user if found, returns NULL if no match.
USER* searchByUsername(LEADERBOARD* leaderboard, char usernameToSearch[]) {    // this is the searchByUserName function definition
    // Set the current node to be the "first" node in the leaderboard
    LEADERBOARD_NODE* currentNode = leaderboard->firstNode;

    while (currentNode != NULL) {
        // Does the string username that is passed from authentication
        // match the current node's data username?

        USER* currentUser = currentNode->data;

        // If they do match...
        if (strcmp(currentUser->userName, usernameToSearch) == 0) {     
            // Quit early
            return currentUser;
        }

        // Otherwise, keep going to the next node
        currentNode = currentNode->next;
    }

    // There was no match
    return NULL;
}

LEADERBOARD_NODE* createLeaderboardNode(const USER* user) {             // this is the createLeaderboardNode function definition
    LEADERBOARD_NODE* newNode = malloc(sizeof(LEADERBOARD_NODE));

    newNode->data = user;  // new node is given data of user
    newNode->next = NULL;  // new node ends at NULL 

    return newNode;      // new node is returned
}

void insertUserIntoLeaderboard(LEADERBOARD* leaderboard, const USER* newUser) {  // this is the insertUserIntoLeaderboard functionn definition
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

/**
 * @brief Creates a new, empty leaderboard to work with
 * @return A leaderboard pointer to an empty Leaderboard
 *
 * @author Luna Parker
 */
LEADERBOARD* initializeNewLeaderboard(void)
{
    LEADERBOARD* newLeaderboard = tryToGetAndAssignMemorySafely(sizeof(LEADERBOARD));

    newLeaderboard->firstNode = NULL;

    return newLeaderboard;
}

/**
 * @brief Clears the leaderboard and all of its associated nodes/data from memory
 * @param leaderboard The leaderboard to clear
 *
 * @author Luna Parker
 */
void clearLeaderboardFromMemory(LEADERBOARD* leaderboard)
{
    // If the leaderboard itself hasn't been assigned in memory, then
    // there's nothing for us to free.
    if(leaderboard == NULL)
    {
        return;
    }

    LEADERBOARD_NODE* currentNode = leaderboard->firstNode;

    while(currentNode != NULL)
    {
        // We'll make a temporary node so that we can traverse
        // before freeing the pointer
    	LEADERBOARD_NODE* tempNode = currentNode;

        currentNode = currentNode->next;

        // We'll then free first the user (data) from the node,
        // and then free the node itself
        free(tempNode->data);
        free(tempNode);
    }

    free(leaderboard);
}
