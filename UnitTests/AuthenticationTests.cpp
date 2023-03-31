#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Game/authentication.h"
#include "../Game/leaderboard.h"

#include <stdlib.h>
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
		USER* currentUser = createUser("Test", "validpassword", 0);
		char passwordInput[PASSWORD_LENGTH] = "validpassword";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsTrue(result);

		free(currentUser);
	}


	TEST_METHOD(doesPasswordMatchForValidCapitalInputCapitalPassword) {
		// A test to make sure that the doesPasswordMatch function will return true if the password entered in uppercase matches the user password saved in uppercase 
		USER* currentUser = createUser("Test", "VALIDPASSWORD", 0);
		char passwordInput[PASSWORD_LENGTH] = "VALIDPASSWORD";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsTrue(result);

		free(currentUser);
	}


	TEST_METHOD(doesPasswordMatchForInvalidPasswordLowercase) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered in lowercase does NOT match the user password saved in lowercase 
		USER* currentUser = createUser("Test", "password", 0);
		char passwordInput[PASSWORD_LENGTH] = "invalidpassword";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);

		free(currentUser);
	}


	TEST_METHOD(doesPasswordMatchForInvalidPasswordUppercase) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered in uppercase does NOT match the user password saved in uppercase 

		USER* currentUser = createUser("Test", "PASSWORD", 0);
		char passwordInput[PASSWORD_LENGTH] = "INVALIDPASSWORD";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);

		free(currentUser);
	}


	TEST_METHOD(doesPasswordMatchForEmptyInput) {
		// A test to make sure that the doesPasswordMatch function will return false if the user enters a blank space when asked for password
		USER* currentUser = createUser("Test", "password", 0);
		char passwordInput[PASSWORD_LENGTH] = " ";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);

		free(currentUser);
	}

	TEST_METHOD(doesPasswordMatchForCapitalInputLowercasePassword) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered is in uppercase but the user password saved is in lowercase
		USER* currentUser = createUser("Test", "password", 0);
		char passwordInput[PASSWORD_LENGTH] = "PASSWORD";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);

		free(currentUser);
	}

	TEST_METHOD(doesPasswordMatchForLowercaseInputCapitalPassword) {
		// A test to make sure that the doesPasswordMatch function will return false if the password entered is in lowercase but the user password saved is in uppercase
		USER* currentUser = createUser("Test", "PASSWORD", 0);
		char passwordInput[PASSWORD_LENGTH] = "password";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);

		free(currentUser);
	}

	TEST_METHOD(doesPasswordMatchForLowercaseInputCapitalPasswordSecondTest) {
		// A test to make sure that the doesPasswordMatch function will return false if only one character of the password enetered does not match the user password saved
		USER* currentUser = createUser("Test", "password", 0);
		char passwordInput[PASSWORD_LENGTH] = "passwordS";

		bool result = doesPasswordMatch(currentUser, passwordInput);
		Assert::IsFalse(result);

		free(currentUser);
	}

	};
}