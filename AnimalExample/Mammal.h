#pragma once
#include "Animal.h"

class Mammal : public Animal
{
public:
	Mammal(std::string name, int hunger, int speed);

	void Move(int steps) override;
	void Eat(int amount) override;
};