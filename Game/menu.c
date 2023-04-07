
// RPS Pro: menu.c
// Contains the implementations of the Menu module's
// functions
//
// Module managed by Luna Parker and Saba Berenji

#include "menu.h"
#include "authentication.h"
#include "input.h"
#include "leaderboard.h"
#include "game.h"
#include "file.h"
#include <stdio.h>
#include <stdbool.h>

#define FIRST_OPTION_CHAR 'a'
#define SECOND_OPTION_CHAR 'b'
#define QUIT_OPTION_CHAR 'q'

#define MAX_MENU_OPTION_NAME_LENGTH 50
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

// Leaderboard Save Messages
#define LEADERBOARD_SAVED_SUCCESSFULLY_MESSAGE "\nProgram data saved successfully\n"
#define LEADERBOARD_FAILED_SAVING_MESSAGE "\nERROR: Program data could not be saved. Please make sure that RPS Pro has write access to the directory it's running from.\n"

//this function prints a welcome message with the username
void printMenuIntroduction(const USER* currentUser)
{
	char currentUserName[USER_NAME_LENGTH];
	copyUserName(currentUser, currentUserName);

	printf("Hi %s, welcome to RPS Pro!\n\n", currentUserName);
}

//this function prints the options for the top menu (Log in and Sign up)
void printTopMenuOptions(const char optionCharacters[], const char* optionNames[])
{
	for (int i = 0; i < NUMBER_OF_TOPMENU_OPTIONS; i++)
	{
		printf("%c) %s\n", optionCharacters[i], optionNames[i]);
	}
}


/*this function will print a welcome message with the username
as well as the options for the second menu once the user logs in to the application*/

void printSecondMenu(const USER* currentUser, const char optionCharacters[], const char* optionNames[])
{
	printMenuIntroduction(currentUser);
	printSecondMenuOptions(optionCharacters, optionNames);
}


//this function contains a switch statement that calls the functions associated with each option from the top menu
//this function will return true if the log in or sign up process was successfull

bool runTopMenuAction(char input, LEADERBOARD* leaderboard, USER** currentUser) {

	bool authenticatedSuccessfully = false;   //declaring a flag

	switch (input)
	{
	case FIRST_OPTION_CHAR:
		authenticatedSuccessfully = login(leaderboard, currentUser);
		break;

	case SECOND_OPTION_CHAR:
		authenticatedSuccessfully = signUp(leaderboard, currentUser);
		break;

	default:
		break;
	}

	return  authenticatedSuccessfully;
}



//this function prints the options for the second menu (game, leaderboard, exit)
void printSecondMenuOptions(const char optionCharacters[], const char* optionNames[])   
{
	for (int i = 0; i < NUMBER_OF_SECONDMENU_OPTIONS; i++)
	{
		printf("%c) %s\n", optionCharacters[i], optionNames[i]);
	}
}

//this function contains a switch statement that calls the functions associated with each option from the second menu
void runSecondMenuAction(char input, LEADERBOARD* leaderboard, USER* currentUser, int commandlineargument) {
	switch (input)
	{
	case FIRST_OPTION_CHAR:
		gamePlay(commandlineargument, currentUser);
		break;
	case SECOND_OPTION_CHAR:
		printLeaderboardByHighestScore(leaderboard);
		break;

	default:      
		break;
	}
}




void runTopMenu(int commandlineargument, LEADERBOARD* leaderboard, USER** currentUser)
{
	const char topMenuOptionCharacters[NUMBER_OF_TOPMENU_OPTIONS] = TOPMENU_OPTION_CHARACTERS;
	const char* topMenuOptionNames[MAX_MENU_OPTION_NAME_LENGTH] = TOPMENU_OPTION_NAMES;

	// We'll set the current char to be a null terminator, just to
	// be sure the while loop won't end immediately
	char currentChar = '\0';

	bool authenticatedSuccessfully = false;   //declaring a flag to make sure if the user was successfully able to log in or sign up

	//print the top menu again if the option entered by the user is not valid or if the log in or sign up process is not successfull
	while (currentChar != QUIT_OPTION_CHAR && !authenticatedSuccessfully)
	{
		// We'll print the options to the user first
		printTopMenuOptions(topMenuOptionCharacters, topMenuOptionNames);

		//We'll get a *valid* character from the user, which is any of the menu options
		currentChar = getAllowedCharFromUser(topMenuOptionCharacters, NUMBER_OF_TOPMENU_OPTIONS, INVALID_MENU_OPTION_PROVIDED_MESSAGE);

		// We know that we now have a valid char, and so we'll run the menu action the user selected

		authenticatedSuccessfully = runTopMenuAction(currentChar, leaderboard, currentUser);   //runTopMenuAction will return true if log in or sign up was successful
	}

	// If we've gotten here, the user has either logged in or signed up successfully, so we run the second menu
	runSecondMenu(leaderboard, *currentUser, commandlineargument);   //passing the commandlineargument that we got from the main function
}



void runSecondMenu(LEADERBOARD* leaderboard, USER* currentUser, int commandlineargument) {

	const char secondMenuOptionCharacters[NUMBER_OF_SECONDMENU_OPTIONS] = SECONDMENU_OPTION_CHARACTERS;
	const char* secondMenuOptionNames[MAX_MENU_OPTION_NAME_LENGTH] = SECONDMENU_OPTION_NAMES;

	// We'll set the current char to be a null terminator, just to be sure the while loop won't end immediately
	char currentChar = '\0';

	// We'll keep looping through the program until the user provides the quit char

	while (currentChar != QUIT_OPTION_CHAR)
	{
		// We'll print the options to the user first
		printSecondMenu(currentUser, secondMenuOptionCharacters, secondMenuOptionNames);

		// We'll get a *valid* character from the user, which is any of the menu options
		currentChar = getAllowedCharFromUser(secondMenuOptionCharacters, NUMBER_OF_SECONDMENU_OPTIONS, INVALID_MENU_OPTION_PROVIDED_MESSAGE);

		// We know that we now have a valid char, and so we'll
		// run the menu action the user selected
		runSecondMenuAction(currentChar, leaderboard, currentUser, commandlineargument);
	}
}

/**
 * @brief Prints whether the leaderboard could be saved correctly
 * @param leaderboardSavedSuccessfully Whether the leaderboard was successfully saved to the file
 *
 * @author Luna Parker
 */
void printLeaderboardSaveMessage(bool leaderboardSavedSuccessfully) {
	if (leaderboardSavedSuccessfully) {
		printf(LEADERBOARD_SAVED_SUCCESSFULLY_MESSAGE);
	}
	else {
		printf(LEADERBOARD_FAILED_SAVING_MESSAGE);
	}
}
