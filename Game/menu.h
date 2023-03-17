// RPS Pro: menu.h
// Contains the definitions of the Menu module's functions
// and data structures
//
// Module managed by Luna Parker and Saba Berenji

#ifndef RPS_PRO_GAME_MENU_H
#define RPS_PRO_GAME_MENU_H

#include "leaderboard.h"
#include "authentication.h"

void printMainMenuIntroduction(const USER*);
void printMainMenuOptions(const char[], const char*[]);
void printMainMenu(const USER*, const char[], const char*[]);
void runMenuAction(char input, LEADERBOARD*, USER*);
void runMainMenu(LEADERBOARD*, USER*);

#endif
