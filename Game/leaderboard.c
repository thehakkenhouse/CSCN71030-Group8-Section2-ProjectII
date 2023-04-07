// RPS Pro: leaderboard.c
// Contains the implementations of the Leaderboard module's
// functions
//
// Module managed by Michelle Novar

#include "leaderboard.h"
#include "memory.h"
#include <stdbool.h>
#include <stdio.h>

#define LEADERBOARD_INTRODUCTION_FORMAT "\nWelcome to the Leaderboard! Here's a list of the highest to lowest scoring players. Try your best to get to the top!\n\n"
#define LEADERBOARD_USER_PRINT_FORMAT "%s -- Score: %d\n"
#define QUIT_LEADERBOARD_PROMPT "\nPress any key to return to the menu...\n"


bool IsEmpty(struct leaderboard* leaderboard) // isEmpty function definition, checks to see if leaderboard is empty or not
{
    // If the leaderboard itself hasn't been defined, return false
    if (leaderboard == NULL) {
        return false;
    }

    return leaderboard->firstNode == NULL;
}

// searches through the leaderboard for username. Returns current user if found, returns NULL if no match.
struct user* searchByUsername(struct leaderboard* leaderboard, char usernameToSearch[]) {    // this is the searchByUserName function definition
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

struct leaderboardNode* createLeaderboardNode(const struct user* user) {             // this is the createLeaderboardNode function definition
    LEADERBOARD_NODE* newNode = malloc(sizeof(LEADERBOARD_NODE));

    newNode->data = user;  // new node is given data of user
    newNode->next = NULL;  // new node ends at NULL 

    return newNode;      // new node is returned
}

void insertUserIntoLeaderboard(struct leaderboard* leaderboard, const struct user* newUser) {  // this is the insertUserIntoLeaderboard function definition
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
void clearLeaderboardFromMemory(struct leaderboard* leaderboard)
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

/**
 * @brief Sorts the given leaderboard in descending order of score
 * @param leaderboard The leaderboard to sort in-place
 * 
 * @author Luna Parker
 */
void sortLeaderboardByScore(struct leaderboard* leaderboard) {
    // We should make sure that this is an initialized
    // leaderboard. If it's not initialized, we can't sort
    // anything.
    if (leaderboard == NULL) {
        return;
    }

    // We should make sure that the leaderboard has at least
    // 1 element. If it doesn't, there's nothing to sort.
    if (leaderboard->firstNode == NULL) {
        return;
    }

    bool swapped = false;
    LEADERBOARD_NODE* currentPointer;
    LEADERBOARD_NODE* lptr = NULL;

    // Bubble Sorting in-place
    // Adapted with help from:
    // https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/
    do
    {
        swapped = false;
        currentPointer = leaderboard->firstNode;

        while (currentPointer->next != lptr)
        {
            USER* currentUser = currentPointer->data;
            USER* nextUser = currentPointer->next->data;

            if (currentUser->score < nextUser->score)
            {
                // Swap the users
                currentPointer->data = nextUser;
                currentPointer->next->data = currentUser;
                swapped = true;
            }

            currentPointer = currentPointer->next;
        }

        lptr = currentPointer;

    } while (swapped);
}

/**
 * @brief Prints a single Leaderboard user in the correct format
 * @param user The Leaderboard user to print
 * 
 * @author Luna Parker
 */
void printLeaderboardUser(const struct user* user) {
    printf(LEADERBOARD_USER_PRINT_FORMAT, user->userName, user->score);
}

/**
 * @brief Prints all users in the leaderboard in descending order of score
 * @param leaderboard The Leaderboard to print
 * 
 * @author Luna Parker
 */
void printLeaderboardByHighestScore(struct leaderboard* leaderboard) {
    // If either the leaderboard is not initialized, or it has no
    // data within it, we'll return early
    if (leaderboard == NULL || leaderboard->firstNode == NULL) {
        return;
    }

    printf(LEADERBOARD_INTRODUCTION_FORMAT);

    // We'll sort the leaderboard in descending score order
    sortLeaderboardByScore(leaderboard);

    // We'll start at the top of the list, and work our way down
    // to the bottom
    LEADERBOARD_NODE* currentNode = leaderboard->firstNode;

    while (currentNode != NULL) {
        // We'll get this node's associated user, and print them
        USER* currentUser = currentNode->data;
        printLeaderboardUser(currentUser);

        // Then, we'll iterate to the next node
        currentNode = currentNode->next;
    }

    waitForKeyToContinue(QUIT_LEADERBOARD_PROMPT);
}
