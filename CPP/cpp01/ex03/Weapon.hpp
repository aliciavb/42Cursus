// Implement a Weapon class that has:
// • A private attribute type, which is a string.
// • A getType() member function that returns a constant reference to type.
// • A setType() member function that sets type using the new value passed as a
// parameter.

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string _type);
		~Weapon();

		const std::string getType();
		void setType(std::string type);
};

#endif