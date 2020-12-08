#pragma once
#include <string>
#include <iostream>

class Animal
{
public:
	virtual void Move(int steps) = 0;
	virtual void Eat(int amount) = 0;

	std::string name;
	int hunger;
protected:
	int _speed;
	int _stepsMoved = 0;
};