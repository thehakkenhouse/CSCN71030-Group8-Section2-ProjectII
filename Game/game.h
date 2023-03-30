#pragma once

#include "authentication.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERROR_MESSAGE "An error occured"


int randomNumber();
char gameChoice(int randomNumber);
int gameResults(char userinput, char gameChoice);
int isRock(char computerchoice);
int isPaper(char computerchoice);
int isScissors(char computerchoice);
void printResult(int gameresult);
void gameScore(int commandlineargument, int gameresult, USER* user);