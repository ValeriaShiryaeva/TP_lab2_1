#include "Airport.h"

int input_number();

Airport::Airport() :length(0), data(nullptr) {
    cout << "The constructor is called Airport" << endl;
}
// ��������
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
// ���������� 
void Airport::creat_airport(int index) {
    Aeroflot A;
    A.input_keyboard();
    memory_allocation_airport(A, index);
}
// ����������
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
        cout << "� ��������� ��� ������ ���������" << endl << endl;
    }
    else {
        cout << endl << "����� ���������" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "���� " << i + 1<< endl;
            data[i].output_console();
        }
    }
    cout << endl;
}
// ����������
void Airport::delite_airport() {
    delete[] data;
    data = nullptr;
    length = 0;
    cout << "�������� ������" << endl;
}
// ����������
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
    cout << "�������� ������" << endl;
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
                cout << "������� ����� �������� ������ ���������� �����" << endl;
                data[index].inputNameDestination();
                cout << "�������� �������� ������ ���������� �����" << endl;
                break;
            case 2:
                getline(cin, s);
                cout << "������� ����� ����� ����� ��������" << endl;
                data[index].inputNumberFlight();
                cout << "������� ����� �����" << endl;
                break;
            case 3:
                getline(cin, s);
                cout << "������� ����� ��� ��������" << endl;
                data[index].inputTypeAircraft();
                cout << "������� ��� ��������" << endl;
                break;
            }
            if (punkt_menu == 4)
                break;
        }
        else
            cout << "�� ����� ������ �����. ��������� ����." << endl;
    }
}

void Airport::print_change_aeroflot_menu() {
    cout << "��� �� ������ ��������?" << endl;
    cout << "1. �������� ������ ���������� �����" << endl;
    cout << "2. ����� �����" << endl;
    cout << "3. ��� ��������" << endl;
    cout << "4. ����� � ������� ����" << endl;
}

void Airport::search(string s) {
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i].getNameDestination() == s)
        {
            cout << "������ ���� " << i + 1 << endl;
            data[i].output_console();
            flag = 1;
        }
        if (flag == 0)
            cout << "���������� �� �������. " << endl;
    }
}