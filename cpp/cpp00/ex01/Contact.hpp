#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
public:
	Contact();
	~Contact();

	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNumber() const;
	const std::string &getDarkestSecret() const;
	
	void setFirstName(const std::string &s);
	void setLastName(const std::string &s);
	void setNickname(const std::string &s);
	void setPhoneNumber(const std::string &s);
	void setDarkestSecret(const std::string &s);


private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif