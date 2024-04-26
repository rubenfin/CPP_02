/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 12:43:38 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/04/24 12:11:19 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::Fixed() : _fixed_num(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed_num = value << this->_frac_bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixed_num = roundf(value * (1 << this->_frac_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixed_num = copy._fixed_num;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		this->_fixed_num = t._fixed_num;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixed_num) / (1 << this->_frac_bits));
}

int Fixed::toInt(void) const
{
	return (_fixed_num >> _frac_bits);
}

Fixed Fixed::operator+(const Fixed &b) const 
{
	Fixed	result;

	result._fixed_num = this->_fixed_num + b._fixed_num;
	return (result);
}

Fixed Fixed::operator-(const Fixed &b) const 
{
	Fixed	result;

	result._fixed_num = this->_fixed_num - b._fixed_num;
	return (result);
}

Fixed Fixed::operator/(const Fixed &b) const 
{
	Fixed	result;

    result._fixed_num = static_cast<int>((static_cast<long long>(this->_fixed_num) << _frac_bits) / b._fixed_num);
	return (result);
}

Fixed Fixed::operator*(const Fixed &b) const 
{
	Fixed	result;

    result._fixed_num = static_cast<int>((static_cast<long long>(this->_fixed_num) * b._fixed_num) >> _frac_bits);
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
	++_fixed_num;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	++_fixed_num;
	return (copy);
}

Fixed &Fixed::operator--(void)
{
	--_fixed_num;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	--_fixed_num;
	return (copy);
}

bool Fixed::operator==(const Fixed &b) const
{
	if (this->_fixed_num == b._fixed_num)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &b) const
{
	if (this->_fixed_num != b._fixed_num)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &b) const
{
	if (this->_fixed_num < b._fixed_num)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &b) const
{
	if (this->_fixed_num <= b._fixed_num)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed &b) const
{
	if (this->_fixed_num > b._fixed_num)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &b) const
{
	if (this->_fixed_num >= b._fixed_num)
		return (true);
	else
		return (false);
}

void Fixed::setFixed(int num)
{
	this->_fixed_num = num;
}