#include <iostream>
#include <cstring>
#include <string>
#include "Line.h"

using std::cout;
using std::cin;
using std::strcpy;


	Line::Line():linePtr(new char[1]), lineLength(1), lineCapacity(1){ //Line default constructor
		linePtr[0] = '\0';
	}

	Line::Line(const char* line){ //Line copy constructor

		lineLength = strlen(line) + 1; 
		lineCapacity = lineLength;
		linePtr = new char[lineCapacity];
		strcpy(linePtr,line);
	}

	Line::Line (char ch){//Line copy ctor

		linePtr = new char[1];
		linePtr[0] = ch;
		linePtr[1] = '\0';
		lineLength = 1;
		lineCapacity = 1;
	}

	Line::Line(const Line &copyObj){ //Copy ctor
		linePtr = new char[copyObj.lineLength];
		strcpy(linePtr, copyObj.linePtr);

		lineLength = copyObj.lineLength;
		lineCapacity = lineLength;
	}

	const Line& Line::operator=(const Line &copyObj){ //Assignment operator
		if(this == &copyObj) {
			return *this;
		}
			

		delete[] linePtr;
		lineLength =  copyObj.lineLength;
		lineCapacity = copyObj.lineCapacity;
		linePtr = new char[lineCapacity];
		strcpy(linePtr, copyObj.linePtr);

		return *this;
	}


	 Line::~Line() { //Destructor
		delete[] linePtr;
	}

	const char* Line::cstr() const{ 
		return linePtr;
	}

	int Line::length() const{
		return lineLength;
	}

	bool Line::empty () const{

		return(lineLength == 0);
	}

	bool Line::full () const{ //Function to check full
		return(lineLength == lineCapacity);
	}

	int Line::capacity() const{
		return lineCapacity;
	}

	void Line::resize(){ // /function to resize
		lineCapacity = lineCapacity * 2;
		char* temp = new char[lineCapacity];

		for(int i =0; i<lineLength; i++){
			temp[i] = linePtr[i];
		}
		delete[] linePtr;
		linePtr =  temp;
	}

	void Line::push_back(const char &ch){ //function to enter ch at the end
		if(full())resize();
		linePtr[lineLength++] = ch;
		linePtr[lineLength] = '\0';
	}

	void Line::pop_back(){ // function to delete ch
		if(empty())return;
		lineLength--;
	}

	std::ostream& operator<<(std::ostream &out, const Line &line){ //overloaded function << out
		out << line.cstr();
		return out;
	}

	std::istream& operator>>(std::istream &in, Line &line){ // overload function >> in
		std::string str;
		getline(in, str);

		Line readLine(str.c_str());
		line = readLine;
		
		return in;
	}

