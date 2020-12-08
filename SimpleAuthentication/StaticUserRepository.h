/*

#pragma once
#include "UserRepository.h"

class StaticUserRepository : public UserRepository
{
public:
	StaticUserRepository();

	virtual User* GetUser(std::string username) override;
	virtual void InsertUser(std::string username, std::string password, std::string friendlyName) override;
	virtual void DeleteUser(std::string username) override;
};

*/