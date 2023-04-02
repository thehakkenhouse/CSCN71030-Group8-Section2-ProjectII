
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/authentication.h"
#include "../Game/leaderboard.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



/*NOTE: The logInand signUp functions from authentication.c cannot be tested as both of them get the usernameand password inside them
for validation so this information cannot be passed to these functions*/



namespace AuthenticationUnitTests
{
	
	TEST_CLASS(doesPasswordMatchTests) {
public:
	TEST_METHOD(doesPasswordMatchForValidLowercaseInputLowercasePassword) {
		// A test to make sure that the doesPasswordMatch function will return true if the password entered in lowercase matches the user password saved in lowercase 
		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "validpassword";
		strcpy(currentUser->userName, "validpassword");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsTrue(result);
	}


	TEST_METHOD(doesPasswordMatchForValidCapitalInputCapitalPassword) {
		// A test to make sure that the doesPasswordMatch function will return true if the password entered in uppercase matches the user password saved in uppercase 
		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "VALIDPASSWORD";
		strcpy(currentUser->userName, "VALIDPASSOWRD");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsTrue(result);
	}


	TEST_METHOD(doesPasswordMatchForInvalidPasswordLowercase) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered in lowercase does NOT match the user password saved in lowercase 
		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "invalidpassword";
		strcpy(currentUser->userName, "password");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);
	}


	TEST_METHOD(doesPasswordMatchForInvalidPasswordUppercase) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered in uppercase does NOT match the user password saved in uppercase 

		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "INVALIDPASSWORD";
		strcpy(currentUser->userName, "PASSWORD");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);
	}


	TEST_METHOD(doesPasswordMatchForEmptyInput) {
		// A test to make sure that the doesPasswordMatch function will return false if the user enters a blank space when asked for password
		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = " ";
		strcpy(currentUser->userName, "password");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);
	}

	TEST_METHOD(doesPasswordMatchForCapitalInputLowercasePassword) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered is in uppercase but the user password saved is in lowercase
		
		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "PASSWORD";
		strcpy(currentUser->userName, "password");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);
	}


	TEST_METHOD(doesPasswordMatchForLowercaseInputCapitalPassword) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered is in lowercase but the user password saved is in uppercase

		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "password";
		strcpy(currentUser->userName, "PASSWORD");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);
	}

	TEST_METHOD(doesPasswordMatchForLowercaseInputCapitalPassword) {
		// A test to make sure that the doesPasswordMatch function will return false if only one character of the password enetered does not match the user password saved
		USER* currentUser;
		char passwordInput[PASSWORD_LENGTH] = "passwordS";
		strcpy(currentUser->userName, "password");

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);
	}

};

