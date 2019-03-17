#pragma once
#include "Point.h"
#include <vector>
#include <gl/glut.h>

struct Triangle
{

	void add_coord_vertex( unsigned short ,unsigned short );

	void init(Point);

	std::vector<Point> Vertices;

};
