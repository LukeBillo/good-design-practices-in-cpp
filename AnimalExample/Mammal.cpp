#include "Mammal.h"

Mammal::Mammal(std::string name, int hunger, int speed)
{
	this->name = name;
	this->hunger = hunger;
	_speed = speed;
}

void Mammal::Move(int steps)
{
	bool movedTooFar = _speed < steps;

	if (movedTooFar) {
		_stepsMoved += _speed;
		std::cout << name << " got tired and only moved " << _speed << " and didn't manage to move " << steps << " steps!" << std::endl;
	}
	else {
		_stepsMoved += steps;
		std::cout << name << " moved " << steps << " steps!" << std::endl;
	}

	std::cout << name << " has moved a total of " << steps << " steps." << std::endl;
}

void Mammal::Eat(int amount)
{
	std::cout << name << " is eating!" << std::endl;
	hunger += amount;

	if (hunger > 10) {
		std::cout << name << " is very full." << std::endl;
		hunger = 10;
	}
}

