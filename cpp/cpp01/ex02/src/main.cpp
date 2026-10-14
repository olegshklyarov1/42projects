/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:30:23 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/13 17:36:01 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* strPTR = &string;
	std::string& strREF = string;
	
	std::cout << "Adresses :" << std::endl;
	std::cout << &string << std::endl;
	std::cout << strPTR << std::endl;
	std::cout << &strREF << std::endl;

	std::cout << "Valeurs :" << std::endl;
	std::cout << string << std::endl;
	std::cout << *strPTR << std::endl;
	std::cout << strREF << std::endl;

	return (0);
}