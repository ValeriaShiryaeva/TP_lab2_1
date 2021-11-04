#include "Airport.h"

Airport::Airport() :length(0), data(nullptr) {
    cout << "The constructor is called Airport" << endl;
}
// дописать
Airport::Airport(int _length) : length(_length) {
    for (int i = 0; i < length; i++)
        //creat();
    cout << "The constructor with parameters is called Airport" << endl;
}

Airport::Airport(const Airport& airport) {
    data = new Aeroflot[airport.length];
    length = airport.length;
    for (int i = 0; i < airport.length; i++)
        data[i] = airport.data[i];
    cout << "The copy constructor is called Airport" << endl;
}

Airport::~Airport() {
    delete[] data;
    data = nullptr;
    length = 0;
    cout << "Destructor called Airport" << endl;
}

Aeroflot& Airport::operator[](int index) {
    if (index >= 0 && index < length)
        return data[index];
}

Airport& Airport::operator=(const Airport& keeper)
{
    if (this == &keeper)
        return *this;
    delete[] data;
    data = new Aeroflot[keeper.length];
    length = keeper.length;
    for (int i = 0; i < keeper.length; i++)
        data[i] = keeper.data[i];
    return *this;
}
// дописать
void Airport::creat_airport() {
    Aeroflot A;
    A.input_keyboard();
    memory_allocation_airport(A);
}

void Airport::memory_allocation_airport(Aeroflot& A) {
    Aeroflot* tmp = data;
    length++;
    data = new Aeroflot[length];
    for (int i = 0; i < length - 1; i++)
        data[i] = tmp[i];
    data[length - 1] = A;
}

void Airport::output_to_console() {
    if (length == 0) {
        cout << "В аэропорте нет рейсов Аэрофлота" << endl << endl;
    }
    else {
        cout << endl << "Рейсы Аэрофлота" << endl;
        for (int i = 0; i < length; i++)
            data[i].output_console();
    }
}