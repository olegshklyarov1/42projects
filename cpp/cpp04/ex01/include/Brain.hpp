/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:47:41 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/27 17:16:49 by olshklya         ###   ########.fr       */
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
	
	const std::string getIdea(size_t i) const;
	const std::string *getIdeaAdress(size_t i) const;
	void setIdea(size_t i, std::string idea);
private:
	std::string _ideas[100];
};