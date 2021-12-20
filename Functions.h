#pragma once
#include <iostream>//біблотека для потоку вводу і виводу
#include <fstream> // для роботи з файлами
#include <string> // для роботи з рядками
#include <iomanip> // для функції setw
#include <Windows.h> // для системних функцій

using namespace std;

struct nameOfPicture {
	string name;
};

struct Author {
	string name,
		surname;
};

struct Date {
	int day,
		month,
		year;
};

struct Genre {
	string genre;
};

struct needRestoration {
	string needRestoration;
};

struct Picture {
	nameOfPicture _name;
	Author _author;
	Date _date;
	Genre _genre;
	needRestoration _restoration;
};

void Table(); //друкування заголовку таблиці
void DataInput(Picture* (&d), int& n); //ввід даних вручну
void ReadingData(Picture* (&d), int& n, string fileName); //читання даних з файлу
void Print(Picture* d, int n); // друкування даних
void DataChange(Picture* (&d), int n);  // зміна даних
void DeleteData(Picture* (&d), int& n); // видалення даних
void AddData(Picture* (&d), int& n); // додавання даних в поч і кінець файлу
void DataSorting(Picture* (&d), int n); //сортування даних
void Calculating(Picture* d, int n); // розрахунок 
void Query(Picture* d, int n); // вибірка
void SaveData(Picture* d, int n, string fileName); // збереження даних
void Copy(Picture* (&d_n), Picture* (&d_o), int n); // Копіювання всіх елементів