#include "Point.hpp"

int	myAbs(int value)
{
	return ((value < 0) ? -value : value);
}

float	area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (myAbs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool	isOnLineSegment(int x1, int y1, int x2, int y2, int px, int py)
{
	int	dxc;
	int	dyc;
	int	dxl;
	int	dyl;
	int	cross;

	dxc = px - x1;
	dyc = py - y1;
	dxl = x2 - x1;
	dyl = y2 - y1;
	cross = dxc * dyl - dyc * dxl;
	if (cross != 0)
		return (false);
        
	if (myAbs(dxl) >= myAbs(dyl))
		return (dxl > 0 ? x1 <= px && px <= x2 : x2 <= px && px <= x1);
	else
		return (dyl > 0 ? y1 <= py && py <= y2 : y2 <= py && py <= y1);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int ax = a.getX();
	int ay = a.getY();
	int bx = b.getX();
	int by = b.getY();
	int cx = c.getX();
	int cy = c.getY();
	int px = point.getX();
	int py = point.getY();

	float A = area(ax, ay, bx, by, cx, cy);

	float A1 = area(px, py, bx, by, cx, cy);
	float A2 = area(ax, ay, px, py, cx, cy);
	float A3 = area(ax, ay, bx, by, px, py);

	bool isInTriangle = (A == A1 + A2 + A3);

	bool isOnEdge = isOnLineSegment(ax, ay, bx, by, px, py)
		|| isOnLineSegment(bx, by, cx, cy, px, py) || isOnLineSegment(cx, cy,
			ax, ay, px, py);

	return (isInTriangle && !isOnEdge);
}