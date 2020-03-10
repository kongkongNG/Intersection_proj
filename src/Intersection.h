#pragma once

#include "Geomtry.h"
#include "Line.h"
#include "Circle.h"
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

class Intersection {
public:
	vector<Geomtry*> geoms;
	set<Point> points;

	int count_intersection();
	void count_intersection(string fileIn, string fileOut);
};