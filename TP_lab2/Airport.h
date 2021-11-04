#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Aeroflot.h"

using namespace std;
class Airport
{
private:
	int length;
	Aeroflot* data;
public:
	Airport();
	Airport(int);
	Airport(const Airport&);
	~Airport();

	Airport& operator=(const Airport&);
	Aeroflot& operator[](int);

	void setLength(int _length) { length = _length; }
	int getLength() { return length; }

	void creat_airport();
	void memory_allocation_airport(Aeroflot&);

	void output_to_console();
};

