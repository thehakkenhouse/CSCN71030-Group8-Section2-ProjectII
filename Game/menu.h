// RPS Pro: menu.h
// Contains the definitions of the Menu module's functions
// and data structures
//
// Module managed by Luna Parker and Saba Berenji

#ifndef RPS_PRO_GAME_MENU_H
#define RPS_PRO_GAME_MENU_H

#include "leaderboard.h"
#include "authentication.h"

void runMenuAction(char input, LEADERBOARD*, USER*);
void runMainMenu(LEADERBOARD*, USER*);

#endif
