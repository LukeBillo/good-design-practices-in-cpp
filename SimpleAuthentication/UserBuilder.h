#pragma once
#include "User.h"

class UserBuilder
{
public:
	UserBuilder();

	UserBuilder WithUsername(std::string username);
	UserBuilder WithPassword(std::string password);
	UserBuilder WithFriendlyName(std::string friendlyName);

	User* Build();
private:
	std::string _username = "";
	std::string _password = "";
	std::string _friendlyName = "";
};
