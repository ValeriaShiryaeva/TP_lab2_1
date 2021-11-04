#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Aeroflot
{
private: 
	string name_destination;
	string number_flight;
	string type_aircraft;
public:
	Aeroflot();
	Aeroflot(string, string, string);
	Aeroflot(const Aeroflot&);
	~Aeroflot();

	void setNameDestination(string _name_destination) { name_destination = _name_destination; }
	void setNumberFlight(string _number_flight) { number_flight = _number_flight; }
	void setTypeAircraft(string _type_aircraft) { type_aircraft = _type_aircraft; }

	string getNameDestination() { return name_destination; }
	string getNumberFlight() { return number_flight; }
	string getTypeAircraft() { return type_aircraft; }

	void inputNameDestination();
	void inputNumberFlight();
	void inputTypeAircraft();

	void inputFileNameDestination();
	void inputFileNumberFlight();
	void inputFileTypeAircraft();

	void input_keyboard();
	void input_from_file(ifstream&);
	void output_console();
	void output_to_file(ofstream&);

	void change();
	void print_menu_change();

};
