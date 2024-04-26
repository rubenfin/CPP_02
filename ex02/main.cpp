/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 12:43:35 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/04/24 15:28:45 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed a;
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	Fixed a(5);
	Fixed b(56);
	if (b >= a)
		std::cout << "b is greater than a " << b << " " << a << std::endl;
	if (b != a)
		std::cout << "b is not equal to a " << b << " " << a << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}