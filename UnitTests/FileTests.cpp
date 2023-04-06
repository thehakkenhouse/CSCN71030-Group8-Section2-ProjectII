#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/file.h"
#include "../Game/authentication.h"
#include <stdlib.h>
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileUnitTests {
	TEST_CLASS(calculateAsciiStringSizeAsBinaryStringTests) {
		public:
		TEST_METHOD(stringIsEmpty)
		{
			// A test to make sure that an empty string returns
			// a length of 1 (for the null terminator)
			char testString[] = "";

			Assert::AreEqual((size_t)1, calculateAsciiStringSizeAsBinaryString(testString));
		}

		TEST_METHOD(twoCharacterString)
		{
			// A test to make sure that a 2-character string
			// returns a length of (2 * 8 + 1) = 17
			char testString[] = "ab";

			Assert::AreEqual((size_t)17, calculateAsciiStringSizeAsBinaryString(testString));
		}

		TEST_METHOD(sixCharacterString)
		{
			// A test to make sure that a 6-character string
			// returns a length of (6 * 8 + 1) = 49
			char testString[] = "abcdef";

			Assert::AreEqual((size_t)49, calculateAsciiStringSizeAsBinaryString(testString));
		}
	};

	TEST_CLASS(calculateBinaryStringSizeAsAsciiStringTests)
	{
		public:
		TEST_METHOD(emptyString)
		{
			// A test to make sure that an empty string
			// returns a length of 1 for the null terminator
			char testString[] = "";

			Assert::AreEqual((size_t)1, calculateBinaryStringSizeAsAsciiString(testString));
		}

		TEST_METHOD(thirtyTwoBitString)
		{
			// A test to make sure that a 32-character string
			// returns a length of (32 / 8 + 1) = 5
			char testString[] = "01100001011100110110010001100110";

			Assert::AreEqual((size_t)5, calculateBinaryStringSizeAsAsciiString(testString));
		}

		TEST_METHOD(fiftySixBitString)
		{
			// A test to make sure that a 56-character string
			// returns a length of (56 / 8 + 1) = 8
			char testString[] = "01100001011100110110010001100110000011111111000000001111";

			Assert::AreEqual((size_t) 8, calculateBinaryStringSizeAsAsciiString(testString));
		}
	};

	TEST_CLASS(convertAsciiStringToBinaryTests)
	{
		public:
		TEST_METHOD(emptyString)
		{
			// A test to make sure that an empty string can be
			// converted successfully
			char testString[] = "";
			char* actual = convertAsciiStringToBinary(testString);

			Assert::AreEqual("", actual);

			free(actual);
		}

		TEST_METHOD(singleCharacterString)
		{
			// A test to make sure that a single character
			// can be converted successfully
			char testString[] = "b";
			char* actual = convertAsciiStringToBinary(testString);

			Assert::AreEqual("01100010", actual);

			free(actual);
		}

		TEST_METHOD(singleWordString)
		{
			// A test to make sure that a single word
			// can be converted successfully
			char testString[] = "dogs";
			char* actual = convertAsciiStringToBinary(testString);

			Assert::AreEqual("01100100011011110110011101110011", actual);

			free(actual);
		}

		TEST_METHOD(longerString)
		{
			// A test to make sure that a longer string can
			// be converted successfully
			char testString[] = "This is a cool string!";
			char* actual = convertAsciiStringToBinary(testString);

			Assert::AreEqual("01010100011010000110100101110011001000000110100101110011001000000110000100100000011000110110111101101111011011000010000001110011011101000111001001101001011011100110011100100001", actual);

			free(actual);
		}
	};

	TEST_CLASS(getCharacterFromBinaryStringIndexTests)
	{
	public:
		TEST_METHOD(emptyStringNullTerminator)
		{
			// A test to make sure that a 00000000
			// string returns a null terminator
			char testString[] = "00000000";

			Assert::AreEqual('\0', getCharacterFromBinaryStringIndex(testString, 0));
		}

		TEST_METHOD(singleCharacter)
		{
			// A test to make sure that the binary equivalent of
			// 'a' returns 'a'
			char testString[] = "01100001";

			Assert::AreEqual('a', getCharacterFromBinaryStringIndex(testString, 0));
		}

		TEST_METHOD(characterAtFirstIndex)
		{
			// A test to make sure that the first offset returns
			// the character 'c'
			char testString[] = "0110111001100011";

			Assert::AreEqual('c', getCharacterFromBinaryStringIndex(testString, 1));
		}

		TEST_METHOD(longStringAtZeroIndex)
		{
			// A test to make sure that a longer string with index
			// 0 returns the character 'f'
			char testString[] = "011001100110001001100011011001000110010101100110";

			Assert::AreEqual('f', getCharacterFromBinaryStringIndex(testString, 0));
		}

		TEST_METHOD(longStringInMiddleIndex)
		{
			// A test to make sure that a long string with an index
			// near the middle returns the character 'T'
			char testString[] = "011110000111100101111010010101000101010001000011011000010110001001100011";

			Assert::AreEqual('T', getCharacterFromBinaryStringIndex(testString, 3));
		}

		TEST_METHOD(longStringAtEndIndex)
		{
			// A test to make sure that a long string with an
			// index at the end returns the character 'c'
			char testString[] = "011110000111100101111010010101000101010001000011011000010110001001100011";

			Assert::AreEqual('c', getCharacterFromBinaryStringIndex(testString, 8));
		}
	};

	TEST_CLASS(convertBinaryStringToAsciiTests)
	{
	public:
		TEST_METHOD(emptyString)
		{
			// A test to make sure that an empty string in
			// binary returns an empty string in ASCII
			char testString[] = "";
			char* actual = convertBinaryStringToAscii(testString);

			Assert::AreEqual("", actual);

			free(actual);
		}

		TEST_METHOD(singleCharacterString)
		{
			// A test to make sure that a single
			// byte of a binary string returns a single character
			// string in ASCII
			char testString[] = "01111000";
			char* actual = convertBinaryStringToAscii(testString);

			Assert::AreEqual("x", actual);

			free(actual);
		}

		TEST_METHOD(longerString)
		{
			// A test to make sure that a longer string in
			// binary converts back to text
			char testString[] = "01010100011010000110100101110011001000000110100101110011001000000110000100100000011101000110010101110011011101000010000001100011011011110110111001110110011001010111001001110100011010010110111001100111001000000110001001100001011000110110101100100000011001100111001001101111011011010010000001100010011010010110111001100001011100100111100100100001";
			char* actual = convertBinaryStringToAscii(testString);

			Assert::AreEqual("This is a test converting back from binary!", actual);

			free(actual);
		}
	};

	TEST_CLASS(cleanStringOfSeparatorsTests)
	{
	public:
		TEST_METHOD(emptyString)
		{
			// A test to make sure that empty strings
			// are not modified
			char actual[] = "";

			cleanStringOfSeparators(actual);

			Assert::AreEqual("", actual);
		}

		TEST_METHOD(singleCharacterNotSeparator)
		{
			// A test to make sure that a single character
			// which is not the separator is not removed
			char actual[] = "t";

			cleanStringOfSeparators(actual);

			Assert::AreEqual("t", actual);
		}

		TEST_METHOD(singleCharacterIsSeparator)
		{
			// A test to make sure that a single character
			// which is a separator is removed
			char actual[] = "|";

			cleanStringOfSeparators(actual);

			Assert::AreEqual(" ", actual);
		}

		TEST_METHOD(threeCharactersMiddleSeparator)
		{
			// A test to make sure that 3 characters with
			// a separator in the middle is removed
			char actual[] = "a|c";

			cleanStringOfSeparators(actual);

			Assert::AreEqual("a c", actual);
		}

		TEST_METHOD(threeCharactersEndSeparator)
		{
			// A test to make sure that 3 characters with
			// a separator at the end is removed
			char actual[] = "ab|";

			cleanStringOfSeparators(actual);

			Assert::AreEqual("ab ", actual);
		}

		TEST_METHOD(multipleSeparators)
		{
			// A test to make sure that all separators in a
			// given string are removed
			char actual[] = "abc|def|hi|";

			cleanStringOfSeparators(actual);

			Assert::AreEqual("abc def hi ", actual);
		}
	};

	TEST_CLASS(convertUserToLeaderboardLineTests)
	{
	public:
		TEST_METHOD(conversionOneTest)
		{
			// A test to make sure that a user with no special
			// characters is encoded into binary successfully
			USER* testUser = createUser("Test User", "coolpass", 12);

			char* actual = convertUserToLeaderboardLine(testUser);

			Assert::AreEqual("010101000110010101110011011101000010000001010101011100110110010101110010011111000110001101101111011011110110110001110000011000010111001101110011011111000011000100110010", actual);

			free(testUser);
			free(actual);
		}

		TEST_METHOD(conversionTwoTest)
		{
			// A test to make sure that a user with some special
			// characters is encoded into binary successfully
			USER* testUser = createUser("Test!@ 123", "awes0m3!", -8);

			char* actual = convertUserToLeaderboardLine(testUser);

			Assert::AreEqual("01010100011001010111001101110100001000010100000000100000001100010011001000110011011111000110000101110111011001010111001100110000011011010011001100100001011111000010110100111000", actual);

			free(testUser);
			free(actual);
		}

		TEST_METHOD(conversionThreeTest)
		{
			// A test to make sure that a user containing the line
			// separator is converted successfully
			USER* testUser = createUser("Te|st", "doesth|swork?", 999);

			char* actual = convertUserToLeaderboardLine(testUser);

			Assert::AreEqual("0101010001100101001000000111001101110100011111000110010001101111011001010111001101110100011010000010000001110011011101110110111101110010011010110011111101111100001110010011100100111001", actual);

			free(testUser);
			free(actual);
		}
	};

	TEST_CLASS(interpretLeaderboardLineTests)
	{
	public:
		TEST_METHOD(emptyStringsTest)
		{
			// A test with empty username and passwords, and a
			// 0 score
			char username[30];
			char password[20];
			int score;
			char leaderboardLine[] = "011111000111110000110000";

			bool actual = interpretLeaderboardLine(leaderboardLine, username, password, &score);

			Assert::IsFalse(actual);
		}

		TEST_METHOD(conversionOneTest)
		{
			// A test with a username of "luna", a password of
			// "cooltest", and a score of -12
			char username[30];
			char password[20];
			int score;
			char leaderboardLine[] = "0110110001110101011011100110000101111100011000110110111101101111011011000111010001100101011100110111010001111100001011010011000100110010";

			interpretLeaderboardLine(leaderboardLine, username, password, &score);

			Assert::AreEqual("luna", username);
			Assert::AreEqual("cooltest", password);
			Assert::AreEqual(-12, score);
		}

		TEST_METHOD(conversionTwoTest)
		{
			// A test with a username of "LongerUsername@", a password
			// of "v3ryn3at!", and a score of 998
			char username[30];
			char password[20];
			int score;
			char leaderboardLine[] = "0100110001101111011011100110011101100101011100100101010101110011011001010111001001101110011000010110110101100101010000000111110001110110001100110111001001111001011011100011001101100001011101000010000101111100001110010011100100111000";

			interpretLeaderboardLine(leaderboardLine, username, password, &score);

			Assert::AreEqual("LongerUsername@", username);
			Assert::AreEqual("v3ryn3at!", password);
			Assert::AreEqual(998, score);
		}
	};
}
