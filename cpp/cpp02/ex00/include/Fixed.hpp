/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:06:58 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/19 18:44:27 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed&  operator=(const Fixed& other);
	~Fixed();
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int	_value;
	static const int _fractionalBits = 8;
};