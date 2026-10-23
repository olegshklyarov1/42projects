/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:17:25 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:51:51 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}