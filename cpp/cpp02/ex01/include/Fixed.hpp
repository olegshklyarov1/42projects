/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:06:58 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/19 18:58:21 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
public:

//constructors
	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed& other);
	
//operator overload	
	Fixed&  operator=(const Fixed& other);
	
//Destructor
	~Fixed();
	
//Public methods
	float toFloat(void) const;
	int toInt(void) const;
//getter
	int	getRawBits(void) const;
//setter
	void setRawBits(int const raw);

private:
	int	_value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const fixed);