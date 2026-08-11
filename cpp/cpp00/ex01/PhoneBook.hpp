#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
public:
	void add(Contact contact);
	void search (Contact contact);
	void exit();
	int get_size();
	int get_index(Contact contact);

private:
	int size;
	Contact contact_array[8];
};