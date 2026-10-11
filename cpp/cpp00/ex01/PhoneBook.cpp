#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ostream>
#include <string>

PhoneBook::PhoneBook() : _count(0), _next(0) {}
PhoneBook::~PhoneBook() {}

bool PhoneBook::readField(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt << std::flush;
		
		if (!std::getline(std::cin, out))
			return false;
		if (!out.empty())
			return true;
		std::cout << "Field cannot be empty." << std::endl;
	}
}

bool PhoneBook::add()
{
	std::string first, last, nick, phone, secret;

	if (!readField("First Name: ", first) || 
		!readField("Last Name: ", last) ||
		!readField("Nickname: ", nick) ||
		!readField("Phone number: ", phone) ||
		!readField("Darkest secret: ", secret))
		return false;
	
	Contact &c = _contacts[_next];
	c.setFirstName(first);
	c.setLastName(last);
	c.setNickname(nick);
	c.setPhoneNumber(phone);
	c.setDarkestSecret(secret);

	_next = (_next + 1) % MAX;
	if (_count < MAX)
		_count++;

	return true;
}

std::string PhoneBook::truncate(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void PhoneBook::displayList() const
{
	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "Fist name" << "|"
	<< std::setw(10) << "Last name" << "|"
	<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _count; i++)	
	{
		std::cout << std::setw(10) << i << "|"
		<< std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
		<< std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
		<< std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int i) const
{
    std::cout << "First name: "     << _contacts[i].getFirstName() << std::endl;
    std::cout << "Last name: "      << _contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: "       << _contacts[i].getNickname() << std::endl;
    std::cout << "Phone number: "   << _contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
}

bool PhoneBook::search()
{
	if (_count == 0)
	{
		std::cout << "The awesome PhoneBook is empty" << std::endl;
		return true;
	}
	displayList();

	std::cout << "Index: " << std::flush;
	std::string line;
	if (!std::getline(std::cin, line))
		return false;
	
	if (line.length() != 1 || line[0] < '0' || line[0] > '9' || line[0] - '0' >= _count)
		{
			std::cout << "Invalid Index, try again." << std::endl;
			return true;
		}
	displayContact(line[0] - '0');
	return true;
}

