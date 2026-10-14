/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:38:31 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/13 16:37:20 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	public:
	
	Zombie(std::string name);
	~Zombie();
	
	void announce(void);
	
	private:
	
	std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif