/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:36:57 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/15 14:51:56 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc == 1)	
	{
		std::cout << "Everything Harl can say: " << std::endl;
		std::cout << std::endl;
		harl.complain("DEBUG");
		std::cout << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		harl.complain("Something else.");
		std::cout << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
			harl.complain(argv[i]);
	}
	return 0;
}