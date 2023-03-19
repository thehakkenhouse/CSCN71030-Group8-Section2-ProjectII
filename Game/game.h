#pragma once

#include "authentication.h"
#include <stdio.h>
#include <stdbool.h>

int randomNumber();
char gameChoice();
int gameResults(char userinput);
int isRock(char computerchoice);
int isPaper(char computerchoice);
int isScissors(char computerchoice);
void printResult(int gameresult);
int gameScore(int commandlineargument, int gameresult, USER user);