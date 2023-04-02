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
			//strcpy_s(currentUser->password, "validpassword");
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
			//strcpy_s(currentUser->password, "VALIDPASSWORD");
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
			//strcpy_s(currentUser->password, "password");
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
			//strcpy_s(currentUser->password, "PASSWORD");
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
			//strcpy_s(currentUser->password, "password");
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
			//strcpy_s(currentUser->password, "password");
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
			//strcpy_s(currentUser->password, "PASSWORD");
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
			//	strcpy_s(currentUser->password, "password");
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
			//	strcpy_s(currentUser->password, "password");
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
			//	strcpy_s(currentUser->password, "password");
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
			//	strcpy_s(currentUser->password, "password");
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
			//	strcpy_s(currentUser->password, "password");
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
			//	strcpy_s(currentUser->password, "password");
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
			//	strcpy_s(currentUser->password, "password");
			strcpy_s(currentUser->password, sizeof(char) * PASSWORD_LENGTH, "PASSWORD01*");


			bool result = doesPasswordMatch(currentUser, passwordInput);
			Assert::IsTrue(result);

			free(currentUser);
		}
	};
}




