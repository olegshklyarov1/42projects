/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:03:41 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 15:41:11 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap Name constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called." << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0)
		std::cout << this->_name << " is already dead and cannot attack." << std::endl;
	else if (this->_energy_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attack_damage << " points of damage." << std::endl;
		this->_energy_points -= 1;
	}
	else
		std::cout << "Not enough energy to attack." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}