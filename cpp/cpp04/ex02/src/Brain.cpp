/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:49:59 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/27 20:19:06 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain default constructor called." << std::endl;	
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->_ideas[i].assign(other._ideas[i]);
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

std::string Brain::getIdea(size_t i) const
{
	if (i < 100)
		return (this->_ideas[i]);
	else
	 	return ("A brain can't have more than 100 ideas.");
}

const std::string *Brain::getIdeaAddress(size_t i) const
{
	if (i < 100)
	{
		const std::string &stringRef = this->_ideas[i];
		return &stringRef;
	}
	else
		return (NULL);
}

void Brain::setIdea(size_t i, const std::string &idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
	 	std::cout << "A brain can't have more than 100 ideas." << std::endl;
}
