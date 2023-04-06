#define CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/leaderboard.h"
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

			LEADERBOARD* leaderboard;
			LEADERBOARD* newLeaderboard;

			LEADERBOARD_NODE* leaderboard = (LEADERBOARD_NODE*)malloc(sizeof(LEADERBOARD_NODE));
			if (leaderboard == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");


			newLeaderboard->firstNode == NULL;


			bool result = IsEmpty(leaderboard);   // this isn't correct, IsEmpty issue
			Assert::IsTrue(result);

			free(leaderboard);
		}

		TEST_METHOD(IsEmptyFalse)
		{
			// A test to make sure the IsEmpty function will return false
			// if the leaderboard is not empty.

			LEADERBOARD* leaderboard;
			LEADERBOARD* newLeaderboard;

			LEADERBOARD_NODE* leaderboard = (LEADERBOARD_NODE*)malloc(sizeof(LEADERBOARD_NODE));
			if (leaderboard == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			newLeaderboard->firstNode != NULL;


			bool result = IsEmpty(leaderboard); // this isn't correct, IsEmpty issue
			Assert::IsFalse(result);

			free(leaderboard);
		}
	};
}