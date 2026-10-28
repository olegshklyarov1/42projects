/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:26:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/27 20:29:46 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();
	
	virtual void makeSound() const;
	
	Brain *getBrain() const;

	std::string getIdea(size_t i) const;
	void setIdea(size_t i, const std::string &idea);

private:
	Brain* _brain;
};