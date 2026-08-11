#include <iostream>

class Contact
{
public:
	std::string get_firstname();
	std::string get_lastname();
	std::string get_nickname();


private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};