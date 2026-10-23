/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:36:20 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:11:57 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();
	
	void highFivesGuys(void);
};