/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:52:38 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/19 19:16:10 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = input << _fractionalBits;
}

Fixed::Fixed(const float input)
{
	std::cout << "float constructor called" << std::endl;
	this->_value = roundf(input * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed& other) const
{ 
	return this->_value > other._value; 
}
bool Fixed::operator<(const Fixed& other) const 
{ 
	return this->_value < other._value; 
}
bool Fixed::operator>=(const Fixed& other) const
{ 
	return this->_value >= other._value; 
}
bool Fixed::operator<=(const Fixed& other) const 
{ 
	return this->_value <= other._value; 
}
bool Fixed::operator==(const Fixed& other) const 
{ 
	return this->_value == other._value; 
}
bool Fixed::operator!=(const Fixed& other) const 
{ 
	return this->_value != other._value; 
}

Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    if (other._value == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator++(void) {
    this->_value += 1;
    return *this;
}

// Postfix increment (a++): Saves previous state, changes value, returns previous state copy
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_value += 1;
    return temp;
}

// Prefix decrement (--a)
Fixed& Fixed::operator--(void) {
    this->_value -= 1;
    return *this;
}

// Postfix decrement (a--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return this->_value >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const fixed)
{
	out << fixed.toFloat();
	
	return out;
}