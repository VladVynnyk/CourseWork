#pragma once
#include <iostream>//�������� ��� ������ ����� � ������
#include <fstream> // ��� ������ � �������
#include <string> // ��� ������ � �������
#include <iomanip> // ��� ������� setw
#include <Windows.h> // ��� ��������� �������

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

void Table(); //���������� ��������� �������
void DataInput(Picture* (&d), int& n); //��� ����� ������
void ReadingData(Picture* (&d), int& n, string fileName); //������� ����� � �����
void Print(Picture* d, int n); // ���������� �����
void DataChange(Picture* (&d), int n);  // ���� �����
void DeleteData(Picture* (&d), int& n); // ��������� �����
void AddData(Picture* (&d), int& n); // ��������� ����� � ��� � ����� �����
void DataSorting(Picture* (&d), int n); //���������� �����
void Calculating(Picture* d, int n); // ���������� 
void Query(Picture* d, int n); // ������
void SaveData(Picture* d, int n, string fileName); // ���������� �����
void Copy(Picture* (&d_n), Picture* (&d_o), int n); // ��������� ��� ��������