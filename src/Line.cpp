#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2) {
	this->type = LINE;
	
	if (x1 == x2) {
		verToX = true;
		this->x = (double)x1;
		this->k = 0.0;
		this->b = 0.0;
	}
	else {
		if (y1 == y2) {
			verToY = true;
		}
		this->x = 0.0;
		this->k = 1.0 * ((double)y2 - y1) / ((double)x2 - x1);
		this->b = 1.0 * y1 - this->k * x1;
	}
	
}

bool Line::isInterset(Geomtry* obj) {
	if (obj->type == LINE) {
		Line *ln = dynamic_cast<Line*>(obj);

		/* handle special lines!!! */
		if (this->isVerticalToX()) {
			if (ln->isVerticalToX()) {
				return false;
			}
			else {
				return true;
			}
		}
		if (ln->isVerticalToX()) {
			if (this->isVerticalToX()) {
				return false;
			}
			else {
				return true;
			}
		}
		return fabs(this->k - ln->k) > EPS;
	}
	else if (obj->type == CIRCLE) {
		Circle *cc = dynamic_cast<Circle*>(obj);
		double up, down, d;

		/*   handle special line!!!   */
		if (isVerticalToX()) {
			d = fabs(cc->n - this->x);
		}
		else if (isVerticalToY()) {
			d = fabs(cc->m - this->b);
		}
		else {
			up = this->k * cc->n - cc->m + this->b;
			down = sqrt(this->k * this->k + 1);
			d = fabs(up / down);
		}
		
		if (d > cc->r) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		cout << "error in Line::isInterset" << endl;
		return false;
	}	
}


vector<Point> Line::getInterPoint(Geomtry* obj) {
	vector<Point> pvec;

	if (obj->type == LINE) {
		Line *ln = dynamic_cast<Line*>(obj);
		double x, y;

		/*   handle special lines!!! */
		if (this->isVerticalToX()) {
			x = this->x;
			y = ln->k * x + ln->b;
		}
		//else if (this->isVerticalToY()) {
		//	y = this->b;
		//	if (ln->isVerticalToX()) {
		//		x = ln->x;
		//	}
		//	else {
		//		x = (y - ln->b) / ln->k;
		//	}
		//}
		else if (ln->isVerticalToX()) {
			x = ln->x;
			y = this->k * x + this->b;
		}
		//else if (ln->isVerticalToY()) {
		//	y = ln->b;
		//	x = (y - ln->b) / ln->k
		//}
		else {			// no need to consider vertical to y because we can handle it
			x = (ln->b - this->b) / (this->k - ln->k);
			y = this->k * x + this->b;
		}
		
		pvec.push_back({ x, y });
	}
	else if (obj->type == CIRCLE) {
		Circle *cc = dynamic_cast<Circle*>(obj);
		//double x1, x2, y1, y2;
		double A, B, C;

		if (this->isVerticalToX()) {
			double delta = cc->r * cc->r - (this->x - cc->n) * (this->x - cc->n);
			if (delta == 0) {
				pvec.push_back({ this->x, cc->m });
			}
			else {
				delta = sqrt(delta);
				pvec.push_back({ this->x, cc->m + delta });
				pvec.push_back({ this->x, cc->m - delta });
			}
		}
		else if (this->isVerticalToY()) {
			double delta = cc->r * cc->r - (this->b - cc->m) * (this->b - cc->m);
			if (delta == 0) {
				pvec.push_back({ cc->n, this->b });
			}
			else {
				delta = sqrt(delta);
				pvec.push_back({ cc->n + delta, this->b });
				pvec.push_back({ cc->n - delta, this->b });
			}
		}
		else {
			A = 1 + k * k;
			B = 2 * k * (b - cc->m) - 2 * cc->n;
			C = (b - cc->m) * (b - cc->m) + cc->n * cc->n - cc->r * cc->r;
			vector<double> ans = Geomtry::solve(A, B, C);
			for (auto it = ans.begin(); it != ans.end(); it++) {
				double yi = k * *it + b;
				pvec.push_back({ *it, yi });
			}
		}
	}

	return pvec;
}

bool Line::isVerticalToX() {
	return this->verToX;
}
bool Line::isVerticalToY() {
	return this->verToY;
}