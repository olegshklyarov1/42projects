/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:37:02 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 15:12:58 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap Name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points),
											_attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called." << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points == 0)
		std::cout << this->_name << " is already dead and cannot attack." << std::endl;
	else if (this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attack_damage << " points of damage." << std::endl;
		this->_energy_points -= 1;
	}
	else
		std::cout << "Not enough energy to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
		std::cout << this->_name << " is already dead and cannot be more damaged." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage." << std::endl;
		if (amount > this->_hit_points)
			this->_hit_points = 0;
		else
			this->_hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0)
		std::cout << this->_name << " is already dead and cannot be repaired." << std::endl;
	else if (this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " got " << amount << " points of hit points." << std::endl;
		this->_hit_points += amount;
		this->_energy_points -= 1;  
	}
	else
		std::cout << "Not enough energy points to be repaired." << std::endl;
}

unsigned int ClapTrap::getHitPoints() const
{
	return this->_hit_points;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return this->_energy_points;
}