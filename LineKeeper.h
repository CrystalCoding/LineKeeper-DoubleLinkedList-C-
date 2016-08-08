#ifndef LINEKEEPER_H_
#define LINEKEEPER_H_

#include "LinkedList.h"

class LineKeeper {
private:
	LinkedList list;
public:
	LineKeeper(const char*);
	void print(int m, int n = 0);
};

#endif /* LINEKEEPER_H_ */
