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

			Assert::IsFalse(isStringMinimumLength(testString, 5));
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

	TEST_CLASS(getStringUpToCharTests) {
	public:
		TEST_METHOD(emptyString) {
			// A test to make sure that an empty string
			// returns false, indicating that it couldn't
			// find the line separator, and also returns
			// the same empty string
			char emptyString[] = "";
			char actual[10];

			Assert::IsFalse(getStringUpToChar('|', emptyString, actual, 10));
			Assert::AreEqual("", actual);
		}

		TEST_METHOD(oneCharacterStringNotLineSeparator) {
			// A test to make sure that a single character string, not composed
			// of the line separator, returns false and the same original character
			char testString[] = "g";
			char actual[10];

			Assert::IsFalse(getStringUpToChar('|', testString, actual, 10));
			Assert::AreEqual("g", actual);
		}

		TEST_METHOD(oneCharacterStringLineSeparator) {
			// A test to make sure that a single character string which is
			// composed solely of the line separator returns an empty string
			char testString[] = "|";
			char actual[10];

			Assert::IsTrue(getStringUpToChar('|', testString, actual, 10));
			Assert::AreEqual("", actual);
		}

		TEST_METHOD(stringWithNoLineSeparator) {
			// A test to make sure that a string that doesn't have the
			// line separator returns false and the same original string
			char testString[] = "This is a test string";
			char actual[50];

			Assert::IsFalse(getStringUpToChar('|', testString, actual, 50));
			Assert::AreEqual("This is a test string", actual);
		}

		TEST_METHOD(stringWithLineSeparatorAtEnd) {
			// A test to make sure that a string with a line separator
			// at the end, returns the same string, but without the
			// line separator
			char testString[] = "A cool input string|";
			char actual[50];

			Assert::IsTrue(getStringUpToChar('|', testString, actual, 50));
			Assert::AreEqual("A cool input string", actual);
		}

		TEST_METHOD(stringWithLineSeparatorInMiddle) {
			// A test to make sure that a string with a line separator
			// in the middle returns up to that line separator,
			// and true to indicate the separator exists
			char testString[] = "Awesome test wh|ich is split in the middle";
			char actual[50];

			Assert::IsTrue(getStringUpToChar('|', testString, actual, 50));
			Assert::AreEqual("Awesome test wh", actual);
		}

		TEST_METHOD(stringWithMultipleLineSeparators) {
			// A test to make sure that a string with multiple line
			// separators returns up to the first line separator
			char testString[] = "This is a string | which has multip|le line separators";
			char actual[50];

			Assert::IsTrue(getStringUpToChar('|', testString, actual, 50));
			Assert::AreEqual("This is a string ", actual);
		}
	};

	TEST_CLASS(removeNewLineFromStringTests)
	{
	public:
		TEST_METHOD(emptyString)
		{
			// A test to make sure that an empty string isn't
			// modified by this function
			char actual[] = "";

			endStringAtNewLine(actual);

			Assert::AreEqual("", actual);
		}

		TEST_METHOD(stringWithSpaces)
		{
			// A test to make sure that a string only composed
			// of spaces isn't modified by the function
			char actual[] = "   ";

			endStringAtNewLine(actual);

			Assert::AreEqual("   ", actual);
		}

		TEST_METHOD(alphanumericString)
		{
			// A test to make sure that a string only composed
			// of letters and numbers isn't modified by the function
			char actual[] = "abcDEF123";

			endStringAtNewLine(actual);

			Assert::AreEqual("abcDEF123", actual);
		}

		TEST_METHOD(newlineOnlyString)
		{
			// A test to make sure a newline only string
			// returns an empty string
			char actual[] = "\n\n\n";

			endStringAtNewLine(actual);

			Assert::AreEqual("", actual);
		}

		TEST_METHOD(newlineAtEndOfString)
		{
			// A test to make sure that a newline at the end of the string
			// gets removed
			char actual[] = "this is a test\n";

			endStringAtNewLine(actual);

			Assert::AreEqual("this is a test", actual);
		}

		TEST_METHOD(newlineInMiddleOfString)
		{
			// A test to make sure that a newline in the middle
			// of a string gets removed
			char actual[] = "this\n is a test";

			endStringAtNewLine(actual);

			Assert::AreEqual("this", actual);
		}

		TEST_METHOD(multipleNewlinesInString)
		{
			// A test to make sure that multiple newlines in a string
			// get removed
			char actual[] = "a longer \nstring with \na test";

			endStringAtNewLine(actual);

			Assert::AreEqual("a longer ", actual);
		}
	};

	TEST_CLASS(isCharInArrayTests)
	{
		TEST_METHOD(emptyCharArray)
		{
			// A test for when the allowed character array
			// is empty
			char allowedChars[1];

			Assert::IsFalse(isCharInArray('g', allowedChars, 0));
		}

		TEST_METHOD(singleCharArrayMatches)
		{
			// A test for a single character array, where
			// the character matches
			char allowedChars[1] = { 'f' };

			Assert::IsTrue(isCharInArray('f', allowedChars, 1));
		}

		TEST_METHOD(singleCharArrayNoMatch)
		{
			// A test for a single character array, where
			// the character doesn't match
			char allowedChars[1] = { 'l' };

			Assert::IsFalse(isCharInArray('k', allowedChars, 1));
		}

		TEST_METHOD(multiCharArrayFrontMatches)
		{
			// A test for a multi char array, where the
			// the search char is at the front of the array
			char allowedChars[3] = { 'l', 'm', 'n' };

			Assert::IsTrue(isCharInArray('l', allowedChars, 3));
		}

		TEST_METHOD(multiCharArrayMiddleMatches)
		{
			// A test for a multi char array, where the
			// the search char is in the middle of the array
			char allowedChars[4] = { '1', 'a', 'c', 'b'};

			Assert::IsTrue(isCharInArray('c', allowedChars, 4));
		}

		TEST_METHOD(multiCharArrayEndMatches)
		{
			// A test for a multi char array, where the
			// the search char is at the end of the array
			char allowedChars[4] = { '0', '.', '2', 'g' };

			Assert::IsTrue(isCharInArray('g', allowedChars, 4));
		}

		TEST_METHOD(multiCharArrayNoMatch)
		{
			// A test for a multi char array, where the
			// the search char is at the front of the array
			char allowedChars[3] = { 'd', 'f', '8' };

			Assert::IsFalse(isCharInArray('k', allowedChars, 3));
		}
	};
}
