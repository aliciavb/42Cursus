// Now, create two classes: HumanA and HumanB. They both have a Weapon
// and a name. They also have a member function attack() that displays (without
// the angle brackets):
//
// <name> attacks with their <weapon type>
//
// HumanA and HumanB are almost identical except for these two small details:
// • While HumanA takes the Weapon in its constructor, HumanB does not.
// • HumanB may not always have a weapon, whereas HumanA will always be armed.

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB(std::string _name);
		void attack();
};

#endif