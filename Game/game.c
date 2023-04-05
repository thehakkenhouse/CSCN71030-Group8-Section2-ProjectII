// RPS Pro: game.c
// Contains the implementations of the File module's
// functions
//
// Module managed by Sierra Erb

#include "game.h"
#include "authentication.h"
#include "input.h"
#include "input.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define INVALID_INPUT_MESSAGE "Invalid input. Please try again.\n"
#define PROMPT_GAME_MESSAGE "Let's play a game of Rock, Paper, Scissors! Enter R for rock, P for paper, or S for scissors!\n"

//gamePlay will be called in the menu module when the user choses to play a game and calls all necessary functions to 
//play a game
void gamePlay(int commandlineargument, USER* currentuser)
{
    srand(time(NULL)); //using srand to make the random function more random, seeding it with time(NULL) 
    
    int randomnumbers = randomNumber(); //generates random number using rand and assigns it to randomnumbers
    char gamechoices = gameChoice(randomnumbers); //generates computer choice based on the random number
    printf("%s", PROMPT_GAME_MESSAGE);
    char validchar = getValidCharFromUser(INVALID_INPUT_MESSAGE); //gets a valid char from the user (this function comes from the input module)
    while (validchar != 'r' && validchar != 'p' && validchar != 's' && validchar != 'R' && validchar != 'P' && validchar != 'S')
    {
        printf("%s", INVALID_INPUT_MESSAGE);
        validchar = getValidCharFromUser(INVALID_INPUT_MESSAGE);
    }
    int gameresults = gameResults(validchar, gamechoices); //generates the game results based on the user input and computer input
    gameScore(commandlineargument, gameresults, currentuser); //updates user struct based on the resuls of the game
}

//generates a randomNumber to help select computer input
int randomNumber()
{
    int randomnumber = rand() % 3 + 1; //randomly generates a number between 1-3 inclusively

    return randomnumber; //returns the randomly generated number 
}

//this function will assign a computer input based on the random number that was generated
char gameChoice(int randomNumber)
{
    if (randomNumber == 1)
        return 'r'; //random number 1 corresponds to the game choice of rock
    else if (randomNumber == 2)
        return 'p'; //random number 2 corresponds to the game choice of paper
    else if (randomNumber == 3)
        return 's'; //random number 3 corresponds to the game choice of scissors
}

//this function will take the users input and computer input and generates a result 
int gameResults(char userinput, char gameChoice)
{
    int gameresult = 0;
    printf("Computer choice: %c\n", gameChoice);
    printf("User choice: %c\n", userinput);
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
    }
    printResults(gameresult);
    return gameresult; //error using uninitialized memory //results the result of the game (0 for user win, 1 for user loss, and 2 for tie)
}

//if the user chose rock, this function will be called to determine result of the game
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

//if the user chose paper, this function will be called to determine result of the game
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

//if the user chose scissors, this function will be called to determine result of the game
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

//this function will print the result of the game to the screen
void printResults(int gameresult)
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

void gameScore(int commandlineargument, int gameresult, USER* currentuser)
{
    int score = 0;
    if (gameresult == 0) //user won the game (+1 added to score)
    {
        score = commandlineargument * 1; //whatever the command line argument is we will multiply it by +1
    }
    else if (gameresult == 1) //user lost the game (-1 added to score)
    {
        score = commandlineargument * (-1); //whatever the command line argument is we will multiply it by -1
    }
    else if (gameresult == 2) //tied game
    {
        score = 0; //score does not change when the game is tied
    }
    else
    {
        score = 0;
    }
    printf("Score: %d\n", score);
    currentuser->score = currentuser->score + score;
}
