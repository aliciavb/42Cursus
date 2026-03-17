#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	count = 0;
}

std::string PhoneBook::formatField(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact()
{
	std::string input;
	int index;

	index = count % 8;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: field can't be empty" << std::endl;
		return;
	}
	contacts[index].setFirstName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: field can't be empty" << std::endl;
		return;
	}
	contacts[index].setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: field can't be empty" << std::endl;
		return;
	}
	contacts[index].setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: field can't be empty" << std::endl;
		return;
	}
	contacts[index].setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: field can't be empty" << std::endl;
		return;
	}
	contacts[index].setDarkestSecret(input);

	count++;
	std::cout << "Contact added!" << std::endl;
}

void PhoneBook::searchContacts()
{
	int max;
	int i;

	if (count > 8)
		max = 8;
	else
		max = count;

	if (max == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname"
			  << "|" << std::endl;

	i = 0;
	while (i < max)
	{
		std::cout << "|" << std::setw(10) << i
				  << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
				  << "|" << std::setw(10) << formatField(contacts[i].getLastName())
				  << "|" << std::setw(10) << formatField(contacts[i].getNickname())
				  << "|" << std::endl;
		i++;
	}

	std::cout << "Enter index: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Error: invalid index" << std::endl;
		return;
	}

	int idx = input[0] - '0';
	if (idx >= max)
	{
		std::cout << "Error: index out of range" << std::endl;
		return;
	}

	std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}