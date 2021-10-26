#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
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
void С_gray(const string& a);
// функция которая показывает какую строку выбрали
void Choose(const string& a);
// фунция вывода любого меню(ЮИ)
int Menu_show(const string* arr, const int & size);

class Country;
int Enter_check(int & a, const int & max = 1000, const int & min = 0);
void Shapka();
void Print(Country* World, const int & size);
void Sort(Country* World, const int & size);
class Country {
	string name;
	string capital;
	int population;
	int area;
	public:
	Country(){name = "";
		capital = "";
		population = 0;
		area = 0;}
	string GETname() {
		return name;
	}
	string GETcapital() {
		return capital;
	}
	int GETpopulation() {
		return population;
	}
	int GETarea() {
		return area;
	}
	void operator()(const string & n, const string & c, const int & p, const int & a );
	friend void Print(Country* World, const int & size);
	friend void Sort(Country* World, const int & size);
};


