#include <iostream>
#include"Airport.h"
#include "Aeroflot.h"
using namespace std;

Airport airport;

void menu();
void print_menu();
int selection_position();
int selection_position_addendum();
void delite();
void print_menu_delite();
void change();
void search_by_destination();
int input_number();

int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
		menu();
}

void menu() {
	print_menu();
	int punkt_menu = input_number();
	if (punkt_menu <= 6 && punkt_menu >= 0) {
		switch (punkt_menu)
		{
		case 1:
			airport.output_to_console();
			break;
		case 2:
			if (airport.getLength() != 0)
				airport += (selection_position_addendum() - 1);
			else
				airport += 0;
			break;
		case 3:
			if (airport.getLength() != 0)
				delite();
			else
				cout << "� ��������� ��� ����������, ������ ������ �������" << endl;
			break;
		case 4:
			if (airport.getLength() != 0)
				change();
			else
				cout << "� ��������� ��� ����������, ������ ������ ��������" << endl;
			break;
		case 5:
			if (airport.getLength() != 0)
			{
				if (airport.getLength() != 1)
				{
					airport.sorting_aeroflot();
					cout << "��������� �������������" << endl;
				}
				else
					cout << "� ��������� ���� ��������, ��� ������ ����������." << endl;
			}
			else
				cout << "� ��������� ��� ����������, ������ ������ �������������." << endl;
			break;
		case 6:
			if (airport.getLength() != 0)
				search_by_destination();
			else
				cout << "� ��������� ��� ����������, ������ ������ �����." << endl;
			break;
		case 0:
			exit(0);
		}
	}
	else
		cout << "������ �� ������ ����� ����. " << endl;
}

void print_menu()
{
	cout << "�������� ����� ����:" << endl;
	cout << "	1. ����� �� ����� ����������� ��������� "<< endl;
	cout << "	2. ���������� ��������� �� ��������� �������" << endl;
	cout << "	3. �������� ���������� ���������" << endl;
	cout << "	4. �������������� ���������� ���������" << endl;
	cout << "	5. ����������� ��������� �� ������� ������" << endl;
	cout << "	6. ������� �� ����� ����� �� ���������� �������� ������ ����������" << endl;
	cout << "	0. ����� �� ���������" << endl;
}

int selection_position_addendum() {
	while (1) {
		cout << "�� ������ ������� �������� �� ������� �� 1 �� " << airport.getLength() + 1 << endl;
		int number_position = input_number();
		if (number_position >= 1 && number_position <= airport.getLength() + 1)
			return number_position;
		else
			cout << "������� �� ������ ������� ���������" << endl;
	}	
}

int selection_position() {
	airport.output_to_console();
	while (1) {
		cout << "�������� ������� ���������. ";
		int number_position = input_number();
		if (number_position >= 1 && number_position <= airport.getLength())
			return number_position;
		else
			cout << "������� �� ������ ������� ���������" << endl;
	}	
}

void delite() {
	while (1) {
		print_menu_delite();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2 || punkt_menu == 3)
		{
			switch (punkt_menu)
			{
			case 1:
				airport.delite_airport();
				break;
			case 2:
				airport -= (selection_position() - 1);
				break;
			}
			if (punkt_menu == 3)
				break;
		}
		else
			cout << "�� ����� ������ �����. ";
	}
}

void print_menu_delite() {
	cout << "��� �� ������ �������?" << endl;
	cout << "1. ������� ��������" << endl;
	cout << "2. ������� ��������" << endl;
	cout << "3. ����� � ������� ����" << endl;
}

void change() {
	while (1) {
		airport.output_to_console();
		cout << "�������� ��������, ������� ������ ��������. "; 
		int number = input_number();
		if (number <= airport.getLength() && number != 0)
		{
			airport.change_aeroflot(number - 1);
			break;
		}
		else
			cout << "�� ����� ������ �����. ";
	}
}

void search_by_destination() {
	string s;
	getline(cin, s);
	cout << "������� ����� ����������, �� �������� ����� �����" << endl;
	while (1) {
		getline(cin, s);
		if (s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ - ") == string::npos)
		{
			airport.search(s);
			break;
		}
		else
			cout << "������� �� ������ �������� ������ ����������, ��������� ����." << endl;
	}
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << "�������: " << endl;
		cin >> number_s;
		if (number_s.find_first_not_of("0123456789", 0) == string::npos)
		{
			int number = stoi(number_s);
			return number;
		}
		else
			cout << "������� �� ������ ��������. ��������� ����." << endl;
	}
}