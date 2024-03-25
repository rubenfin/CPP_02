/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 11:38:16 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/25 12:50:14 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_num = copy.fixed_num;
}
Fixed& Fixed::operator=(const Fixed &t)
{
	if (this != &t)
	{
		this->fixed_num = t.fixed_num;
	}
	return (*this);
}

Fixed::Fixed() : fixed_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}