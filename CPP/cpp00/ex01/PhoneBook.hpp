#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int count;

	std::string formatField(std::string str);

public:
	PhoneBook();
	void addContact();
	void searchContacts();
};

#endif