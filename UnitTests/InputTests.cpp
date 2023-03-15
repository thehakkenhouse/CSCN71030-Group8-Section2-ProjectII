#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/input.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InputUnitTests {
	TEST_CLASS(isStringMinimumLengthTests) {
	public:
		TEST_METHOD(zeroLengthStringWithZeroMinimum) {
			// A test to make sure that an empty string is allowed when
			// 0 is provided as the minimum length
			char emptyString[] = "";

			Assert::IsTrue(isStringMinimumLength(emptyString, 0));
		}

		TEST_METHOD(zeroLengthStringWithPositiveMinimum) {
			// A test to make sure that an empty string isn't allowed
			// when a positive value is provided as the minimum length
			char emptyString[] = "";

			Assert::IsFalse(isStringMinimumLength(emptyString, 1));
		}

		TEST_METHOD(stringWithSpaces) {
			// A test to make sure that a string composed of all spaces
			// is allowed when it meets the minimum length requirement
			char spaceString[] = "   ";

			Assert::IsTrue(isStringMinimumLength(spaceString, 2));
		}

		TEST_METHOD(stringLengthMatches) {
			// A test to make sure that a string which exactly matches
			// the minimum length passes
			char testString[] = "abc";

			Assert::IsTrue(isStringMinimumLength(testString, 3));
		}

		TEST_METHOD(stringLengthOneLess) {
			// A test to make sure that a string whose length is one less
			// than the minimum is not allowed
			char testString[] = "ab c";

			Assert::IsFalse(isStringMinimumLength(testString, 3));
		}

		TEST_METHOD(stringLengthOneMore) {
			// A test to make sure that a string whose length is 1 more
			// than the required is allowed
			char testString[] = "TTWTS";

			Assert::IsTrue(isStringMinimumLength(testString, 4));
		}
	};

	TEST_CLASS(isStringSpecificCharTests) {
	public:
		TEST_METHOD(emptyStringNullTerminatorChar) {
			// A test to make sure that an empty string doesn't
			// match the null terminator (since they're different
			// conditions)
			char emptyString[] = "";

			Assert::IsFalse(isStringSpecificChar(emptyString, '\0'));
		}

		TEST_METHOD(emptyStringWithChar) {
			// A test to make sure that an empty string doesn't
			// match an ASCII character
			char emptyString[] = "";

			Assert::IsFalse(isStringSpecificChar(emptyString, 'a'));
		}

		TEST_METHOD(singleCharacterStringNotMatching) {
			// A test to make sure that a single character string,
			// which doesn't match the search char
			char testString[] = "a";

			Assert::IsFalse(isStringSpecificChar(testString, 'b'));
		}

		TEST_METHOD(singleCharacterMatching) {
			// A test to make sure that a single character string
			// which matches the search char returns true
			char testString[] = "t";

			Assert::IsTrue(isStringSpecificChar(testString, 't'));
		}

		TEST_METHOD(longStringNoCharactersMatching) {
			// A test to make sure that a multi character string
			// with no matching characters returns false
			char testString[] = "ttyl";

			Assert::IsFalse(isStringSpecificChar(testString, 'c'));
		}

		TEST_METHOD(longStringFirstCharacterMatching) {
			// A test to make sure that a multi character string
			// with a matching character at index 0 returns false
			char testString[] = "HBC DEF";

			Assert::IsFalse(isStringSpecificChar(testString, 'H'));
		}

		TEST_METHOD(longStringMatchingCharacterContained) {
			// A test to make sure that a multi character string
			// with a matching character within the string returns
			// false
			char testString[] = "ABCDEF";

			Assert::IsFalse(isStringSpecificChar(testString, 'C'));
		}
	};

	TEST_CLASS(getStringUpToLineSeparatorTests) {
	public:
		TEST_METHOD(emptyString) {
			// A test to make sure that an empty string
			// returns false, indicating that it couldn't
			// find the line separator, and also returns
			// the same empty string
			char emptyString[] = "";
			char actual[10];

			Assert::IsFalse(getStringUpToLineSeparator(emptyString, actual, 10));
			Assert::AreEqual(actual, "");
		}

		TEST_METHOD(oneCharacterStringNotLineSeparator) {
			// A test to make sure that a single character string, not composed
			// of the line separator, returns false and the same original character
			char testString[] = "g";
			char actual[10];

			Assert::IsFalse(getStringUpToLineSeparator(testString, actual, 10));
			Assert::AreEqual(actual, testString);
		}

		TEST_METHOD(oneCharacterStringLineSeparator) {
			// A test to make sure that a single character string which is
			// composed solely of the line separator returns an empty string
			char testString[] = "|";
			char actual[10];

			Assert::IsTrue(getStringUpToLineSeparator(testString, actual, 10));
			Assert::AreEqual(actual, "");
		}

		TEST_METHOD(stringWithNoLineSeparator) {
			// A test to make sure that a string that doesn't have the
			// line separator returns false and the same original string
			char testString[] = "This is a test string";
			char actual[50];

			Assert::IsFalse(getStringUpToLineSeparator(testString, actual, 50));
			Assert::AreEqual(actual, testString);
		}

		TEST_METHOD(stringWithLineSeparatorAtEnd) {
			// A test to make sure that a string with a line separator
			// at the end, returns the same string, but without the
			// line separator
			char testString[] = "A cool input string|";
			char actual[50];

			Assert::IsTrue(getStringUpToLineSeparator(testString, actual, 50));
			Assert::AreEqual(actual, "A cool input string");
		}

		TEST_METHOD(stringWithLineSeparatorInMiddle) {
			// A test to make sure that a string with a line separator
			// in the middle returns up to that line separator,
			// and true to indicate the separator exists
			char testString[] = "Awesome test wh|ich is split in the middle";
			char actual[50];

			Assert::IsTrue(getStringUpToLineSeparator(testString, actual, 50));
			Assert::AreEqual(actual, "Awesome test wh");
		}

		TEST_METHOD(stringWithMultipleLineSeparators) {
			// A test to make sure that a string with multiple line
			// separators returns up to the first line separator
			char testString[] = "This is a string | which has multip|le line separators";
			char actual[50];

			Assert::IsTrue(getStringUpToLineSeparator(testString, actual, 50));
			Assert::AreEqual(actual, "This is a string ");
		}
	};
}