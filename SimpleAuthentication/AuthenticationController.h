#pragma once
#include "UserRepository.h"

class AuthenticationController
{
public:
	AuthenticationController(UserRepository* userRepository)
	{
		_userRepository = userRepository;
	}

	~AuthenticationController()
	{
		if (_userRepository == nullptr)
			return;

		delete _userRepository;
		_userRepository = nullptr;
	}

	virtual bool TryLogin(std::string username, std::string password) = 0;
	virtual void Logout() = 0;
	virtual User* GetActiveUser() = 0;
protected:
	User* _activeUser = nullptr;
	UserRepository* _userRepository;
};
