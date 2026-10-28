/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:16:10 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/28 13:13:07 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal Copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}



std::string Animal::getType() const
{
	return this->type;
}