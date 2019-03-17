#include "Triangle.h"


void Triangle::add_coord_vertex(unsigned short x, unsigned short y)
{

	Vertices.back().x = x;
	Vertices.back().y = y;

}

void Triangle::init(Point point)
{
	Vertices.push_back(point);
}

