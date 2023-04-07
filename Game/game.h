#pragma once

#include "authentication.h"
#include "input.h"
#include "leaderboard.h"
#include "menu.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERROR_MESSAGE "An error occured"

// prototypes for game.h 
void gamePlay(int commandlineargument, struct user* currentuser);
int randomNumber();
char gameChoice(int randomNumber);
int gameResults(char userinput, char gameChoice);
int isRock(char computerchoice);
int isPaper(char computerchoice);
int isScissors(char computerchoice);
void printResults(int gameresult);
void gameScore(int commandlineargument, int gameresult, struct user* currentuser);
