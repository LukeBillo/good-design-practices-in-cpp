#pragma once
#include "AuthenticationController.h"

class PlainTextPasswordAuthenticationController : public AuthenticationController
{
public:
	PlainTextPasswordAuthenticationController(UserRepository* userRepository);

	virtual bool TryLogin(std::string username, std::string password) override;
	virtual void Logout() override;
	virtual User* GetActiveUser() override;
};

