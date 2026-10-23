/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:58:15 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:52:58 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType(void) const 
{
	return(this->_type);
}

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}