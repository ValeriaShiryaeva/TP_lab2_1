#include "Airport.h"

int input_number();

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
// переписать 
void Airport::creat_airport(int index) {
    Aeroflot A;
    A.input_keyboard();
    memory_allocation_airport(A, index);
}
// переписать
void Airport::memory_allocation_airport(Aeroflot& A, int index) {
    Aeroflot* tmp = data;
    length++;
    data = new Aeroflot[length];
    for (int i = 0; i < length; i++)
    {
        if(i < index && i != index )
            data[i] = tmp[i];
        if (i > index && i != index)
            data[i] = tmp[i - 1];
        if (i == index)
            data[i] = A;
    }
}

void Airport::output_to_console() {
    if (length == 0) {
        cout << "В аэропорте нет рейсов Аэрофлота" << endl << endl;
    }
    else {
        cout << endl << "Рейсы Аэрофлота" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Рейс " << i + 1<< endl;
            data[i].output_console();
        }
    }
    cout << endl;
}
// переписать
void Airport::delite_airport() {
    delete[] data;
    data = nullptr;
    length = 0;
    cout << "Аэропорт удален" << endl;
}
// переписать
void Airport::delite_aeroflot(int index) {
    Aeroflot * tmp = new Aeroflot[length - 1];
    int t = 0;
    for (int i = 0; i < length; i++)
    {
        if (i != index)
            tmp[t++] = data[i];
    }
    length--;
    data = tmp;
    cout << "Аэрофлот удален" << endl;
}

void Airport::change_aeroflot(int index) {
    while (1) {
        print_change_aeroflot_menu();
        int punkt_menu = input_number();
        if (punkt_menu <= 4 && punkt_menu >= 1) {
            string s;
            switch (punkt_menu)
            {
            case 1:
                getline(cin, s);
                cout << "Введите новое название пункта назначения рейса" << endl;
                data[index].inputNameDestination();
                cout << "Изменено название пункта назначения рейса" << endl;
                break;
            case 2:
                getline(cin, s);
                cout << "Введите новый номер рейса самолета" << endl;
                data[index].inputNumberFlight();
                cout << "Изменен номер рейса" << endl;
                break;
            case 3:
                getline(cin, s);
                cout << "Введите новый тип самолета" << endl;
                data[index].inputTypeAircraft();
                cout << "Изменен тип самолета" << endl;
                break;
            }
            if (punkt_menu == 4)
                break;
        }
        else
            cout << "Не верно введен пункт. Посторите ввод." << endl;
    }
}

void Airport::print_change_aeroflot_menu() {
    cout << "Что вы хотите изменить?" << endl;
    cout << "1. Название пункта назначения рейса" << endl;
    cout << "2. Номер рейса" << endl;
    cout << "3. Тип самолета" << endl;
    cout << "4. Выйти в главное меню" << endl;
}

void Airport::search(string s) {
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i].getNameDestination() == s)
        {
            cout << "Найден рейс " << i + 1 << endl;
            data[i].output_console();
            flag = 1;
        }
        if (flag == 0)
            cout << "Совпадений не найдено. " << endl;
    }
}