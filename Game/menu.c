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

#define PLAY_GAME_MENU_OPTION_CHAR 'a'
#define PLAY_GAME_MENU_OPTION_NAME "Play new game"

#define LEADERBOARD_OPTION_CHAR 'b'
#define LEADERBOARD_OPTION_NAME "View the leaderboard"

#define QUIT_OPTION_CHAR 'q'
#define QUIT_OPTION_NAME "Log out and quit"

#define MENU_OPTION_CHARACTERS {PLAY_GAME_MENU_OPTION_CHAR, LEADERBOARD_OPTION_CHAR, QUIT_OPTION_CHAR}
#define MENU_OPTION_NAMES {PLAY_GAME_MENU_OPTION_NAME, LEADERBOARD_OPTION_NAME, QUIT_OPTION_NAME}
#define NUMBER_OF_MENU_OPTIONS 3
#define MAX_MENU_OPTION_NAME_LENGTH 30

#define INVALID_MENU_OPTION_PROVIDED_MESSAGE "ERROR: you provided an invalid menu option. Please try again.\n"

void printMainMenuIntroduction(const USER* currentUser)
{
	char currentUserName[USER_NAME_LENGTH];
	getUserName(currentUser, currentUserName);

	printf("Hi %s, welcome to RPS Pro!\n\n", currentUserName);
}

void printMainMenuOptions(const char optionCharacters[], const char* optionNames[])
{
	for(int i = 0; i < NUMBER_OF_MENU_OPTIONS; i++)
	{
		printf("%c) %s\n", optionCharacters[i], optionNames[i]);
	}
}

void printMainMenu(const USER* currentUser, const char optionCharacters[], const char* optionNames[])
{
	printMainMenuIntroduction(currentUser);
	printMainMenuOptions(optionCharacters, optionNames);
}

void runMenuAction(char input, LEADERBOARD* leaderboard, USER* currentUser) {
	switch(input)
	{
		case PLAY_GAME_MENU_OPTION_CHAR:
			break;
		case LEADERBOARD_OPTION_CHAR:
			break;
		default:
			// If the user wants to quit, we don't need
			// to do anything here
			break;
	}
}

void runMainMenu(LEADERBOARD* leaderboard, USER* currentUser) {
	const char menuOptionCharacters[NUMBER_OF_MENU_OPTIONS] = MENU_OPTION_CHARACTERS;
	const char* menuOptionNames[MAX_MENU_OPTION_NAME_LENGTH] = MENU_OPTION_NAMES;

	// We'll set the current char to be a null terminator, just to
	// be sure the while loop won't end immediately
	char currentChar = '\0';

	// We'll keep looping through the program until the user
	// provides the quit char
	while(currentChar != QUIT_OPTION_CHAR)
	{
		// We'll print the options to the user first
		printMainMenu(currentUser, menuOptionCharacters, menuOptionNames);

		// We'll get a *valid* character from the user, which is any of the
		// menu options
		currentChar = getAllowedCharFromUser(menuOptionCharacters, NUMBER_OF_MENU_OPTIONS, INVALID_MENU_OPTION_PROVIDED_MESSAGE);

		// We know that we now have a valid char, and so we'll
		// run the menu action the user selected
		runMenuAction(currentChar, leaderboard, currentUser);
	}
}
