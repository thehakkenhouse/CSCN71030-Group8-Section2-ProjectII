
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

void printMenuIntroduction(const USER* currentUser);
void printTopMenuOptions(const char optionCharacters[], const char* optionNames[]);
void printSecondMenu(const USER* currentUser, const char optionCharacters[], const char* optionNames[]);
bool runTopMenuAction(char input, LEADERBOARD* leaderboard, USER* currentUser);
void printSecondMenuOptions(const char optionCharacters[], const char* optionNames[]);
void runSecondMenuAction(char input, LEADERBOARD* leaderboard, USER* currentUser, int commandlineargument);
void runTopMenu(int commandlineargument);
void runSecondMenu(LEADERBOARD* leaderboard, USER* currentUser, int commandlineargument);




#endif