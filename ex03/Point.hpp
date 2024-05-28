/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 15:31:05 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/05/27 16:36:06 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

// MAKE IN ORTHODOX CANONICAL FORM

class Point
{
private:
    const Fixed _x;
    const Fixed _y;
public:
    Point(void);
    Point(const float x, const float y);
    ~Point();
    float getX(void) const;
    float getY(void) const;
};


