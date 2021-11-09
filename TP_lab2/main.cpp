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
				cout << "В аэропорту нет Аэрофлотов, ничего нельзя удалить" << endl;
			break;
		case 4:
			if (airport.getLength() != 0)
				change();
			else
				cout << "В аэропорту нет Аэрофлотов, ничего нельзя изменить" << endl;
			break;
		case 5:
			if (airport.getLength() != 0)
			{
				if (airport.getLength() != 1)
				{
					airport.sorting_aeroflot();
					cout << "Аэрофлоты отсортированы" << endl;
				}
				else
					cout << "В аэропорту один Аэрофлот, нет смысла сортировки." << endl;
			}
			else
				cout << "В аэропорту нет Аэрофлотов, ничего нельзя отсортировать." << endl;
			break;
		case 6:
			if (airport.getLength() != 0)
				search_by_destination();
			else
				cout << "В аэропорту нет Аэрофлотов, ничего нельзя найти." << endl;
			break;
		case 0:
			exit(0);
		}
	}
	else
		cout << "Введен не верный пункт меню. " << endl;
}

void print_menu()
{
	cout << "Выберете пункт меню:" << endl;
	cout << "	1. Вывод на экран содержимого аэропорта "<< endl;
	cout << "	2. Добавление Аэрофлота на выбранную позицию" << endl;
	cout << "	3. Удаление выбранного Аэрофлота" << endl;
	cout << "	4. Редактирование выбранного Аэрофлота" << endl;
	cout << "	5. Упорядочить аэрофлоты по номерам рейсов" << endl;
	cout << "	6. Вывести на экран рейсы по свопадению названия пункта назначения" << endl;
	cout << "	0. Выход из программы" << endl;
}

int selection_position_addendum() {
	while (1) {
		cout << "Вы можете добавть Аэрофлот на позицию от 1 до " << airport.getLength() + 1 << endl;
		int number_position = input_number();
		if (number_position >= 1 && number_position <= airport.getLength() + 1)
			return number_position;
		else
			cout << "Введена не верная позиция Аэрофлота" << endl;
	}	
}

int selection_position() {
	airport.output_to_console();
	while (1) {
		cout << "Выберите позицию Аэрофлота. ";
		int number_position = input_number();
		if (number_position >= 1 && number_position <= airport.getLength())
			return number_position;
		else
			cout << "Введена не верная позиция Аэрофлота" << endl;
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
			cout << "Не верно введен номер. ";
	}
}

void print_menu_delite() {
	cout << "Что вы хотите удалить?" << endl;
	cout << "1. Удалить аэропорт" << endl;
	cout << "2. Удалить Аэрофлот" << endl;
	cout << "3. Выход в главное меню" << endl;
}

void change() {
	while (1) {
		airport.output_to_console();
		cout << "Выберите Аэрофлот, который хотите изменить. "; 
		int number = input_number();
		if (number <= airport.getLength() && number != 0)
		{
			airport.change_aeroflot(number - 1);
			break;
		}
		else
			cout << "Не верно введен номер. ";
	}
}

void search_by_destination() {
	string s;
	getline(cin, s);
	cout << "Введите пункт назначения, по которому будет поиск" << endl;
	while (1) {
		getline(cin, s);
		if (s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ - ") == string::npos)
		{
			airport.search(s);
			break;
		}
		else
			cout << "Введено не верное название пункта назначения, повторите ввод." << endl;
	}
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << "Введите: " << endl;
		cin >> number_s;
		if (number_s.find_first_not_of("0123456789", 0) == string::npos)
		{
			int number = stoi(number_s);
			return number;
		}
		else
			cout << "Введено не верное значение. Повторите ввод." << endl;
	}
}