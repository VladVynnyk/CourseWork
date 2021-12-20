#include "Functions.h"
#include <iostream>
using std::cout;
using std::cin;
//using namespace std;
void Table()
{
	cout << "|---|----------------------|--------------|-----------------|------------|-------------|------------------|------------------------------------|-----------------------|\n";
	cout << "| № |        Ім'я          |  Прізвище    |  День написання |    Місяць  |    Рік      |     Жанр         |           Назва картини            |Чи потребує реставрації|\n";
	cout << "|   |        автора        |              |                 |            |             |                  |                                    |                       |\n";
	cout << "|---|----------------------|--------------|-----------------|------------|-------------|------------------|------------------------------------|-----------------------|\n";
}

void DataInput(Picture* (&d), int& n)
{
	int num;
	cout << "Введіть к-ть даних" << endl;
	cin >> n;

	d = new Picture[n];

	for (int i = 0; i < n; i++) {
		cout << "Введіть назву картини: " << endl;
		cin >> d[i]._name.name;
		cout << "Введіть імя автора: " << endl;
		cin >> d[i]._author.name;
		cout << "Введіть прізвище автора: " << endl;
		cin >> d[i]._author.surname;

		cout << "Введіть дату написання картини: " << endl;
		cout << "День: " << endl;
		cin >> d[i]._date.day;
		while (true) {
			if (d[i]._date.day >= 1 && d[i]._date.day <= 31)
			{
				cout << "Дані введено вірно." << endl;
				break;
			}
			else
			{
				cout << "Дані введено не вірно. Введіть дані заново." << endl;
				cin >> d[i]._date.day;
			}
		}
		cout << "Місяць: " << endl;
		cin >> d[i]._date.month;
		while (true) {
			if (d[i]._date.month >= 1 && d[i]._date.month <= 12)
			{
				cout << "Дані введено вірно." << endl;
				break;
			}
			else
			{
				cout << "Дані введено не вірно. Введіть дані заново." << endl;
				cin >> d[i]._date.month;
			}
		}
		cout << "Рік: " << endl;
		cin >> d[i]._date.year;


		cout << "Введіть жанр картини: " << endl;
		cin >> d[i]._genre.genre;
		cout << "Чи потребує реставрації(Так або Ні): " << endl;
		cin >> d[i]._restoration.needRestoration;
		while (true) {
			if (d[i]._restoration.needRestoration == "Так" || d[i]._restoration.needRestoration == "Ні") {
				cout << "Дані введено вірно." << endl;
				break;
			}
			else {
				cout << "Дані введено не вірно. Введіть дані заново." << endl;
				cin >> d[i]._restoration.needRestoration;
			}
		}
		cout << "----------------------------------------" << endl;

	}
}

void ReadingData(Picture* (&d), int& n, string fileName)
{
	ifstream reading(fileName);
	if (reading) {
		reading >> n;

		d = new Picture[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i]._name.name;

			reading >> d[i]._author.name;
			reading >> d[i]._author.surname;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;

			reading >> d[i]._genre.genre;

			reading >> d[i]._restoration.needRestoration;
			cout << "Дані прочитані!" << endl;
		}
	}
	else
		cout << "Помилка відкриття файлу:" << endl;
	reading.close();
}

void Print(Picture* d, int n)
{
	Table();
	for (int i = 0; i < n; i++) {
		cout << left << "|" << setw(3) << i+1 << "|  " << setw(20) << d[i]._author.name
			<< "|  " << setw(12) << d[i]._author.surname 
			<< "|  " << setw(15) << d[i]._date.day 
			<< "|     " << setw(7) << d[i]._date.month
			<< "|  " << setw(9) << d[i]._date.year 
			<< "  |" <<  setw(18)  
			<<d[i]._genre.genre << "|  "
			<< setw(34) << d[i]._name.name 
			<< "|     " << setw(16) << d[i]._restoration.needRestoration<< "  |"<<endl;
	}
}
void DataChange(Picture* (&d), int n)
{
	int _n;
	int menu, actions;
	system("cls");
	cout << "1 Редагування одного пункту запису" << endl;
	cout << "2 Редагування запису цілком" << endl;
	cin >> actions;
	cout << "Введіть номер елементу (від 1 до " << n << "):";
	cin >> _n;
	_n--;
	//перевірка що введено прав значення
	if (_n >= 0 && _n < n)
	{
		if (actions == 1) {
			cout << "Який пункт редагуєте?" << endl
			<< "1 Ім'я художника" << endl
			<< "2 Прізвище" << endl
			<< "3 День написання" << endl
			<< "4 Місяць" << endl
			<< "5 Рік" << endl
			<< "6 Жанр" << endl
			<< "7 Чи потребує реставрації(Так або Ні)" << endl;
		cin >> menu;
		
			switch (menu) {
			case 1:
				cout << "Введіть ім'я художника: ";
				cin >> d[_n]._author.name;
				break;
			case 2:
				cout << "Введіть прізвище художника: ";
				cin >> d[_n]._author.surname;
				break;
			case 3:
				cout << "Введіть день написання картини: ";
				cin >> d[_n]._date.day;
				while (true) {
					if (d[_n]._date.day >= 1 && d[_n]._date.day <= 31)
					{
						cout << "Дані введено вірно." << endl;
						break;
					}
					else
					{
						cout << "Дані введено не вірно. Введіть дані заново." << endl;
						cin >> d[_n]._date.day;
					}
				}
				break;
			case 4:
				cout << "Введіть місяць написання картини: ";
				cin >> d[_n]._date.month;
				while (true) {
					if (d[_n]._date.month >= 1 && d[_n]._date.month <= 12)
					{
						cout << "Дані введено вірно." << endl;
						break;
					}
					else
					{
						cout << "Дані введено не вірно. Введіть дані заново." << endl;
						cin >> d[_n]._date.month;
					}
				}
				break;
			case 5:
				cout << "Введіть рік написання картини: ";
				cin >> d[_n]._date.year;
				break;
			case 6:
				cout << "Введіть жанр картини: ";
				cin >> d[_n]._genre.genre;
				break;
			case 7:
				cout << "Чи потребує реставрації: ";
				cin >> d[_n]._restoration.needRestoration;
				while (true) {
					if (d[_n]._restoration.needRestoration == "Так" || d[_n]._restoration.needRestoration == "Ні") {
						cout << "Дані введено вірно." << endl;
						break;
					}
					else {
						cout << "Дані введено не вірно. Введіть дані заново." << endl;
						cin >> d[_n]._restoration.needRestoration;
					}
				}
				break;
			}
		}
	
		if (actions == 2) {
			cout << "Введіть назву картини: ";
			cin >> d[_n]._name.name;
			cout << "Введіть ім'я художника: ";
			cin >> d[_n]._author.name;
			cout << "Введіть прізвище художника: ";
			cin >> d[_n]._author.surname;

			cout << "Введіть дату: ";
			cout << "Введіть день: ";
			cin >> d[_n]._date.day;
			while (true) {
				if (d[_n]._date.day >= 1 && d[_n]._date.day <= 31)
				{
					cout << "Дані введено вірно." << endl;
					break;
				}
				else
				{
					cout << "Дані введено не вірно. Введіть дані заново." << endl;
					cin >> d[_n]._date.day;
				}
			}
			cout << "Введіть місяць: ";
			cin >> d[_n]._date.month;
			while (true) {
				if (d[_n]._date.month >= 1 && d[_n]._date.month <= 12)
				{
					cout << "Дані введено вірно." << endl;
					break;
				}
				else
				{
					cout << "Дані введено не вірно. Введіть дані заново." << endl;
					cin >> d[_n]._date.month;
				}
			}
			cout << "Введіть рік: ";
			cin >> d[_n]._date.year;

			cout << "Введіть жанр:";
			cin >> d[_n]._genre.genre;

			cout << "Чи потребує реставрації(Так або Ні): " << endl;
			cin >> d[_n]._restoration.needRestoration;
			while (true) {
				if (d[_n]._restoration.needRestoration == "Так" || d[_n]._restoration.needRestoration == "Ні") {
					cout << "Дані введено вірно." << endl;
					break;
				}
				else {
					cout << "Дані введено не вірно. Введіть дані заново." << endl;
					cin >> d[_n]._restoration.needRestoration;
				}
			}
		}
		system("cls");
		cout << "Дані змінено!" << endl;
	}
	else
		cout << "Номер введений не вірно" << endl;
}

void Copy(Picture* (&d_n), Picture* (&d_o), int n)
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void DeleteData(Picture* (&d), int& n)
{
	int _n;
	cout << "Введіть номер елементу (від 1 до " << n << "):";
	cin >> _n;
	_n--;
	system("cls");
	//перевірка що введено правильне значення
	if (_n >= 0 && _n < n) {
		Picture* buf = new Picture[n];
		Copy(buf, d, n);
		--n;
		d = new Picture[n];

		int q = 0;
		//запамятовуємо дані крім не потрібного
		for (int i = 0; i <= n; i++)
		{
			if (i != _n) {
				d[q] = buf[i]; // використовуємо індекс q тому що, в осн. масиві елементів менше, ніж в тимчасовому
				++q;
			}
		}
		system("sys");
		delete[] buf;
		cout << "Дані видалено" << endl;
	}
	else
		cout << "Номер введено не вірно" << endl;
}

void AddData(Picture* (&d), int& n)
{
	Picture* buf;
	buf = new Picture[n];

	Copy(buf, d, n);

	n++;
	d = new Picture[n];

	Copy(d, buf, --n);

	cout << "Введіть назву картини: " << endl;
	cin >> d[n]._name.name;
	cout << "Введіть імя та прізвище автора: " << endl;
	cin >> d[n]._author.name >> d[n]._author.surname;
	cout << "Введіть дату написання картини: " << endl;
	cout << "День: " << endl;
	cin >> d[n]._date.day;
	while (true) {
		if (d[n]._date.day >= 1 && d[n]._date.day <= 31)
		{
			cout << "Дані введено вірно." << endl;
			break;
		}
		else
		{
			cout << "Дані введено не вірно. Введіть дані заново." << endl;
			cin >> d[n]._date.day;
		}
	}
	cout << "Місяць: " << endl;
	cin >> d[n]._date.month;
	while (true) {
		if (d[n]._date.month >= 1 && d[n]._date.month <= 12)
		{
			cout << "Дані введено вірно." << endl;
			break;
		}
		else
		{
			cout << "Дані введено не вірно. Введіть дані заново." << endl;
			cin >> d[n]._date.month;
		}
	}

	cout << "Рік: " << endl;
	cin >> d[n]._date.year;

	cout << "Введіть жанр картини: " << endl;
	cin >> d[n]._genre.genre;

	cout << "Чи потребує реставрації(Так або Ні): " << endl;
	cin >> d[n]._restoration.needRestoration;
	while (true) {
		if (d[n]._restoration.needRestoration == "Так" || d[n]._restoration.needRestoration == "Ні") {
			cout << "Дані введено вірно." << endl;
			break;
		}
		else {
			cout << "Дані введено не вірно. Введіть дані заново." << endl;
			cin >> d[n]._restoration.needRestoration;
		}
	}
	system("cls");
	cout << "Дані додано" << endl;
	delete[] buf;
}

void Calculating(Picture* d, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (d[i]._genre.genre == "Портрет") {
			count++;
		}
	}
	cout << "Кількість портретів: "<< count << endl;
}


void Query(Picture* d, int n) {
	int menu;
	int actions;
	cout << "1 Вибірка картин, які потребують реставрації та написані в минулому столітті" << endl;
	cout << "2 Вибірка по іншому полю" << endl;
	cin >> menu;
	Table();
	if (menu == 1) {
		for (int i = 0; i < n; i++) {
			if (d[i]._date.year >= 1901 && d[i]._date.year <= 2000) {
				if (d[i]._restoration.needRestoration == "Так") {
					
					cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
						<< "|  " << setw(12) << d[i]._author.surname
						<< "|  " << setw(15) << d[i]._date.day
						<< "|     " << setw(7) << d[i]._date.month
						<< "|  " << setw(9) << d[i]._date.year
						<< "  |" << setw(18)
						<< d[i]._genre.genre << "|  "
						<< setw(34) << d[i]._name.name
						<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
				}
			}
		}
	}
	if (menu == 2) {
		cout << "По якому полю вибірка?" << endl
			<< "1 Ім'я художника" << endl
			<< "2 Прізвище" << endl
			<< "3 Рік(Інтервал)" << endl
			<< "4 Жанр" << endl
			<< "5 Чи потребує реставрації(Так або Ні)" << endl;
		cin >> actions;
		switch (actions) {
		case 1:
		{
			cout << "Введіть ім'я художника" << endl;
			string name;
			cin >> name;
			Table();
			for (int i = 0; i < n; i++) {
				if (d[i]._author.name == name) {
					cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
						<< "|  " << setw(12) << d[i]._author.surname
						<< "|  " << setw(15) << d[i]._date.day
						<< "|     " << setw(7) << d[i]._date.month
						<< "|  " << setw(9) << d[i]._date.year
						<< "  |" << setw(18)
						<< d[i]._genre.genre << "|  "
						<< setw(34) << d[i]._name.name
						<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
				}
			}
			break;
		}
		case 2:
		{
			cout << "Введіть прізвище художника" << endl;
			string surname;
			cin >> surname;
			Table();
			for (int i = 0; i < n; i++) {
				if (d[i]._author.surname == surname) {
					cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
						<< "|  " << setw(12) << d[i]._author.surname
						<< "|  " << setw(15) << d[i]._date.day
						<< "|     " << setw(7) << d[i]._date.month
						<< "|  " << setw(9) << d[i]._date.year
						<< "  |" << setw(18)
						<< d[i]._genre.genre << "|  "
						<< setw(34) << d[i]._name.name
						<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
				}
			}
			break;
		}
		case 3:
		{
			int year, secondYear;
			cout << "Введіть початкову дату(Рік):" << endl;
			cin >> year;
			cout << "Введіть кінцеву дату(Рік):" << endl;
			cin >>secondYear;
			Table();
			for (int i = 0; i < n; i++) {
				if (d[i]._date.year >= year && d[i]._date.year <= secondYear){
					cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
						<< "|  " << setw(12) << d[i]._author.surname
						<< "|  " << setw(15) << d[i]._date.day
						<< "|     " << setw(7) << d[i]._date.month
						<< "|  " << setw(9) << d[i]._date.year
						<< "  |" << setw(18)
						<< d[i]._genre.genre << "|  "
						<< setw(34) << d[i]._name.name
						<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
				}
			}
			break;
		}
		case 4:
		{
			string genre;
			cout << "Введіть жанр:" << endl;
			cin >> genre;
			Table();
			for (int i = 0; i < n; i++) {
				if (d[i]._genre.genre == genre) {
					cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
						<< "|  " << setw(12) << d[i]._author.surname
						<< "|  " << setw(15) << d[i]._date.day
						<< "|     " << setw(7) << d[i]._date.month
						<< "|  " << setw(9) << d[i]._date.year
						<< "  |" << setw(18)
						<< d[i]._genre.genre << "|  "
						<< setw(34) << d[i]._name.name
						<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
				}
			}
			break;
		}
		case 5:
		{
			string restoration;
			cout << "Чи портребує реставрації:" << endl;
			cin >> restoration;
			Table();
			for (int i = 0; i < n; i++) {
				if (d[i]._restoration.needRestoration == restoration) {
					cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
						<< "|  " << setw(12) << d[i]._author.surname
						<< "|  " << setw(15) << d[i]._date.day
						<< "|     " << setw(7) << d[i]._date.month
						<< "|  " << setw(9) << d[i]._date.year
						<< "  |" << setw(18)
						<< d[i]._genre.genre << "|  "
						<< setw(34) << d[i]._name.name
						<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
				}
			}
		}
		}
	}
}

void DataSorting(Picture* (&d), int n)
{
	Picture buf;
	int item;
	
	for (int counter = 1; counter < n; counter++)
	{
		buf = d[counter]; //  записуємо в тимчасову змінну поточне значення елементу масиву
		item = counter - 1; // запамятовуємо індекс попереднього елементу масиву
		while (item >= 0 && d[item]._genre.genre > buf._genre.genre) // поки індекс не дорівнює 0 і попередній елемент масиву більший поточного
		{
			d[item + 1] = d[item]; // перестановка елементів масиву
			d[item] = buf;
			item--;
		}
	}

	//for (int counter = 1; counter < n; counter++)
	//{
	//	buf = d[counter]; //  записуємо в тимчасову змінну поточне значення елементу масиву
	//	item = counter - 1; // запамятовуємо індекс попереднього елементу масиву
	//	while (item >= 0 && strcmp(d[item]._genre.genre,  buf._genre.genre)) // поки індекс не дорівнює 0 і попередній елемент масиву більший поточного
	//	{
	//		d[item + 1] = d[item]; // перестановка елементів масиву
	//		d[item] = buf;
	//		item--;
	//	}
	//}


	cout << "Дані відсортовано!" << endl;
	Table();
	for (int i = 0; i < n; i++) {
		cout << left << "|" << setw(3) << i + 1 << "|  " << setw(20) << d[i]._author.name
			<< "|  " << setw(12) << d[i]._author.surname
			<< "|  " << setw(15) << d[i]._date.day
			<< "|     " << setw(7) << d[i]._date.month
			<< "|  " << setw(9) << d[i]._date.year
			<< "  |" << setw(18)
			<< d[i]._genre.genre << "|  "
			<< setw(34) << d[i]._name.name
			<< "|     " << setw(16) << d[i]._restoration.needRestoration << "  |" << endl;
	}
}

void SaveData(Picture* d, int n, string fileName) {
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._author.name << endl;
			record << d[i]._author.surname << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year << endl;

			record << d[i]._genre.genre << endl;

			record << d[i]._name.name << endl;
			if (i < n - 1) {
				record << d[i]._restoration.needRestoration << endl;
			}
			else {
				record << d[i]._restoration.needRestoration;
			}
		}
	}
	else
		cout << "Помилка відкриття файлу" << endl;
	record.close();
}
