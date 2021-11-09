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

	Airport& operator+=(int);
	Airport& operator-=(int);

	void setLength(int _length) { length = _length; }
	int getLength() { return length; }

	Airport& memory_allocation_airport(Aeroflot&, int);

	void output_to_console();

	void delite_airport();

	void change_aeroflot(int);
	void print_change_aeroflot_menu();

	void search(string);

	void sorting_aeroflot();
};

