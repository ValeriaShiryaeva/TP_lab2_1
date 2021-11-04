#include <iostream>
#include <fstream>
//#include <stdio.h>
#include"Airport.h"
#include "Aeroflot.h"
using namespace std;

Airport airport;

int main()
{
	setlocale(LC_ALL, "rus");

	airport.creat_airport();
	airport.output_to_console();
	//while (1)
		//menu();
}