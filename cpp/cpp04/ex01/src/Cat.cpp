/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:31:39 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/27 16:38:38 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Brain allocation failed");
		std::cout << "Exiting because of allocation error" << std::endl;
		exit(1);
	}
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator = (other);
		this->type = other.type;
		delete this->_brain;
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = new Brain();
	}
	return *this;
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "* Meoooow *" << std::endl;
}