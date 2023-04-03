
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

void printMenuIntroduction(const struct user* currentUser);
void printTopMenuOptions(const char optionCharacters[], const char* optionNames[]);
void printSecondMenu(const struct user* currentUser, const char optionCharacters[], const char* optionNames[]);
bool runTopMenuAction(char input, struct leaderboard* leaderboard, struct user* currentUser);
void printSecondMenuOptions(const char optionCharacters[], const char* optionNames[]);
void runSecondMenuAction(char input, struct leaderboard* leaderboard, struct user* currentUser, int commandlineargument);
void runTopMenu(int commandlineargument);
void runSecondMenu(struct leaderboard* leaderboard, struct user* currentUser, int commandlineargument);

#endif
