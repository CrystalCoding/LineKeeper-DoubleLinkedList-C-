
#include "LineKeeper.h"
#include <fstream>
#include <string>
#include "Line.h"

using std::string;
using std::ifstream;

LineKeeper::LineKeeper(const char * filename) { // LineKeeper ctor
	// TODO Auto-generated constructor stub
	ifstream is(filename);
	string inputString;
	if (!is.is_open()) {  // checking file
		exit(0);
	}
	while (getline(is, inputString)) { 
		Line inputLine(inputString.c_str());
		list.push_back(inputLine);
	}

}

void LineKeeper::print(int m, int n) { // print function: using print function of linked list class
	if (m > n) {
		int temp = m;
		m = n;
		n = temp;
	}

	if (m < 1) {
		m = 1;
	}

	if (n > list.size()) {
		n = list.size();
	}

	for (int i = m; i <= n; ++i) {
		list.print(i);
	}
}