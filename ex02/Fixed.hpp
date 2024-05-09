/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 12:43:40 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/09 14:24:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int _raw_bits;
	static const int _frac_bits = 8;

  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &t);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	void setFixed(int num);
	bool operator==(const Fixed &b) const;
	bool operator!=(const Fixed &b) const;
	bool operator<(const Fixed &b) const;
	bool operator<=(const Fixed &b) const;
	bool operator>(const Fixed &b) const;
	bool operator>=(const Fixed &b) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	Fixed operator+(const Fixed &b) const;
	Fixed operator-(const Fixed &b) const;
	Fixed operator/(const Fixed &b) const;
	Fixed operator*(const Fixed &b) const;
	static const Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
