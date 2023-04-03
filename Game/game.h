#pragma once

#include "authentication.h"
#include "input.h"
#include "menu.h"
#include "leaderboard.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
const char message[] = "An invalid char was inputted. Try again.\n";
#define ERROR_MESSAGE "An error occured"

void gamePlay(int commandlineargument, USER* currentuser);
int randomNumber();
char gameChoice(int randomNumber);
int gameResults(char userinput, char gameChoice);
int isRock(char computerchoice);
int isPaper(char computerchoice);
int isScissors(char computerchoice);
void printResults(int gameresult);
void gameScore(int commandlineargument, int gameresult, USER* user);
