// RPS Pro: authentication.c
// Contains the implementations of the Authentication module's
// functions
//
// Module managed by Saba Berenji

#include "authentication.h"

void copyUserName(const USER* user, char userName[])
{
	strcpy_s(user->userName, sizeof(char) * USER_NAME_LENGTH, userName);
}



//defining the doesPasswordMatch function which checks to see if the entered password matches the user's password from the leaderboard module
bool doesPasswordMatch(const USER* leaderboardUser, const char inputPassword[])
{
    if (strcmp(leaderboardUser->password, inputPassword) != 0) {
        printf("Your password doesn't match the provided username.");
        return false;      //return false if the passwords don't match
    }

    else 
     return true;         //return true if the passwords are identical
}


/*defining the login function which interacts with the findUserInLeaderboard() function from the leaderboard module
and returns true if the user's entered information are correct */

bool login(const LEADERBOARD leaderboard, USER* currentUser) {
    // Ask the user for a username and password
    puts("Please enter your username and password: ");
    char usernameInput[USER_NAME_LENGTH];
    char passwordInput[PASSWORD_LENGTH];
    getStringFromUser(usernameInput, USER_NAME_LENGTH);
    getStringFromUser(passwordInput, PASSWORD_LENGTH);


    // Check whether or not the given username exists in the leaderboard database
    USER* loginUser = getUserFromUsernameInLeaderboard(leaderboard, usernameInput);  //call the getUserFromUsernameInLeaderboard function from the leaderboard module

   
    if (loginUser == NULL) //if the username does not exist in the database
    {
        printf("The username entered does not exits. Please enter a valid username or sign up to create a new account\n");  //display a usable message and return false
        return false;  
    }


    doesPasswordMatch(loginUser, passwordInput);    //if the username exists, check if the password entered matches the password stored for that username

    return true;   //return true if botht the username and password are correct
}

//defining the signUp function which gets username and password from the user and checks to see if the account already exists or not, if not creates a new one
bool signUp(LEADERBOARD leaderboard, USER* newUser)
{
    // Get the the username for a username and password
    puts("Please enter your username and password: ");
    char usernameInput[USER_NAME_LENGTH];
    char passwordInput[PASSWORD_LENGTH];
    getStringFromUser(usernameInput, USER_NAME_LENGTH);
    getStringFromUser(passwordInput, PASSWORD_LENGTH);


    // Check whether the given username exists in the leaderboard database
    USER* currentUser = getUserFromUsernameInLeaderboard(leaderboard, usernameInput);  //call the getUserFromUsernameInLeaderboard function from the leaderboard module

    // Check whether or not the given username exists in the leaderboard database
    if (currentUser != NULL) //if the username exists in the database
    {
        printf("This username already exists, please try a different username or log in to your account");  //display a usable message and return false
        return false;
    }

    else   //if there is no account with the entered username, create a new account for the user by saving the data
    {
        //save the data
        strcpy(newUser->userName, usernameInput);
        strcpy(newUser->password, passwordInput);
    }

    return true;   //finally, return true after saving the user's data
}
