#include <iostream>
#include "Functions.h"

int stateMenu;
void Menu() {
    cout << "Виберіть дію:" << endl
        << "0. Вихід з програми" << endl
        << "1. Ввід даних " << endl
        << "2. Друкування даних " << endl
        << "3. Редагування даних " << endl
        << "4. Видалення " << endl
        << "5. Додавання даних " << endl
        << "6. Вибірка з файлу " << endl
        << "7. Розрахунок " << endl
        << "8. Сортування " << endl
        << "9. Збереження " << endl
        << "Ваша дія: ";
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
            cout << "Ввід вручну чи з файлу?" << endl << "1 - Вручну" << endl << "2 - З файлу" << endl;
            cin >> actions;
            system("cls");

            if (actions == 1) {
                //ввід вручну
                DataInput(d, amountOfData);
            }
            else
            {
                //ввід з файлу
                // cout << "У випадку вводу з файлу введіть назву файлу" << endl;
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
                cout << "Дані порожні!" << endl;
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
                cout << "Дані порожні!" << endl;
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
                cout << "Дані порожні!" << endl;
            }
            system("pause");
            system("cls");
            cout << "Видалення" << endl;
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
                cout << "Дані порожні!" << endl;
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
                cout << "Дані порожні!" << endl;
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
                cout << "Дані порожні!" << endl;
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
                cout << "Дані порожні!" << endl;
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
                cout << "Введіть назву файлу:" << endl;
                cin >> fileName;
                SaveData(d, amountOfData, fileName);
               /* SaveData(d, amountOfData, "Pictures.txt");*/
            }
            else
                cout << "Дані порожні" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
        default:
        {
            cout << "Невірно введений номер дії" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
        }
    }
}


