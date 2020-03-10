//#pragma once
#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Geomtry.h"
#include "Line.h"

class Circle : public Geomtry {

public:
	/*(x-n)^2 + (y-m)^2 = r^2*/
	double n;
	double m;
	double r;
	Circle(int x, int y, int r);
	bool isInterset(Geomtry* obj);
	vector<Point> getInterPoint(Geomtry* obj);

};
#endif // !_CIRCLE_H