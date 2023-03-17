// RPS Pro: authentication.c
// Contains the implementations of the Authentication module's
// functions
//
// Module managed by Saba Berenji

#include "authentication.h"
#include <string.h>

void getUserName(const USER* user, char userName[])
{
	strcpy_s(userName, sizeof(char) * USER_NAME_LENGTH, user->userName);
}
