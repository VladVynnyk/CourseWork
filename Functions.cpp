#include "Functions.h"
#include <iostream>
using std::cout;
using std::cin;
//using namespace std;
void Table()
{
	cout << "|---|----------------------|--------------|-----------------|------------|-------------|------------------|------------------------------------|-----------------------|\n";
	cout << "| � |        ��'�          |  �������    |  ���� ��������� |    ̳����  |    г�      |     ����         |           ����� �������            |�� ������� �����������|\n";
	cout << "|   |        ������        |              |                 |            |             |                  |                                    |                       |\n";
	cout << "|---|----------------------|--------------|-----------------|------------|-------------|------------------|------------------------------------|-----------------------|\n";
}

void DataInput(Picture* (&d), int& n)
{
	int num;
	cout << "������ �-�� �����" << endl;
	cin >> n;

	d = new Picture[n];

	for (int i = 0; i < n; i++) {
		cout << "������ ����� �������: " << endl;
		cin >> d[i]._name.name;
		cout << "������ ��� ������: " << endl;
		cin >> d[i]._author.name;
		cout << "������ ������� ������: " << endl;
		cin >> d[i]._author.surname;

		cout << "������ ���� ��������� �������: " << endl;
		cout << "����: " << endl;
		cin >> d[i]._date.day;
		while (true) {
			if (d[i]._date.day >= 1 && d[i]._date.day <= 31)
			{
				cout << "��� ������� ����." << endl;
				break;
			}
			else
			{
				cout << "��� ������� �� ����. ������ ��� ������." << endl;
				cin >> d[i]._date.day;
			}
		}
		cout << "̳����: " << endl;
		cin >> d[i]._date.month;
		while (true) {
			if (d[i]._date.month >= 1 && d[i]._date.month <= 12)
			{
				cout << "��� ������� ����." << endl;
				break;
			}
			else
			{
				cout << "��� ������� �� ����. ������ ��� ������." << endl;
				cin >> d[i]._date.month;
			}
		}
		cout << "г�: " << endl;
		cin >> d[i]._date.year;


		cout << "������ ���� �������: " << endl;
		cin >> d[i]._genre.genre;
		cout << "�� ������� �����������(��� ��� ͳ): " << endl;
		cin >> d[i]._restoration.needRestoration;
		while (true) {
			if (d[i]._restoration.needRestoration == "���" || d[i]._restoration.needRestoration == "ͳ") {
				cout << "��� ������� ����." << endl;
				break;
			}
			else {
				cout << "��� ������� �� ����. ������ ��� ������." << endl;
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
			cout << "��� ��������!" << endl;
		}
	}
	else
		cout << "������� �������� �����:" << endl;
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
	cout << "1 ����������� ������ ������ ������" << endl;
	cout << "2 ����������� ������ ������" << endl;
	cin >> actions;
	cout << "������ ����� �������� (�� 1 �� " << n << "):";
	cin >> _n;
	_n--;
	//�������� �� ������� ���� ��������
	if (_n >= 0 && _n < n)
	{
		if (actions == 1) {
			cout << "���� ����� ��������?" << endl
			<< "1 ��'� ���������" << endl
			<< "2 �������" << endl
			<< "3 ���� ���������" << endl
			<< "4 ̳����" << endl
			<< "5 г�" << endl
			<< "6 ����" << endl
			<< "7 �� ������� �����������(��� ��� ͳ)" << endl;
		cin >> menu;
		
			switch (menu) {
			case 1:
				cout << "������ ��'� ���������: ";
				cin >> d[_n]._author.name;
				break;
			case 2:
				cout << "������ ������� ���������: ";
				cin >> d[_n]._author.surname;
				break;
			case 3:
				cout << "������ ���� ��������� �������: ";
				cin >> d[_n]._date.day;
				while (true) {
					if (d[_n]._date.day >= 1 && d[_n]._date.day <= 31)
					{
						cout << "��� ������� ����." << endl;
						break;
					}
					else
					{
						cout << "��� ������� �� ����. ������ ��� ������." << endl;
						cin >> d[_n]._date.day;
					}
				}
				break;
			case 4:
				cout << "������ ����� ��������� �������: ";
				cin >> d[_n]._date.month;
				while (true) {
					if (d[_n]._date.month >= 1 && d[_n]._date.month <= 12)
					{
						cout << "��� ������� ����." << endl;
						break;
					}
					else
					{
						cout << "��� ������� �� ����. ������ ��� ������." << endl;
						cin >> d[_n]._date.month;
					}
				}
				break;
			case 5:
				cout << "������ �� ��������� �������: ";
				cin >> d[_n]._date.year;
				break;
			case 6:
				cout << "������ ���� �������: ";
				cin >> d[_n]._genre.genre;
				break;
			case 7:
				cout << "�� ������� �����������: ";
				cin >> d[_n]._restoration.needRestoration;
				while (true) {
					if (d[_n]._restoration.needRestoration == "���" || d[_n]._restoration.needRestoration == "ͳ") {
						cout << "��� ������� ����." << endl;
						break;
					}
					else {
						cout << "��� ������� �� ����. ������ ��� ������." << endl;
						cin >> d[_n]._restoration.needRestoration;
					}
				}
				break;
			}
		}
	
		if (actions == 2) {
			cout << "������ ����� �������: ";
			cin >> d[_n]._name.name;
			cout << "������ ��'� ���������: ";
			cin >> d[_n]._author.name;
			cout << "������ ������� ���������: ";
			cin >> d[_n]._author.surname;

			cout << "������ ����: ";
			cout << "������ ����: ";
			cin >> d[_n]._date.day;
			while (true) {
				if (d[_n]._date.day >= 1 && d[_n]._date.day <= 31)
				{
					cout << "��� ������� ����." << endl;
					break;
				}
				else
				{
					cout << "��� ������� �� ����. ������ ��� ������." << endl;
					cin >> d[_n]._date.day;
				}
			}
			cout << "������ �����: ";
			cin >> d[_n]._date.month;
			while (true) {
				if (d[_n]._date.month >= 1 && d[_n]._date.month <= 12)
				{
					cout << "��� ������� ����." << endl;
					break;
				}
				else
				{
					cout << "��� ������� �� ����. ������ ��� ������." << endl;
					cin >> d[_n]._date.month;
				}
			}
			cout << "������ ��: ";
			cin >> d[_n]._date.year;

			cout << "������ ����:";
			cin >> d[_n]._genre.genre;

			cout << "�� ������� �����������(��� ��� ͳ): " << endl;
			cin >> d[_n]._restoration.needRestoration;
			while (true) {
				if (d[_n]._restoration.needRestoration == "���" || d[_n]._restoration.needRestoration == "ͳ") {
					cout << "��� ������� ����." << endl;
					break;
				}
				else {
					cout << "��� ������� �� ����. ������ ��� ������." << endl;
					cin >> d[_n]._restoration.needRestoration;
				}
			}
		}
		system("cls");
		cout << "��� ������!" << endl;
	}
	else
		cout << "����� �������� �� ����" << endl;
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
	cout << "������ ����� �������� (�� 1 �� " << n << "):";
	cin >> _n;
	_n--;
	system("cls");
	//�������� �� ������� ��������� ��������
	if (_n >= 0 && _n < n) {
		Picture* buf = new Picture[n];
		Copy(buf, d, n);
		--n;
		d = new Picture[n];

		int q = 0;
		//������������ ��� ��� �� ���������
		for (int i = 0; i <= n; i++)
		{
			if (i != _n) {
				d[q] = buf[i]; // ������������� ������ q ���� ��, � ���. ����� �������� �����, �� � �����������
				++q;
			}
		}
		system("sys");
		delete[] buf;
		cout << "��� ��������" << endl;
	}
	else
		cout << "����� ������� �� ����" << endl;
}

void AddData(Picture* (&d), int& n)
{
	Picture* buf;
	buf = new Picture[n];

	Copy(buf, d, n);

	n++;
	d = new Picture[n];

	Copy(d, buf, --n);

	cout << "������ ����� �������: " << endl;
	cin >> d[n]._name.name;
	cout << "������ ��� �� ������� ������: " << endl;
	cin >> d[n]._author.name >> d[n]._author.surname;
	cout << "������ ���� ��������� �������: " << endl;
	cout << "����: " << endl;
	cin >> d[n]._date.day;
	while (true) {
		if (d[n]._date.day >= 1 && d[n]._date.day <= 31)
		{
			cout << "��� ������� ����." << endl;
			break;
		}
		else
		{
			cout << "��� ������� �� ����. ������ ��� ������." << endl;
			cin >> d[n]._date.day;
		}
	}
	cout << "̳����: " << endl;
	cin >> d[n]._date.month;
	while (true) {
		if (d[n]._date.month >= 1 && d[n]._date.month <= 12)
		{
			cout << "��� ������� ����." << endl;
			break;
		}
		else
		{
			cout << "��� ������� �� ����. ������ ��� ������." << endl;
			cin >> d[n]._date.month;
		}
	}

	cout << "г�: " << endl;
	cin >> d[n]._date.year;

	cout << "������ ���� �������: " << endl;
	cin >> d[n]._genre.genre;

	cout << "�� ������� �����������(��� ��� ͳ): " << endl;
	cin >> d[n]._restoration.needRestoration;
	while (true) {
		if (d[n]._restoration.needRestoration == "���" || d[n]._restoration.needRestoration == "ͳ") {
			cout << "��� ������� ����." << endl;
			break;
		}
		else {
			cout << "��� ������� �� ����. ������ ��� ������." << endl;
			cin >> d[n]._restoration.needRestoration;
		}
	}
	system("cls");
	cout << "��� ������" << endl;
	delete[] buf;
}

void Calculating(Picture* d, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (d[i]._genre.genre == "�������") {
			count++;
		}
	}
	cout << "ʳ������ ��������: "<< count << endl;
}


void Query(Picture* d, int n) {
	int menu;
	int actions;
	cout << "1 ������ ������, �� ���������� ����������� �� ������� � �������� ������" << endl;
	cout << "2 ������ �� ������ ����" << endl;
	cin >> menu;
	Table();
	if (menu == 1) {
		for (int i = 0; i < n; i++) {
			if (d[i]._date.year >= 1901 && d[i]._date.year <= 2000) {
				if (d[i]._restoration.needRestoration == "���") {
					
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
		cout << "�� ����� ���� ������?" << endl
			<< "1 ��'� ���������" << endl
			<< "2 �������" << endl
			<< "3 г�(��������)" << endl
			<< "4 ����" << endl
			<< "5 �� ������� �����������(��� ��� ͳ)" << endl;
		cin >> actions;
		switch (actions) {
		case 1:
		{
			cout << "������ ��'� ���������" << endl;
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
			cout << "������ ������� ���������" << endl;
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
			cout << "������ ��������� ����(г�):" << endl;
			cin >> year;
			cout << "������ ������ ����(г�):" << endl;
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
			cout << "������ ����:" << endl;
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
			cout << "�� �������� �����������:" << endl;
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
		buf = d[counter]; //  �������� � ��������� ����� ������� �������� �������� ������
		item = counter - 1; // ������������ ������ ������������ �������� ������
		while (item >= 0 && d[item]._genre.genre > buf._genre.genre) // ���� ������ �� ������� 0 � ��������� ������� ������ ������ ���������
		{
			d[item + 1] = d[item]; // ������������ �������� ������
			d[item] = buf;
			item--;
		}
	}

	//for (int counter = 1; counter < n; counter++)
	//{
	//	buf = d[counter]; //  �������� � ��������� ����� ������� �������� �������� ������
	//	item = counter - 1; // ������������ ������ ������������ �������� ������
	//	while (item >= 0 && strcmp(d[item]._genre.genre,  buf._genre.genre)) // ���� ������ �� ������� 0 � ��������� ������� ������ ������ ���������
	//	{
	//		d[item + 1] = d[item]; // ������������ �������� ������
	//		d[item] = buf;
	//		item--;
	//	}
	//}


	cout << "��� �����������!" << endl;
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
		cout << "������� �������� �����" << endl;
	record.close();
}
