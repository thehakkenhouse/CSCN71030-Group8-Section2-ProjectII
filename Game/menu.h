
// RPS Pro: menu.h
// Contains the definitions of the Menu module's functions
// and data structures
//
// Module managed by Luna Parker and Saba Berenji

#ifndef RPS_PRO_GAME_MENU_H
#define RPS_PRO_GAME_MENU_H

#include "leaderboard.h"
#include "authentication.h"
#include <stdbool.h>

// prototypes for menu.h 
void printMenuIntroduction(const struct user*);
void printTopMenuOptions(const char[], const char*[]);
void printSecondMenu(const struct user*, const char[], const char*[]);
bool runTopMenuAction(char, struct leaderboard*, struct user**);
void printSecondMenuOptions(const char[], const char*[]);
void runSecondMenuAction(char, struct leaderboard*, struct user*, int);
void runTopMenu(int, struct leaderboard*, struct user**);
void runSecondMenu(struct leaderboard*, struct user*, int);
void printLeaderboardSaveMessage(bool);

#endif
