// RPS Pro: menu.c
// Contains the implementations of the Menu module's
// functions
//
// Module managed by Luna Parker and Saba Berenji

#include "menu.h"
#include "authentication.h"
#include "input.h"
#include "leaderboard.h"
#include <stdio.h>

#define FIRST_OPTION_CHAR 'a'
#define SECOND_OPTION_CHAR 'b'
#define QUIT_OPTION_CHAR 'q'

#define MAX_MENU_OPTION_NAME_LENGTH 30
#define INVALID_MENU_OPTION_PROVIDED_MESSAGE "ERROR: you provided an invalid menu option. Please try again.\n"

//Top menu
#define NUMBER_OF_TOPMENU_OPTIONS 2   
#define AUTHENTICATION_OPTION_LOGIN   "Log in"         
#define AUTHENTICATION_OPTION_SIGNUP  "Sign up"  
#define TOPMENU_OPTION_CHARACTERS {FIRST_OPTION_CHAR, SECOND_OPTION_CHAR}
#define TOPMENU_OPTION_NAMES {AUTHENTICATION_OPTION_LOGIN, AUTHENTICATION_OPTION_SIGNUP}



//Second menu
#define NUMBER_OF_SECONDMENU_OPTIONS 3
#define PLAY_GAME_MENU_OPTION_NAME "Play new game"
#define LEADERBOARD_OPTION_NAME "View the leaderboard"
#define QUIT_OPTION_NAME "Log out and quit"
#define SECONDMENU_OPTION_CHARACTERS {FIRST_OPTION_CHAR, SECOND_OPTION_CHAR, QUIT_OPTION_CHAR}
#define SECONDMENU_OPTION_NAMES {PLAY_GAME_MENU_OPTION_NAME, LEADERBOARD_OPTION_NAME, QUIT_OPTION_NAME}




void printMenuIntroduction(const USER* currentUser)
{
	char currentUserName[USER_NAME_LENGTH];
	copyUserName(currentUser, currentUserName);

	printf("Hi %s, welcome to RPS Pro!\n\n", currentUserName);
}

//Top menu functions
void printTopMenuOptions(const char optionCharacters[], const char* optionNames[])
{
	for(int i = 0; i < NUMBER_OF_TOPMENU_OPTIONS; i++)
	{
		printf("%c) %s\n", optionCharacters[i], optionNames[i]);
	}
}

void printSecondMenu(const USER* currentUser, const char optionCharacters[], const char* optionNames[])
{
	printMenuIntroduction(currentUser);
	printSecondMenuOptions(optionCharacters, optionNames);
}

void runTopMenuAction(char input, LEADERBOARD* leaderboard, USER* currentUser) {
	switch (input)
	{
	case FIRST_OPTION_CHAR:
		//call the log in function
		break;
	case SECOND_OPTION_CHAR:
		//call the sign up function
		break;
	default:
		break;
	}
}

//Second menu functions
void printSecondMenuOptions(const char optionCharacters[], const char* optionNames[])    //changed the name   
{
	for (int i = 0; i < NUMBER_OF_SECONDMENU_OPTIONS; i++)
	{
		printf("%c) %s\n", optionCharacters[i], optionNames[i]);
	}
}


void runSecondMenuAction(char input, LEADERBOARD* leaderboard, USER* currentUser) {
	switch(input)
	{
		case FIRST_OPTION_CHAR:
			//game module
			break;
		case SECOND_OPTION_CHAR:
			//leaderboard module
			break;

		default:
			break;
	}
}



void runSecondMenu(LEADERBOARD* leaderboard, USER* currentUser) {

	const char secondMenuOptionCharacters[NUMBER_OF_SECONDMENU_OPTIONS] = SECONDMENU_OPTION_CHARACTERS;
	const char* secondMenuOptionNames[MAX_MENU_OPTION_NAME_LENGTH] = SECONDMENU_OPTION_NAMES;

	// We'll set the current char to be a null terminator, just to
	// be sure the while loop won't end immediately
	char currentChar = '\0';

	// We'll keep looping through the program until the user
	// provides the quit char
	while(currentChar != QUIT_OPTION_CHAR)
	{
		// We'll print the options to the user first
		printSecondMenu(currentUser, secondMenuOptionCharacters, secondMenuOptionNames);

		// We'll get a *valid* character from the user, which is any of the
		// menu options
		currentChar = getAllowedCharFromUser(secondMenuOptionCharacters, secondMenuOptionNames, INVALID_MENU_OPTION_PROVIDED_MESSAGE);

		// We know that we now have a valid char, and so we'll
		// run the menu action the user selected
		runSecondMenuAction(currentChar, leaderboard, currentUser);
	}
}

////////NEEDS WORK /  NOT FINISHED
/*
void runSecondMenu(LEADERBOARD* leaderboard, USER* currentUser) {

	const char topMenuOptionCharacters[NUMBER_OF_TOPMENU_OPTIONS] = TOPMENU_OPTION_CHARACTERS;
	const char* topMenuOptionNames[MAX_MENU_OPTION_NAME_LENGTH] = TOPMENU_OPTION_NAMES;

	// We'll set the current char to be a null terminator, just to
	// be sure the while loop won't end immediately
	char currentChar = '\0';

	// We'll keep looping through the program until the user
	// provides the quit char
	while (currentChar != QUIT_OPTION_CHAR)
	{
		// We'll print the options to the user first
		printTopMenu(currentUser, topMenuOptionCharacters, topMenuOptionNames);

		// We'll get a *valid* character from the user, which is any of the
		// menu options
		currentChar = getAllowedCharFromUser(topMenuOptionCharacters, topMenuOptionNames, INVALID_MENU_OPTION_PROVIDED_MESSAGE);

		// We know that we now have a valid char, and so we'll
		// run the menu action the user selected
		runMenuAction(currentChar, leaderboard, currentUser);
	}
}
*/
