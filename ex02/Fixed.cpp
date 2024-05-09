/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 12:43:38 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/09 14:24:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::Fixed() : _raw_bits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = value << this->_frac_bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(value * (1 << this->_frac_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_raw_bits = copy._raw_bits;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		this->_raw_bits = t._raw_bits;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_raw_bits) / (1 << this->_frac_bits));
}

int Fixed::toInt(void) const
{
	return (_raw_bits >> _frac_bits);
}

Fixed Fixed::operator+(const Fixed &b) const 
{
	Fixed	result;

	result._raw_bits = this->_raw_bits + b._raw_bits;
	return (result);
}

Fixed Fixed::operator-(const Fixed &b) const 
{
	Fixed	result;

	result._raw_bits = this->_raw_bits - b._raw_bits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &b) const 
{
	Fixed	result;

    result._raw_bits = static_cast<int>((static_cast<long long>(this->_raw_bits) << _frac_bits) / b._raw_bits);
	return (result);
}

Fixed Fixed::operator*(const Fixed &b) const 
{
	Fixed	result;

    result._raw_bits = static_cast<int>((static_cast<long long>(this->_raw_bits) * b._raw_bits) >> _frac_bits);
	return (result);
}

const Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}
Fixed &Fixed::operator++(void)
{
	++_raw_bits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	++_raw_bits;
	return (copy);
}

Fixed &Fixed::operator--(void)
{
	--_raw_bits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	--_raw_bits;
	return (copy);
}

bool Fixed::operator==(const Fixed &b) const
{
	if (this->_raw_bits == b._raw_bits)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &b) const
{
	if (this->_raw_bits != b._raw_bits)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &b) const
{
	if (this->_raw_bits < b._raw_bits)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &b) const
{
	if (this->_raw_bits <= b._raw_bits)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed &b) const
{
	if (this->_raw_bits > b._raw_bits)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &b) const
{
	if (this->_raw_bits >= b._raw_bits)
		return (true);
	else
		return (false);
}

void Fixed::setFixed(int num)
{
	this->_raw_bits = num;
}