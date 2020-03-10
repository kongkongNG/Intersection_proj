#pragma once
//#include "Line.h"
//#include "Circle.h"
#include <math.h>
#include <iostream>
#include <vector>
#define EPS 1e-6

using namespace std;

enum Type {
	LINE, CIRCLE
};

struct Point {
	int id;
	double x, y;

	Point(double x, double y) : x(x), y(y) {}

	bool operator<(const Point &p) const
	{
		if (fabs(x - p.x) <= EPS && fabs(y - p.y) <= EPS) {
			return false;
		}
		else {
			return (x!=p.x)? x < p.x : y < p.y;
		}
		
	}
};

class Geomtry {

public:
	int type;
	virtual bool isInterset(Geomtry* obj) = 0;
	virtual vector<Point> getInterPoint(Geomtry* obj) = 0;
	static vector<double> solve(double a, double b, double c) {	// solve ax^2 + bx + c = 0
		vector<double> ans;
		double delta = b * b - 4 * a * c;
		if (delta == 0) {
			double x = -b / (2 * a);
			ans.push_back(x);
		}
		else if (delta > 0) {
			double sq = sqrt(delta);
			double x1 = (-b + sq) / (2 * a);
			double x2 = (-b - sq) / (2 * a);
			ans.push_back(x1);
			ans.push_back(x2);
		}

		return ans;
	}

};