#pragma once
#include <string>

struct User {
	std::string username;
	std::string password;
	std::string friendlyName;

	User(std::string username, std::string password, std::string friendlyName) {
		this->username = username;
		this->password = password;
		this->friendlyName = friendlyName;
	}
};