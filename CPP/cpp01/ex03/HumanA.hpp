#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		Weapon &_weapon;
		std::string _name;
	public:
		HumanA(std::string _name, Weapon &_weapon);
		void attack();
};

#endif