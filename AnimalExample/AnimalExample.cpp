// AnimalExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Mammal.h"

int main()
{
	Animal* zebra = new Mammal("zebra", 5, 5);
	zebra->Eat(5);
	zebra->Move(5);
	zebra->Move(6);
}
