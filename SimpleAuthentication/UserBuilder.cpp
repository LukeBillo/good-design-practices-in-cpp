#include "UserBuilder.h";

UserBuilder::UserBuilder()
{
}

UserBuilder UserBuilder::WithUsername(std::string username)
{
	_username = username;
}

UserBuilder UserBuilder::WithPassword(std::string password)
{
	_password = password;
}

UserBuilder UserBuilder::WithFriendlyName(std::string friendlyName)
{
	_friendlyName = friendlyName;
}

User* UserBuilder::Build()
{
	return new User(_username, _password, _friendlyName);
}
