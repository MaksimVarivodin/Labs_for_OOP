#pragma once
/*

ЛАБОРАТОРНАЯ РАБОТА №9Б
Создать ассоциативный массив (телефонная книжка) на основе двух классов 
(NAME -> first and NUMBER -> second).
Перегрузить оператор < в классе NAME для упорядочивания по имени.
В каждом классе:
– ф. вывода get();
Организовать map<> из 3-5 элементов.
Напечатать весь список.
Осуществить поиск по ключу (по имени).
Напечатать всех, у кого фамилия начинается на определенную букву(попробовать).
Удалить всех, у кого фамилия начинается на определенную букву(попробовать).

*/

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <map>
using namespace std;
void Enter_check(string & a) {
	string b;
	getline(cin, b);
	a = b;
}

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void С_gray(const string & a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	cout << a;
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}

void Choose(const string & a)
{
	cout << setw(11) << "--> ";
	С_gray(a);
	cout << endl;
}

int Menu_show(const string  arr[], const int & size)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//получение хендла
	CONSOLE_CURSOR_INFO cursor = { 100,false };//число от 1 до 100 размер курсора в процентах; false\true - видимость
	SetConsoleCursorInfo(hCons, &cursor);
	bool done = false;
	int choice;
	int pos = 1;
	for (;;)
	{
		system("cls");
		cout << setw(19) << arr[0] << endl;
		int i = 1;
		for (; i < pos; i++)
			cout << setw(11 + arr[i].length()) << arr[i] << endl;
		Choose(arr[pos]);
		i++;
		for (; i < size; i++)
			cout << setw(11 + arr[i].length()) << arr[i] << endl;

		choice = _getch();
		if (choice == 224)
			choice = _getch();


		if (choice == 13)
			// enter
		{
			system("cls");
			return pos;
		}

		if (choice == 27 || done == true)
		{
			done = false;
			return 0;
		}

		switch (choice) {
		case 72:
			if (pos == 1)	pos = size - 1;
			else pos--;
			break;
		case 80:
			if (pos == size - 1)pos = 1;
			else pos++;
			break;
		}
	}

}
class Name;
bool operator>(Name& o, Name& t);
bool operator<(Name& o, Name& t);
class Name {
	string name;
public:
	Name(const string & a = "")
	{
		name = a;
	}	
	string GETname()const  { return this->name; }
	friend bool operator>(Name& o, Name& t);
	friend bool operator<(Name& o, Name& t);
};
bool operator>(const Name& o, const Name& t) { return o.GETname() > t.GETname(); }
bool operator<(const Name& o, const Name& t) { return o.GETname() < t.GETname(); }

class Number {
	int  num;
public:
	Number(const int & a = 0 )
	{
		num= a;
	}
	int GETnum() { return this->num; }
};