/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:06:58 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/19 19:12:22 by olshklya         ###   ########.fr       */
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
	
//operators	
	Fixed&  operator=(const Fixed& other);

	bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
	
	Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
	
	Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);
	
//Destructor
	~Fixed();
	
//Public methods
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
//getter
	int	getRawBits(void) const;
//setter
	void setRawBits(int const raw);

private:
	int	_value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const fixed);