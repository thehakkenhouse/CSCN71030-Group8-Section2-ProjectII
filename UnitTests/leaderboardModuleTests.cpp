#define CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/leaderboard.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace LeaderboardUnitTests
{

	TEST_CLASS(IsEmpty)
	{
	public:
		TEST_METHOD(IsEmptyTrue)
		{
			// A test to make sure the IsEmpty function will return true
			// if the leaderboard is empty.

			LEADERBOARD* leaderboard;

			leaderboard == NULL;


			bool result = IsEmpty(leaderboard);
			Assert::IsTrue(result);

		}

		TEST_METHOD(IsEmptyFalse)
		{
			// A test to make sure the IsEmpty function will return false
			// if the leaderboard is not empty.

			LEADERBOARD* leaderboard;

			leaderboard != NULL;


			bool result = IsEmpty(leaderboard);
			Assert::IsFalse(result);

		}


	}