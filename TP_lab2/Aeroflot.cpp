#include "Aeroflot.h"

string string_name_destination = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ�������������������������������������Ũ�������������������������� -";
string string_number_flight = "SU -1234567890";
string string__type_aircraft = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ�������������������������������������Ũ�������������������������� -1234567890";

Aeroflot::Aeroflot() : name_destination("uncounted"), number_flight("uncounted"), type_aircraft("uncounted"){
	cout << "The constructor is called Aeroflot" << endl;
}

Aeroflot::Aeroflot(string _name_destination, string _number_flight, string _type_aircraft):
	name_destination(_name_destination), number_flight(_number_flight), type_aircraft(_type_aircraft){
	cout << "The constructor with parameters is called Aeroflot" << endl;
}

Aeroflot::Aeroflot(const Aeroflot& A): 
	name_destination(A.name_destination), number_flight(A.number_flight), type_aircraft(A.type_aircraft){
	cout << "The copy constructor is called Aeroflot" << endl;
}

Aeroflot::~Aeroflot() {
	cout << "Destructor called Aeroflot" << endl;
}

void Aeroflot::inputNameDestination() {
	string _name_destination;
	while (1) {
		getline(cin, _name_destination);
		if (_name_destination.find_first_not_of(string_name_destination) == string::npos)
		{
			name_destination = _name_destination;
			break;
		}
		else
			cout << "������� �� ������ �������� ������ ����������, ��������� ����." << endl;
	}
}

void Aeroflot::inputNumberFlight() {
	string _number_flight;
	while (1) {
		getline(cin, _number_flight);
		if (_number_flight.find_first_not_of(string_number_flight) == string::npos && _number_flight.find("SU") != string::npos
			&& _number_flight.size() >= 3 && _number_flight.size() <= 8)
		{
			number_flight = _number_flight;
			break;
		}
		else
			cout << "������ �� ������ ����� �����, ��������� ����." << endl;
	}
}

void Aeroflot::inputTypeAircraft() {
	string _type_aircraft;
	while (1) {
		getline(cin, _type_aircraft);
		if (_type_aircraft.find_first_not_of(string__type_aircraft) == string::npos)
		{
			type_aircraft = _type_aircraft;
			break;
		}
		else
			cout << "������ �� ������ ��� ��������, ��������� ����." << endl;
	}
}

void Aeroflot::input_keyboard() {
	string s;
	getline(cin, s); // cinignor ������� ������-��
	cout << "������� �������� ������ ���������� �����" << endl;
	inputNameDestination();
	cout << "������� ����� ����� ��������" << endl;
	inputNumberFlight();
	cout << "������� ��� ��������" << endl;
	inputTypeAircraft();
}

void Aeroflot::output_console() {
	cout << "�������� ������ ���������� �����: " << name_destination << endl;
	cout << "����� �����: " << number_flight << endl;
	cout << "��� ��������: " << type_aircraft << endl;
}
