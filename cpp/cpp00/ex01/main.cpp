/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:38:38 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/14 15:38:41 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook book;
	std::string cmd;

	while (true)
	{
		std::cout << ">" << std::flush;
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
		{
			if (!book.add())
				break;
		}
		else if (cmd == "SEARCH")
		{
			if(!book.search())
				break;
		}
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}