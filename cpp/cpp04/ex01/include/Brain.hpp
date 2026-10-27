/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:47:41 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/27 20:15:27 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string> 
#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	
	std::string getIdea(size_t i) const;
	const std::string *getIdeaAddress(size_t i) const;
	void setIdea(size_t i,const std::string &idea);
private:
	std::string _ideas[100];
};