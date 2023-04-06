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
}