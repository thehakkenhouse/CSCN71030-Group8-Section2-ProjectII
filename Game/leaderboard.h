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



#endif


