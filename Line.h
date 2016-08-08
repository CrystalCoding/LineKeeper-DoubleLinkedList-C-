


#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <istream>
#include <ostream>
using std::ostream;

class Line{

private:
	char* linePtr;
	int lineLength;
	int lineCapacity;

public:
	Line();
	Line(const char* line);
	Line(char);
	Line(const Line&);
	const Line& operator=(const Line&);
	virtual ~Line();
	const char* cstr() const;
	int length() const;
	bool empty() const;
	bool full() const;
	int capacity() const;
	void resize();
	void push_back(const char&);
	void pop_back();

};

	std::ostream& operator<<(std::ostream &out, const Line &);
	std::istream& operator>>(std::istream &in, Line &);

	#endif

