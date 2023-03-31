// RPS Pro: game.c
// Contains the implementations of the File module's
// functions
//
// Module managed by Sierra Erb

#include "authentication.h"
#include "game.h"
#include "input.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>


int randomNumber()
{
    srand(time(NULL)); //using srand to make the random function more random, seeding it with time(NULL) 

    int randomnumber = rand() % 3 + 1; //randomly generates a number between 1-3 inclusively

    return randomnumber; //returns the randomly generated number 
}

char gameChoice(int randomNumber)
{
    if (randomNumber == 1)
        return 'r'; //random number 1 corresponds to the game choice of rock
    else if (randomNumber == 2)
        return 'p'; //random number 2 corresponds to the game choice of paper
    else if (randomNumber == 3)
        return 's'; //random number 3 corresponds to the game choice of scissors
}

int gameResults(char userinput, char gameChoice)
{

  //  char computerchoice = gameChoice(); //calls gameChoice function to get the computer generated game choice
    printf("%c", gameChoice);
    int gameresult = 0;
    if (userinput == 'r' || userinput == 'R') //if the user inputted rock - either capital or not
    {
        gameresult = isRock(gameChoice); //calls on isRock function

    }
    else if (userinput == 'p' || userinput == 'P') //if the user inputted paper - either capital or not
    {
        gameresult = isPaper(gameChoice); //calls on isPaper function
    }
    else if (userinput == 's' || userinput == 'S') //if user entered scissors - either capital or not
    {
        gameresult = isScissors(gameChoice); //calls on isScissors function
    }
    else
    {
        gameresult = -1;
        printf("%s\n", ERROR_MESSAGE);
    }
    PrintResult(gameresult);
    return gameresult; //error using uninitialized memory //results the result of the game (0 for user win, 1 for user loss, and 2 for tie)
}

int isRock(char computerchoice)
{
   // int result; //0 means a win, 1 means a loss, 2 means a tie
    if (computerchoice == 'r') //user entered rock and so did computer
        return 2; //tie game
    else if (computerchoice == 'p') //user entered rock and computer chose paper
        return 1; //user lost
    else if (computerchoice == 's') //user entered rock and computer chose scissors
        return 0; //user won
    else
        return -1;
}

int isPaper(char computerchoice)
{
  //  int result; //0 means a win, 1 means a loss, 2 means a tie
    if (computerchoice == 'r') //user entered paper and computer chose rock
        return 0; //user won
    else if (computerchoice == 'p') //user entered paper and computer chose paper
        return 2; //tie game
    else if (computerchoice == 's') //user entered paper and computer chose scissors
        return 1; //user lost
    else
        return -1;
}


int isScissors(char computerchoice)
{
    //int result; //0 means a win, 1 means a loss, 2 means a tie
    if (computerchoice == 'r') //user entered scissors and computer chose rock
        return 1; //user lost
    else if (computerchoice == 'p') //user entered scissors and computer chose paper
        return 0; //user won
    else if (computerchoice == 's') //user entered scissors and computer chose scissors
        return 2; //tie game
    else
        return -1;
}

void printResult(int gameresult)
{
    if (gameresult == 0) //if the user won
        printf("You won! Great job!\n");
    else if (gameresult == 1) //if the user lost
        printf("You lost! Too bad, so sad!\n");
    else if (gameresult == 2) //if there was a tie game
        printf("Tie game! I'll get you next time!\n");
    else
        printf("%s\n", ERROR_MESSAGE);
}


void gameScore(int commandlineargument, int gameresult, USER* user)
{
    int score = 0;
    if (gameresult == 0)
    {
        score = commandlineargument * 1;
    }
    else if (gameresult == 1)
    {
        score = commandlineargument * (-1);
    }
    else if (gameresult == 2)
    {
        score = 0;
    }
    printf("Score: %d\n", score);
    user->score = user->score + score;
}
