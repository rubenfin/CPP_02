/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 11:38:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/25 12:50:28 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
  private:
	int fixed_num;
	static const int frac_bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed& operator=(const Fixed &t);
};
