/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:39:24 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:49:32 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();

		void announce(void);
		void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);