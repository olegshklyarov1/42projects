/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:26:20 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/15 14:52:07 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Harl
{
public:

	Harl();
	~Harl();
	
	void complain(std::string level);
	
private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};