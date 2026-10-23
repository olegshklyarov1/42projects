/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:26:49 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 14:45:56 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap &operator=(const ClapTrap& other);
	~ClapTrap();
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;

	
private:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
};