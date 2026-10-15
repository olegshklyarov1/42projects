/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:38:55 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/14 15:38:57 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(const std::string &s)     { _firstName = s; }
void Contact::setLastName(const std::string &s)      { _lastName = s; }
void Contact::setNickname(const std::string &s)      { _nickname = s; }
void Contact::setPhoneNumber(const std::string &s)   { _phoneNumber = s; }
void Contact::setDarkestSecret(const std::string &s) { _darkestSecret = s; }

const std::string &Contact::getFirstName() const     { return _firstName; }
const std::string &Contact::getLastName() const      { return _lastName; }
const std::string &Contact::getNickname() const      { return _nickname; }
const std::string &Contact::getPhoneNumber() const   { return _phoneNumber; }
const std::string &Contact::getDarkestSecret() const { return _darkestSecret; }