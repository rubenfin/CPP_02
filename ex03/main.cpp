/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 16:36:34 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/28 15:09:48 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
    Point a(0,0);
    Point b(20,0);
    Point c(10,30);
    Point point(9,25);

	if (bsp(a, b, c, point))
		std::cout << "Inside";
	else
		std::cout << "Not Inside";

	return (0);
}