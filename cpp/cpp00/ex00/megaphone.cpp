/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:32:34 by olshklya          #+#    #+#             */
/*   Updated: 2026/08/11 16:56:14 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <cstring>

void capitalize(int ac, char **av)
{	
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; j < (int)strlen(av[i]); j++)
			std::cout << (char)std::toupper(av[i][j]);
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac > 1)
		capitalize(ac, av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}