//#pragma once
#ifndef _LINE_H
#define _LINE_H

#include "Geomtry.h"
#include "Circle.h"

class Line : public Geomtry {
private:
	double k;
	double b;
	double x;		// use it when Vertical to X
	bool verToX = false;
	bool verToY = false;
public:
	Line(int x1, int y1, int x2, int y2);
	bool isInterset(Geomtry* obj);
	vector<Point> getInterPoint(Geomtry* obj);
	
	bool isVerticalToX();
	bool isVerticalToY();

};
#endif // !
