

// RPS Pro
// A sophisticated and yet simple take on the classic
// gesture game - now with AI and a leaderboard!
//
// CSCN71030 Section 2, Group 8
// Michelle Novar, Sierra Erb, Saba Berenji, Luna Parker
//
// Please see Git tags and branches for version history

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(int argc, char* argv[])
{

	if (argc < 2)   //displaying an error message if the user does not enter the number of players
	{
		puts("ERROR: you have not entered any commad line argument\n");
		exit(EXIT_FAILURE);   //exit the program after displying the error message
	}

	int commandlineargument = atoi(argv[1]);   //converting the input from string to integer using the atoi() function


	runTopMenu(commandlineargument);



	return 0;
}
