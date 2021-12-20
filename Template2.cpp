#include <iostream>
#include "Functions.h"

int stateMenu;
void Menu() {
    cout << "������� ��:" << endl
        << "0. ����� � ��������" << endl
        << "1. ��� ����� " << endl
        << "2. ���������� ����� " << endl
        << "3. ����������� ����� " << endl
        << "4. ��������� " << endl
        << "5. ��������� ����� " << endl
        << "6. ������ � ����� " << endl
        << "7. ���������� " << endl
        << "8. ���������� " << endl
        << "9. ���������� " << endl
        << "���� ��: ";
    cin >> stateMenu;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    int actions, amountOfData = 0;
    string fileName;
    Picture* d = new Picture[amountOfData];

    while (stateMenu != 0) {

        switch (stateMenu)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            system("cls");
            cout << "��� ������ �� � �����?" << endl << "1 - ������" << endl << "2 - � �����" << endl;
            cin >> actions;
            system("cls");

            if (actions == 1) {
                //��� ������
                DataInput(d, amountOfData);
            }
            else
            {
                //��� � �����
                // cout << "� ������� ����� � ����� ������ ����� �����" << endl;
                //cin >> fileName; // Input.txt

                ReadingData(d, amountOfData, "Pictures.txt");
            }

            system("pause");
            system("cls");
            Menu();
            break;
        }
        case 2:
        {
            system("cls");
            if (amountOfData != 0) {
                Print(d, amountOfData);
            }
            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
        case 3:
        {
            system("cls");
            if (amountOfData != 0) {
                DataChange(d, amountOfData);
            }
            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");            
            Menu();
            break;
        }
        case 4:
        {
            system("cls");
            if (amountOfData != 0) {
                DeleteData(d, amountOfData);
            }
            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");
            cout << "���������" << endl;
            Menu();
            break;
        }
        case 5:
        {
            system("cls");
            if (amountOfData != 0) {
                AddData(d, amountOfData);
                amountOfData++;
            }

            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
        case 6:
        {
            system("cls");
            if (amountOfData != 0) {
                Query(d, amountOfData);
            }

            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        }
        case 7:
        {
            system("cls");
            if (amountOfData != 0) {
                Calculating(d, amountOfData);
            }

            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
        case 8:
        {
            system("cls");
            if (amountOfData != 0) {
                DataSorting(d, amountOfData);
            }

            else {
                cout << "��� ������!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
        case 9:
        {
            system("cls");        
            if (amountOfData != 0) {
                cout << "������ ����� �����:" << endl;
                cin >> fileName;
                SaveData(d, amountOfData, fileName);
               /* SaveData(d, amountOfData, "Pictures.txt");*/
            }
            else
                cout << "��� ������" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
        default:
        {
            cout << "������ �������� ����� 䳿" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
        }
    }
}


