/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 15:30:55 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/27 16:36:10 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

float Point::getX(void) const
{
    return (this->_x.toFloat());
}

float Point::getY(void) const
{
    return (this->_y.toFloat());
}

Point::~Point()
{
}