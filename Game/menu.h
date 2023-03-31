// RPS Pro: menu.h
// Contains the definitions of the Menu module's functions
// and data structures
//
// Module managed by Luna Parker and Saba Berenji

#ifndef RPS_PRO_GAME_MENU_H
#define RPS_PRO_GAME_MENU_H

#include "leaderboard.h"
#include "authentication.h"

void printMainMenuIntroduction(const struct user*);
void printMainMenuOptions(const char[], const char*[]);
void printMainMenu(const struct user*, const char[], const char*[]);
void runMenuAction(char input, struct leaderboard*, struct user*);
void runMainMenu(struct leaderboard*, struct user*);
void printSecondMenuOptions(const char[], const char*[]);

#endif
