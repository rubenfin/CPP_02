/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 11:38:16 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/27 12:14:55 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_num = copy._fixed_num;
}
Fixed &Fixed::operator=(const Fixed &t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		this->_fixed_num = t._fixed_num;
	return (*this);
}

Fixed::Fixed() : _fixed_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_num);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_num = raw;
}