#include "Intersection.h"
//#define DEBUG
//#define PERF

int main(int argc, char* argv[]) {
	Intersection inter;
#ifdef DEBUG
	cout << inter.count_intersection() << endl;
	
#else
#ifdef PERF
	inter.count_intersection("input18.txt", "out.txt");
#else
	if (argc < 5) {
		cout << "Error, too few parameters!!!" << endl;
	}
	else {
		if (string(argv[1]) == "-i" && string(argv[3]) == "-o") {
			inter.count_intersection(argv[2], argv[4]);
		}
		else if (string(argv[1]) == "-o" && string(argv[3]) == "-i") {
			inter.count_intersection(argv[4], argv[2]);
		}
		else {
			cout << "Error, use -i <path/to/input file> -o <path/to/output file>" << endl;
		}
	}
#endif // PERF
#endif // DEBUG

	
	
	

}