#pragma once
#include "User.h"
#include <vector>

class UserRepository
{
public:
	virtual User* GetUser(std::string username) = 0;
	virtual void InsertUser(std::string username, std::string password, std::string friendlyName) = 0;
	virtual void DeleteUser(std::string username) = 0;
protected:
	std::vector<User>* _users = nullptr;
};

