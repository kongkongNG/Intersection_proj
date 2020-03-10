#include "Circle.h"

Circle::Circle(int x, int y, int r) {
	this->type = CIRCLE;
	this->n = (double)x;
	this->m = (double)y;
	this->r = (double)r;
}

bool Circle::isInterset(Geomtry* obj) {
	if (obj->type == LINE) {
		return obj->isInterset(this);
	}
	else if (obj->type == CIRCLE) {
		Circle* cc = dynamic_cast<Circle*>(obj);
		double dcenter = sqrt((n - cc->n) * (n - cc->n) 
			+ (m - cc->m) * (m - cc->m));	// d = sqrt((x1-x2)^2 + (y1-y2)^2)
		if (dcenter > r + cc->r || dcenter < fabs(r - cc->r) ) {
			return false;
		}
		else {
			return true;
		}
	}

	return false;
}
vector<Point> Circle::getInterPoint(Geomtry* obj) {
	vector<Point> pvec;

	if (obj->type == LINE) {
		return obj->getInterPoint(this);
	}
	else if (obj->type == CIRCLE) {
		Circle* cc = dynamic_cast<Circle*>(obj);
		double d, CE, AE;
		double x0, y0, x1, y1, x2, y2;
		//double dinter;
		//double tmp;

		//L = sqrt((n - cc->n) * (n - cc->n)
		//	+ (m - cc->m) * (m - cc->m));	// distance of two centers
		//AE = (this->r * this->r - cc->r * cc->r + L * L) / (2 * L);
		//x0 = this->n + (AE / L) * (cc->n - this->n); // x0 = x1 + AE/L * (x2 - x1)
		//y0 = this->m + (AE / L) * (cc->m - this->m); // x0 = y1 + AE/L * (y2 - y1)

		//dinter = sqrt((n - x0) * (n - x0)
		//	+ (m - y0) * (m - y0));	// distance of two centers
		//if (dinter == r) {
		//	pvec.push_back({ x0, y0 });
		//	return pvec;
		//}
		//CE = sqrt(r * r - (x0 - this->n) * (x0 - this->n) 
		//	- (y0 - this->m) * (y0 - this->m));	// CE^2 = r1^2 - (x0-x1)^2 - (y0-y1)^2
		//tmp = sqrt(1 )
		d = sqrt((n - cc->n) * (n - cc->n)
				+ (m - cc->m) * (m - cc->m));	// distance of two centers
		AE = (this->r * this->r - cc->r * cc->r + d * d) / (2 * d);
		x0 = this->n + AE / d * (cc->n - this->n); // x0 = x1 + AE/d * (x2-x1)
		y0 = this->m + AE / d * (cc->m - this->m); // x0 = x1 + AE/d * (x2-x1)
		CE = sqrt(r * r - AE * AE); // CE^2 + AE^2 = AC^2 = r^2

		x1 = x0 - CE / d * (cc->m - m);
		y1 = y0 + CE / d * (cc->n - n);
		x2 = x0 + CE / d * (cc->m - m);
		y2 = y0 - CE / d * (cc->n - n);

		if (x1 == x2 && y1 == y2) {
			pvec.push_back({ x1, y1 });
		}
		else {
			pvec.push_back({ x1, y1 });
			pvec.push_back({ x2, y2 });
		}

	}

	return pvec;
}