#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "PlainTextPasswordAuthenticationController.h"
#include "FileUserRepository.h"

constexpr auto MAX_LOGIN_ATTEMPTS = 3;

UserRepository* users = new FileUserRepository("users.txt");
AuthenticationController* authenticator = new PlainTextPasswordAuthenticationController(users);

enum class Command
{
	Invalid,
	InsertUser,
	DeleteUser,
	Logout,
};

const std::unordered_map<std::string, Command> stringToCommandMap = {
		{ "logout", Command::Logout },
};

Command ParseCommand(std::string input)
{
	std::transform(input.begin(), input.end(), input.begin(), [](char c) { return std::tolower(c); });
	const auto iterator = stringToCommandMap.find(input);

	return iterator == stringToCommandMap.end() ? 
		Command::Invalid : 
		iterator->second;
}

void RunAdminConsole(User* adminUser)
{
	std::cout << "Welcome, " << adminUser->friendlyName << "." << std::endl;
	std::cout << "What would you like to do?" << std::endl;

	std::string inputCommand;
	Command command = Command::Invalid;

	while (command != Command::Logout)
	{
		std::cin >> inputCommand;
		command = ParseCommand(inputCommand);

		switch (command)
		{
		case (Command::Logout):
			authenticator->Logout();
			break;
		default:
			std::cout << "That command was invalid, try again." << std::endl;
		}
	}
}

int main()
{
	std::cout << "Welcome to the simple authentication program!" << std::endl;

	bool isAuthorized = false;
	int loginAttempts = 0;

	while (!isAuthorized && loginAttempts < MAX_LOGIN_ATTEMPTS) {
		std::string username;
		std::string password;

		std::cout << "Please enter your username: ";
		std::cin >> username;

		std::cout << "Please enter your password: ";
		std::cin >> password;

		isAuthorized = authenticator->TryLogin(username, password);
		if (!isAuthorized) {
			std::cout << "Username and password incorrect! You have " << (MAX_LOGIN_ATTEMPTS - loginAttempts) << " left." << std::endl;
		}
	}

	if (!isAuthorized) {
		std::cout << "Sorry. You didn't get the password correct. You have been locked out." << std::endl;
		system("pause");
		return 0;
	}

	User* activeUser = authenticator->GetActiveUser();
	if (activeUser == nullptr) {
		std::cout << "Looks like something went wrong." << std::endl;
		system("pause");
		return 0;
	}

	RunAdminConsole(activeUser);
	return 0;
}