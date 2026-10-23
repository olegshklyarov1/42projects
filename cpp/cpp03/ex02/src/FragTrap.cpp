/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:42:29 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 15:57:48 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called." << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;	
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called." << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five, guys!" << std::endl;
}