#define _CRT_SECURE_NO_WARNINGS 1

// RPS Pro: authentication.c
// Contains the implementations of the Authentication module's
// functions
//
// Module managed by Saba Berenji

#include "authentication.h"
#include "input.h"
#include "file.h"
#include "menu.h"
#include "leaderboard.h"
#include "memory.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Creates a new user pointer based on provided parameters
 * @param username The username of the user
 * @param password The password of the user
 * @param score The initial score of the user
 * @return A USER pointer for the new user
 *
 * @author Luna Parker
 */
USER* createUser(const char username[], const char password[], int score)
{
    USER* newUser = tryToGetAndAssignMemorySafely(sizeof(USER));

    strcpy(newUser->userName, username);
    strcpy(newUser->password, password);
    newUser->score = score;

    return newUser;
}

void copyUserName(const struct user* user, char userName[])
{
	strcpy(userName, user->userName);
}

/*defining the doesPasswordMatch function which checks to see if the entered
password matches the user's password from the leaderboard database*/

bool doesPasswordMatch(const struct user* leaderboardUser, const char inputPassword[])
{
    if (strcmp(leaderboardUser->password, inputPassword) != 0)
        return false;      //return false if the passwords don't match

    else
        return true;         //return true if the passwords are identical
}


/*defining the login function which returns true if the usrname and password entered by the user
matches the ones in the leaderboard database and returns false otherwise */

bool login(const struct leaderboard* leaderboard, struct user** currentUser) {

    // Ask the user for a username and password
    puts("Please enter your username and password in order to log in: ");
    char usernameInput[USER_NAME_LENGTH];
    char passwordInput[PASSWORD_LENGTH];

    //get the username and password from the user
    getStringFromUser(usernameInput, USER_NAME_LENGTH);
    getStringFromUser(passwordInput, PASSWORD_LENGTH);


    // Check whether or not the given username exists in the leaderboard database
    USER* loginUser = searchByUsername(leaderboard, usernameInput);  //call the searchByUsername function from the leaderboard module


    if (loginUser == NULL) //if the username does not exist in the database
    {
        printf("The username entered does not exist. Please enter a valid username or sign up to create a new account.\n");  //display a usable message and return false
        return false;
    }

    /* if the username exists, check if the password entered matches the password stored for that username
    by calling the doesPasswordMatch function */

    if (!doesPasswordMatch(loginUser, passwordInput))     //if the password does not match the username, print a usable message and return false
    {
        printf("Your password doesn't match the provided username. Please enter a valid password.\n");
        return false;
    }

	*currentUser = loginUser;

    return true;   //return true if both the username and password are correct
}


/* defining the signUp function which gets username and password from the user and checks to see if the account already exists or not,
if not creates a new account */

bool signUp(struct leaderboard* leaderboard, const struct user** user)
{
    // Ask the user for a username and password
    puts("Please enter a username and a password in order to sign up: ");
    char usernameInput[USER_NAME_LENGTH];
    char passwordInput[PASSWORD_LENGTH];

    //get the username and password from the user
    getStringFromUser(usernameInput, USER_NAME_LENGTH);
    getStringFromUser(passwordInput, PASSWORD_LENGTH);


    // Check whether the given username exists in the leaderboard database
    USER* possibleUser = searchByUsername(leaderboard, usernameInput);  //call the searchByUsername function from the leaderboard module

    if (possibleUser != NULL) //if the username exists in the database and currentUser is not NULL 
    {
        //display a usable message and return false
        printf("This username already exists, please try a different username or log in to your account\n");
        return false;
    }

    else   //if there is no account with the entered username, create a new account for the user by saving the data
    {
        *user = createUser(usernameInput, passwordInput, 0);
        insertUserIntoLeaderboard(leaderboard, *user);
    }

    return true;   //finally, return true after saving the user's data
}
