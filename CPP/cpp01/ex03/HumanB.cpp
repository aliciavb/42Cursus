#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string newName) : _name(newName)
{
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (_weapon != NULL && _weapon->getType() != "")
	{
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " doesn't have a weapon to attack." << std::endl;
	}
}