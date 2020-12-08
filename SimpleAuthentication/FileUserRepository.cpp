#include "FileUserRepository.h"

FileUserRepository::FileUserRepository(std::string filePath)
{
	_users = ReadUsersFromFile(filePath);
}

User* FileUserRepository::GetUser(std::string username)
{
	for (size_t i = 0; i < _users->size(); ++i) {
		User& user = _users->at(i);

		if (user.username == username) {
			return &user;
		}
	}

	return nullptr;
}

void FileUserRepository::InsertUser(std::string username, std::string password, std::string friendlyName)
{
}

void FileUserRepository::DeleteUser(std::string username)
{
}

std::vector<User>* FileUserRepository::ReadUsersFromFile(std::string filePath)
{
	std::ifstream usersFile(filePath);
	std::string userLine;

	std::vector<User>* users = new std::vector<User>();

	while (std::getline(usersFile, userLine)) {
		User user = FileLineToUser(userLine);
		users->push_back(user);
	}

	return users;
}

User& FileUserRepository::FileLineToUser(std::string userLine)
{
	std::stringstream stream(userLine);

	std::string username;
	std::getline(stream, username, ',');

	std::string friendlyName;
	std::getline(stream, friendlyName, ',');

	std::string password;
	std::getline(stream, password, ',');

	User* user = new User(username, password, friendlyName);
	return *user;
}
