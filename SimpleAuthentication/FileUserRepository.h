#pragma once
#include <fstream>
#include <sstream>
#include "UserRepository.h"

class FileUserRepository : public UserRepository
{
public:
	FileUserRepository(std::string filePath);
	virtual User* GetUser(std::string username) override;
	virtual void InsertUser(std::string username, std::string password, std::string friendlyName) override;
	virtual void DeleteUser(std::string username) override;
private:
	std::vector<User>* ReadUsersFromFile(std::string filePath);
	User& FileLineToUser(std::string userLine);
};

