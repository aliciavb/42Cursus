#include "Contact.hpp"

void Contact::setFirstName(std::string str)
{
	first_name = str;
}

void Contact::setLastName(std::string str)
{
	last_name = str;
}

void Contact::setNickname(std::string str)
{
	nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	phone_number = str;
}

void Contact::setDarkestSecret(std::string str)
{
	darkest_secret = str;
}

std::string Contact::getFirstName()
{
	return first_name;
}

std::string Contact::getLastName()
{
	return last_name;
}

std::string Contact::getNickname()
{
	return nickname;
}

std::string Contact::getPhoneNumber()
{
	return phone_number;
}

std::string Contact::getDarkestSecret()
{
	return darkest_secret;
}
