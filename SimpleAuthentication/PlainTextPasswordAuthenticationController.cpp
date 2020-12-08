#include "PlainTextPasswordAuthenticationController.h"

PlainTextPasswordAuthenticationController::PlainTextPasswordAuthenticationController(UserRepository* userRepository)
	: AuthenticationController(userRepository) {}

bool PlainTextPasswordAuthenticationController::TryLogin(std::string username, std::string password)
{
	if (_activeUser != nullptr) {
		throw std::exception("Can't login when there's already an active user!");
	}

	User* user = _userRepository->GetUser(username);

	if (user == nullptr) {
		return false;
	}

	if (user->password != password) {
		return false;
	}

	_activeUser = user;
	return true;
}

void PlainTextPasswordAuthenticationController::Logout()
{
	_activeUser = nullptr;
}

User* PlainTextPasswordAuthenticationController::GetActiveUser()
{
	return _activeUser;
}
