#define CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/authentication.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



/*NOTE: The logIn and signUp functions from authentication.c cannot be tested automatically as both of them call functions to get user input*/


namespace AuthenticationUnitTests
{

	TEST_CLASS(doesPasswordMatchTests)
	{
	public:
		TEST_METHOD(doesPasswordMatchForLowercaseInputLowercasePsasswordValid) {
			/*A test to make sure that the doesPasswordMatch function will return true
			if the password entered in lowercase matches the user password saved in lowercase */

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "validpassword";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "validpassword");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForUppercaseInputUppercasePasswordValid)
		{
			/**A test to make sure that the doesPasswordMatch function will return true 
			if the password entered in uppercase matches the user password saved in uppercase*/
			
			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "VALIDPASSWORD";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "VALIDPASSWORD");

			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);

		}

		TEST_METHOD(doesPasswordMatchForLowercaseInputLowercasePasswordInvalid)
		{
			/* A test to make sure that the doesPasswordMatch function will return false
			if the password entered in lowercase does NOT match the user password saved in lowercase */

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "invalidpassword";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsFalse(result);

			free(currentUser);

		}

		TEST_METHOD(doesPasswordMatchForUppercaseInputUppercasePasswordInvalid)
		{
			/* A test to make sure that the doesPasswordMatch function will return false 
			if the password entered in uppercase does NOT match the user password saved in uppercase*/

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "INVALIDPASSWORD";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "PASSWORD");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsFalse(result);

			free(currentUser);

		}

		TEST_METHOD(doesPasswordMatchForEmptyInput) {
			/* A test to make sure that the doesPasswordMatch function will return false 
			if the user enters a blank space when asked for password*/

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = " ";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password");

			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsFalse(result);

			free(currentUser);

		}

		TEST_METHOD(doesPasswordMatchForUppercaseInputLowercasePassword)
		{
			/* A test to make sure that the doesPasswordMatch function will returnfalse
			if the password entered is in uppercase but the user password saved is in lowercase*/

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "PASSWORD";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsFalse(result);

			free(currentUser);

		}

		TEST_METHOD(doesPasswordMatchForLowercaseInputUppercasePassword)
		{
			/* A test to make sure that the doesPasswordMatch function will return
			false if the password entered is in lowercase but the user password saved is in uppercase*/

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "password";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "PASSWORD");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsFalse(result);

			free(currentUser);

		}

		TEST_METHOD(doesPasswordMatchForFewUppercaseInputLowercasePassword)
		{
			/* A test to make sure that the doesPasswordMatch function will return false
			if only one character of the password entered does not match the user password saved because of being uppercase */
			
			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "passworD";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsFalse(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForLowercaseInputLowercasePasswordWithNumbers)
		{
			/* A test to make sure that the doesPasswordMatch function will return true
			if the user enters a valid input in lowercase with numbers*/

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "password344";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password344");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForLowercaseInputLowercasePasswordWithSymbols)
		{
			/* A test to make sure that the doesPasswordMatch function will return true
			if the user enters a valid input in lowercase with symbols */
			  
			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "password*%";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password*%");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForLowercaseInputLowercasePasswordWithSymbolsAndNumbers)
		{
			/* A test to make sure that the doesPasswordMatch function will return true
			if the user enters a valid input in lowercase with symbols and numbers */

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "password01*";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "password01*");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForUppercaseInputUppercasePasswordWithNumbers)
		{
			/* A test to make sure that the doesPasswordMatch function will return true 
			if the user enters a valid input in uppercase with numbers*/

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "PASSWORD344";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "PASSWORD344");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForUppercaseInputUppercasePasswordWithSymbols)
		{
			/* A test to make sure that the doesPasswordMatch function will return true
			if the user enters a valid input in uppercase with symbols */

			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "PASSWORD*%";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "PASSWORD*%");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

		TEST_METHOD(doesPasswordMatchForUppercaseInputUppercasePasswordWithSymbolsAndNumbers)
		{
			/* A test to make sure that the doesPasswordMatch function will return true
			if the user enters a valid input in uppercase with symbols and numbers*/
				
			USER* currentUser = (USER*)malloc(sizeof(USER));
			if (currentUser == NULL)
				Assert::Fail(L"This test has failed! Unable to dynamically allocate memory.");

			char passwordInput[PASSWORD_LENGTH] = "PASSWORD01*";
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "PASSWORD01*");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}

	};


	TEST_CLASS(createUserTests)
	{
	public:
		TEST_METHOD(createUserSuccessfullWithValidData) {
		   /* A test to make sure that the createUser function will create the user
		   correctly with the given username, password, and score and then return the struct */


			USER* newUser = createUser("username", "password", 2);

			Assert::AreEqual(newUser->userName, "username");
			Assert::AreEqual(newUser->password, "password");
			Assert::AreEqual(newUser->score, 2);

		}

		TEST_METHOD(createUserSuccessfullWithBlankUsername) {
			/* A test to make sure that the createUser function will create the user
			correctly with a blank username and return it */

			USER* newUser = createUser(" ", "password", 2);

			Assert::AreEqual(newUser->userName, " ");
			Assert::AreEqual(newUser->password, "password");
			Assert::AreEqual(newUser->score, 2);
		}


		TEST_METHOD(createUserSuccessfullWithBlankPassword) {
			/* A test to make sure that the createUser function will create the user
			correctly with a blank password and return it */


			USER* newUser = createUser("username", " ", 2);

			Assert::AreEqual(newUser->userName, "username");
			Assert::AreEqual(newUser->password, " ");
			Assert::AreEqual(newUser->score, 2);
		}

		TEST_METHOD(createUserSuccessfullWithNumbers) {
			/* A test to make sure that the createUser function will create the user
			correctly with username and password that contains numbers and return it */

			USER* newUser = createUser("username12", "password12", 2);

			Assert::AreEqual(newUser->userName, "username12");
			Assert::AreEqual(newUser->password, "password12");
			Assert::AreEqual(newUser->score, 2);
		}



		TEST_METHOD(createUserSuccessfullWithSymbols) {
			/* A test to make sure that the createUser function will create the user
			correctly with username and password that contains symbols and return it */

			USER* newUser = createUser("username*&^", "password&%&", 2);

			Assert::AreEqual(newUser->userName, "username*&^");
			Assert::AreEqual(newUser->password, "password&%&");
			Assert::AreEqual(newUser->score, 2);
		}

	};
}
