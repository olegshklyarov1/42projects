#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	bool add();
	bool search();

private:
	static const int MAX = 8;
	int _count;
	Contact _contacts[MAX];
	int _next;

	static bool readField(const std::string &prompt, std::string &out);
	static std::string truncate(const std::string &s);
	void displayList() const;
	void displayContact(int i) const;
};

# endif