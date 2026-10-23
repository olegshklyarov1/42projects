/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:55:15 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:51:14 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string& name);
		~HumanB(void);
		
		void attack(void) const;
		void setWeapon(Weapon& weapon);
	
	private:
		std::string _name;
		Weapon* _weapon;
};