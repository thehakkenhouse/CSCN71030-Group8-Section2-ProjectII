#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/game.h"
#include "../Game/authentication.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameUnitTests {
	TEST_CLASS(randomNumberTests) {
public:
	TEST_METHOD(randomNumber) {
		// A test to make sure that 
		int randomNumber = 1;
		char actual = 'r';
		char gamechoice = gameChoice(randomNumber);

		Assert::AreEqual(actual, gamechoice);
	}

	TEST_METHOD(randomNumberTwo) {
		// A test to make sure that when the random number 2 is generated
		// the character 'r' is returned
		int randomNumber = 2;
		char actual = 'p';
		char gamechoice = gameChoice(randomNumber);

		Assert::AreEqual(actual, gamechoice);
	}

	TEST_METHOD(randomNumberThree) {
		// A test to make sure that when the random number 3 is generated
		// the character 'r' is returned
		int randomNumber = 3;
		char actual = 's';
		char gamechoice = gameChoice(randomNumber);

		Assert::AreEqual(actual, gamechoice);
	}

	};
	
	
	
	TEST_CLASS(gameChoiceTests) {
public:
	TEST_METHOD(randomNumberOne) {
		// A test to make sure that when the random number 1 is generated
		// the character 'r' is returned
		int randomNumber = 1;
		char actual = 'r';
		char gamechoice = gameChoice(randomNumber);

		Assert::AreEqual(actual, gamechoice);
	}

	TEST_METHOD(randomNumberTwo) {
		// A test to make sure that when the random number 2 is generated
		// the character 'p' is returned
		int randomNumber = 2;
		char actual = 'p';
		char gamechoice = gameChoice(randomNumber);

		Assert::AreEqual(actual, gamechoice);
	}

	TEST_METHOD(randomNumberThree) {
		// A test to make sure that when the random number 3 is generated
		// the character 's' is returned
		int randomNumber = 3;
		char actual = 's';
		char gamechoice = gameChoice(randomNumber);

		Assert::AreEqual(actual, gamechoice);
	}

	};

	TEST_CLASS(isRockTests) {
public:
	TEST_METHOD(computerChoiceIsRock) {
		// A test to make sure that when the user enters rock and computer enters rock
		// the game is tied
		char computerChoice = 'r';
		int actual = 2;
		int result = isRock(computerChoice);

		Assert::AreEqual(actual, result);
	}

	TEST_METHOD(computerChoiceIsPaper) {
		// A test to make sure that when the user enters rock and computer enters paper
		// the user loses
		char computerChoice = 'p';
		int actual = 1;
		int result = isRock(computerChoice);

		Assert::AreEqual(actual, result);
	}

	TEST_METHOD(computerChoiceIsScissors) {
		// A test to make sure that when the user enters rock and computer enters scissors
		// the user wins
		char computerChoice = 's';
		int actual = 0;
		int result = isRock(computerChoice);

		Assert::AreEqual(actual, result);
	}

	};


	TEST_CLASS(isPaperTests) {
public:
	TEST_METHOD(computerChoiceIsRock) {
		// A test to make sure that when the user enters paper and computer enters rock
		// the user wins
		char computerChoice = 'r';
		int actual = 0;
		int result = isPaper(computerChoice);

		Assert::AreEqual(actual, result);
	}

	TEST_METHOD(computerChoiceIsPaper) {
		// A test to make sure that when the user enters paper and computer enters paper
		// the game is tied
		char computerChoice = 'p';
		int actual = 2;
		int result = isPaper(computerChoice);

		Assert::AreEqual(actual, result);
	}

	TEST_METHOD(computerChoiceIsScissors) {
		// A test to make sure that when the user enters paper and computer enters scissors
		// the user loses
		char computerChoice = 's';
		int actual = 1;
		int result = isPaper(computerChoice);

		Assert::AreEqual(actual, result);
	}

	};



	TEST_CLASS(isScissorsTests) {
	public:
		TEST_METHOD(computerChoiceIsRock) {
			// A test to make sure that when the user enters scissors and computer enters rock
			// the user loses
			char computerChoice = 'r';
			int actual = 1;
			int result = isScissors(computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(computerChoiceIsPaper) {
			// A test to make sure that when the user enters scissors and computer enters paper
			// the user wins
			char computerChoice = 'p';
			int actual = 0;
			int result = isScissors(computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(computerChoiceIsScissors) {
			// A test to make sure that when the user enters scissors and computer enters scissors
			// the game is tied
			char computerChoice = 's';
			int actual = 2;
			int result = isScissors(computerChoice);

			Assert::AreEqual(actual, result);
		}

	};



	TEST_CLASS(gameResultsTests) {
	public:
		TEST_METHOD(userInputRComputerInputr) {
			// A test to make sure that when the user enters capital R and computer enters r
			// the game is tied
			char computerChoice = 'r';
			char userChoice = 'R';
			int actual = 2;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputPComputerInputr) {
			// A test to make sure that when the user enters capital P and computer enters r
			// the user wins
			char computerChoice = 'r';
			char userChoice = 'P';
			int actual = 0;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputSComputerInputr) {
			// A test to make sure that when the user enters capital S and computer enters r
			// the user loses
			char computerChoice = 'r';
			char userChoice = 'S';
			int actual = 1;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}
		TEST_METHOD(userInputrComputerInputr) {
			// A test to make sure that when the user enters r and computer enters r
			// the game is tied
			char computerChoice = 'r';
			char userChoice = 'r';
			int actual = 2;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputpComputerInputr) {
			// A test to make sure that when the user enters p and computer enters r
			// the user wins
			char computerChoice = 'r';
			char userChoice = 'p';
			int actual = 0;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputsComputerInputr) {
			// A test to make sure that when the user enters s and computer enters r
			// the user loses
			char computerChoice = 'r';
			char userChoice = 's';
			int actual = 1;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}




		TEST_METHOD(userInputRComputerInputp) {
			// A test to make sure that when the user enters capital R and computer enters p
			// the user loses
			char computerChoice = 'p';
			char userChoice = 'R';
			int actual = 1;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputPComputerInputp) {
			// A test to make sure that when the user enters capital P and computer enters p
			// the game is tied
			char computerChoice = 'p';
			char userChoice = 'P';
			int actual = 2;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputSComputerInputp) {
			// A test to make sure that when the user enters capital S and computer enters p
			// the user wins
			char computerChoice = 'p';
			char userChoice = 'S';
			int actual = 0;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}
		TEST_METHOD(userInputrComputerInputp) {
			// A test to make sure that when the user enters r and computer enters p
			// the user loses
			char computerChoice = 'p';
			char userChoice = 'r';
			int actual = 1;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputpComputerInputp) {
			// A test to make sure that when the user enters p and computer enters p
			// the game is tied
			char computerChoice = 'p';
			char userChoice = 'p';
			int actual = 2;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputsComputerInputp) {
			// A test to make sure that when the user enters s and computer enters p
			// the user wins
			char computerChoice = 'p';
			char userChoice = 's';
			int actual = 0;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}




		TEST_METHOD(userInputRComputerInputs) {
			// A test to make sure that when the user enters capital R and computer enters s
			// the user wins
			char computerChoice = 's';
			char userChoice = 'R';
			int actual = 0;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputPComputerInputs) {
			// A test to make sure that when the user enters capital P and computer enters s
			// the user loses
			char computerChoice = 's';
			char userChoice = 'P';
			int actual = 1;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputSComputerInputs) {
			// A test to make sure that when the user enters capital S and computer enters s
			// the game is tied
			char computerChoice = 's';
			char userChoice = 'S';
			int actual = 2;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}
		TEST_METHOD(userInputrComputerInputs) {
			// A test to make sure that when the user enters r and computer enters s
			// the user wins
			char computerChoice = 's';
			char userChoice = 'r';
			int actual = 0;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputpComputerInputs) {
			// A test to make sure that when the user enters p and computer enters s
			// the user loses
			char computerChoice = 's';
			char userChoice = 'p';
			int actual = 1;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}

		TEST_METHOD(userInputsComputerInputs) {
			// A test to make sure that when the user enters s and computer enters s
			// the game is tied
			char computerChoice = 's';
			char userChoice = 's';
			int actual = 2;
			int result = gameResults(userChoice, computerChoice);

			Assert::AreEqual(actual, result);
		}


	};


}