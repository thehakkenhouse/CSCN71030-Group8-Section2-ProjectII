// RPS Pro: authentication.c
// Contains the implementations of the Authentication module's
// functions
//
// Module managed by Saba Berenji

#include "authentication.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "file.h"
#include "menu.h"
#include "leaderboard.h"

void copyUserName(const USER* user, char userName[])
{
	strcpy_s(userName, sizeof(char) * USER_NAME_LENGTH, user->userName);
}

void getUsername(USER* user)  /*getUsername function gets the input from the user and copies it to the usr struct created using
					the two getStringFromUser and getUserName function calls*/
	  //returns the struct to later get the user password
{


	char userInputUsername[USER_NAME_LENGTH];
	getStringFromUser(userInputUsername, USER_NAME_LENGTH);
	copyUserName(user, userInputUsername);

}

void copyPassword(const USER* user, char password[])
{
	strcpy_s(password, sizeof(char) * PASSWORD_LENGTH, user->password);
}

void getPassword(USER* user)   //gets the password from the user and copies it to the user struct
{
	char userInputPasswrod[PASSWORD_LENGTH];
	getStringFromUser(userInputPasswrod, PASSWORD_LENGTH);
	copyPassword(user, userInputPasswrod);
}


//bool isUsernameInDataBase(USER* user, FILE* ASCII_file)   //connect to ASCII file module
//{
//	bool flag = false; 
//
//	char line[USER_NAME_LENGTH];
//	while (fgets(line, sizeof(line), ASCII_file)) {   //this will work if each line has one word only
//		if (strcmp(line, user->userName) == 0) {
//			flag = true;
//		}
//	}
//	
//	return flag;
//}


bool isUsernameInDataBase(USER* user, FILE* ASCII_file, char filename[])   //connect to ASCII file module
{
	ASCII_file = fopen(filename, "r");

	if (ASCII_file == NULL) {
		// file opening failed
		puts("There was an error in opening the database file");
		exit(EXIT_FAILURE);
	}

	char word[USER_NAME_LENGTH];
	word[USER_NAME_LENGTH - 1] = '\0';

	while (fscanf(ASCII_file, "%s", word) != EOF)   //fscanf reads formatted input from a file
	{
		if (strcmp(word, user->userName) == 0)   
		{
			return true;
		}
	}

	if (fclose(ASCII_file) != 0) {
		// file closing failed
		puts("There was an error in closing the database file");
		exit(EXIT_FAILURE);
	}

	return false;
}


bool isPasswordInDataBase(USER* user, FILE* Binary_file, char filename[])   //connect to ASCII file module
{
	Binary_file = fopen(filename, "rb");  //open the binary file in the reading mode

	if (Binary_file == NULL) {
		// file opening failed
		puts("There was an error in opening the database file");
		exit(EXIT_FAILURE);
	}

	USER temp_user;
	while (fread(&temp_user, sizeof(USER), 1, Binary_file) == 1) {
		if (strcmp(temp_user.userName, user->userName) == 0) {
			return true;
		}
	}

	if (fclose(Binary_file) != 0) {
		// file closing failed
		puts("There was an error in closing the database file");
		exit(EXIT_FAILURE);
	}

	return false;
}



void logIn(FILE* ASCII_file, FILE* Binary_file, char filename[])
{
	USER* user = malloc(sizeof(USER));  //dynamically allocating memory for the struct

	if (user == NULL)  //exit if the return value of malloc is NULL
	{
		puts("ERROR, there was a problem in allocating memory!!");
		exit(EXIT_FAILURE);
	}

	getUsername(user);
	getPassword(user);


	if (isUsernameInDataBase(user, ASCII_file, filename) && isPasswordInDataBase (user, Binary_file, filename))
	{

		//then log in and display the second menu
		//runSecondMenu(LEADERBOARD* leaderboard, user) ///????
	}


	else
	{
		puts("There seems be no account with the entered info, please sign up or enter the correct username and password");
		//exit and go back to top menu
		//runTopMenu(LEADERBOARD* leaderboard, user) ///????
	}
	

}

void signUp(FILE* ASCII_file, FILE* Binary_file, char filename[])
{
	USER* user = malloc(sizeof(USER));  //dynamically allocating memory for the struct

	if (user == NULL)  //exit if the return value of malloc is NULL
	{
		puts("ERROR, there was a problem in allocating memory!!");
		exit(EXIT_FAILURE);
	}

	getUsername(user);
	getPassword(user);



	if (isUsernameInDataBase(user, ASCII_file, filename) && isPasswordInDataBase(user, Binary_file, filename))
	{
		puts("There is already an account with these credentials, please log in using your username and password");
		//exit and go back to top menu
		//runTopMenu(LEADERBOARD* leaderboard, user) ///????

	}
		
	else
	{
		//then log in and display the second menu
	    //runSecondMenu(LEADERBOARD* leaderboard, user) ///????

	}
	
}
