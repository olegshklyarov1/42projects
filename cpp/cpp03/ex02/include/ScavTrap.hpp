/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:58:07 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:12:00 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	
	void attack(const std::string& target);
	void guardGate();
};