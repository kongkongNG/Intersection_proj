#include "Intersection.h"

int Intersection::count_intersection() {
	int N;
	char type;
	int x1, x2, y1, y2;
	int x, y, r;
	Geomtry* gmt;

	cin >> N;
	while (N--) {

		cin >> type;
		if (type == 'L') {
			cin >> x1 >> y1 >> x2 >> y2;
			gmt = new Line(x1, y1, x2, y2);

		}
		else if (type == 'C') {
			cin >> x >> y >> r;
			gmt = new Circle(x, y, r);
		}
		else {
			break;
		}
		for (auto it = geoms.begin(); it != geoms.end(); it++) {
			if (gmt->isInterset(*it)) {
				vector<Point> pvec = gmt->getInterPoint(*it);
				for (auto pIt = pvec.begin(); pIt != pvec.end(); pIt++) {
					pIt->id = points.size();
					points.insert(*pIt);
				}
			}
		}
		geoms.push_back(gmt);
	}

	for (auto it = points.begin(); it != points.end(); it++) {
		cout << (*it).x << " " << (*it).y << endl;
	}

	return points.size();
	
}

void Intersection::count_intersection(string fileIn, string fileOut) {
	ifstream fin;
	ofstream fout;
	int N;
	char type;
	int x1, x2, y1, y2;
	int x, y, r;
	Geomtry* gmt;

	fin.open(fileIn, ios::in);
	if (!fin.is_open()) {
		cout << "Error file name!" << endl;
	}

	fin >> N;
	while (N--) {

		fin >> type;
		if (type == 'L') {
			fin >> x1 >> y1 >> x2 >> y2;
			gmt = new Line(x1, y1, x2, y2);

		}
		else if (type == 'C') {
			fin >> x >> y >> r;
			gmt = new Circle(x, y, r);
		}
		else {
			break;
		}
		for (auto it = geoms.begin(); it != geoms.end(); it++) {
			if (gmt->isInterset(*it)) {
				vector<Point> pvec = gmt->getInterPoint(*it);
				for (auto pIt = pvec.begin(); pIt != pvec.end(); pIt++) {
					pIt->id = points.size();
					points.insert(*pIt);
				}
			}
		}
		geoms.push_back(gmt);
	}

	fout.open(fileOut, ios::out);
	fout << points.size();

	fin.close();
	fout.close();
	//return points.size();
	/*for (auto it = points.begin(); it != points.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}*/
}