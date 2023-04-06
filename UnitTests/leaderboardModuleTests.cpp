#include "pch.h"
#include "CppUnitTest.h"
#define CRT_SECURE_NO_WARNINGS

extern "C" {
#include "../Game/leaderboard.h"
#include "../Game/authentication.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeaderboardUnitTests {


	TEST_CLASS(IsEmptyTest)
	{
	public:
		TEST_METHOD(IsEmptyTrue)
		{
			// A test to make sure the IsEmpty function will return true
			// if the leaderboard is empty.

			LEADERBOARD* leaderboard = initializeNewLeaderboard();

			bool result = IsEmpty(leaderboard);   // this isn't correct, IsEmpty issue
			Assert::IsTrue(result);

			clearLeaderboardFromMemory(leaderboard);
		}

		TEST_METHOD(IsEmptyFalse)
		{
			// A test to make sure the IsEmpty function will return false
			// if the leaderboard is not empty.

			LEADERBOARD* leaderboard = initializeNewLeaderboard();

			USER* newUser = createUser("Test", "password", 0);

			insertUserIntoLeaderboard(leaderboard, newUser);

			bool result = IsEmpty(leaderboard); // this isn't correct, IsEmpty issue
			Assert::IsFalse(result);

			clearLeaderboardFromMemory(leaderboard);
		}
	};


	TEST_CLASS(searchByUsernameTest)
	{
	public:

		// A test to make sure the searchByUsername function searches through the leaderboard database 
		// and returns the correct user if it finds a user with the same username entered by the player
		// We are looking for a user with username "username2" that exists in the database
		TEST_METHOD(searchByUsernameUserSuccessfull)
		{

			LEADERBOARD* leaderboard = initializeNewLeaderboard();
			USER* user;

			char usernameInput[USER_NAME_LENGTH] = "username2";

			USER* user1 = createUser("username1", "password1", 0);
			insertUserIntoLeaderboard(leaderboard, user1);

			USER* user2 = createUser("username2", "password2", 0);
			insertUserIntoLeaderboard(leaderboard, user2);

			USER* user3 = createUser("username3", "password3", 0);
			insertUserIntoLeaderboard(leaderboard, user3);


			user = searchByUsername(leaderboard, usernameInput);

			Assert::AreEqual(user->userName, "username2");
			Assert::IsNotNull(user);
		}



		TEST_METHOD(searchByUsernameUserUnsuccessfull)
		{
			// A test to make sure the searchByUsername function searchs through the leaderboard database 
			// and returns NULL if it does not find a user with the same username entered by the player
			// We are looking for a user with username "InvalidUsername" that does not exist in the database


			LEADERBOARD* leaderboard = initializeNewLeaderboard();
			USER* user;

			char usernameInput[USER_NAME_LENGTH] = "InvalidUsername";

			USER* user1 = createUser("username1", "password1", 0);
			insertUserIntoLeaderboard(leaderboard, user1);

			USER* user2 = createUser("username2", "password2", 0);
			insertUserIntoLeaderboard(leaderboard, user2);

			USER* user3 = createUser("username3", "password3", 0);
			insertUserIntoLeaderboard(leaderboard, user3);


			user = searchByUsername(leaderboard, usernameInput);
			Assert::IsNull(user);
		}


		TEST_METHOD(searchByUsernameUserUnsuccessfullBlankUsername)
		{
			// A test to make sure the searchByUsername function will search through the leaderboard database 
			// and return NULL if it does NOT find a user with the same username entered by the player
			// We are looking for a user with a blank username which does not exist in the database


			LEADERBOARD* leaderboard = initializeNewLeaderboard();
			USER* user;

			char usernameInput[USER_NAME_LENGTH] = " ";

			USER* user1 = createUser("username1", "password1", 0);
			insertUserIntoLeaderboard(leaderboard, user1);

			USER* user2 = createUser("username2", "password2", 0);
			insertUserIntoLeaderboard(leaderboard, user2);

			USER* user3 = createUser("username3", "password3", 0);
			insertUserIntoLeaderboard(leaderboard, user3);


			user = searchByUsername(leaderboard, usernameInput);

			Assert::IsNull(user);
		}


		TEST_METHOD(searchByUsernameUserSuccessfullBlankUsername)
		{
			// A test to make sure the searchByUsername function will search through the leaderboard database 
			// and return the correct username if it does finds a user with the same username entered by the player
			// We are looking for a user with a blank username which does not exist in the database


			LEADERBOARD* leaderboard = initializeNewLeaderboard();
			USER* user;

			char usernameInput[USER_NAME_LENGTH] = " ";

			USER* user1 = createUser("username1", "password1", 0);
			insertUserIntoLeaderboard(leaderboard, user1);

			USER* user2 = createUser("username2", "password2", 0);
			insertUserIntoLeaderboard(leaderboard, user2);

			USER* user3 = createUser(" ", "password3", 0);
			insertUserIntoLeaderboard(leaderboard, user3);


			user = searchByUsername(leaderboard, usernameInput);
			Assert::AreEqual(user->userName, " ");

			Assert::IsNotNull(user);
		}
	};


}