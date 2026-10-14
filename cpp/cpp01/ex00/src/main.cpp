/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:52:27 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/13 16:43:58 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int main(void)
{
	Zombie *heapZombie = newZombie("Heap Zombie");
	
	heapZombie->announce();
	randomChump("Stack Zombie");
	delete heapZombie ;
	
	return EXIT_SUCCESS;
}