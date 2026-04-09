

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string newName, Weapon &newWeapon)
	: _weapon(newWeapon), _name(newName)
{
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
