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
// создает файл со случайными вещественными числами
void create_file(const string & p = "real_numbs.txt");

class Comp {
	static Comp* p;
	static int size;
	double num;	
	double num2;
	static void add(const double & val1 = 0, const double & val2 = 0);
	static void del();
public:
	Comp()
	{
		num = 0;
	}
	Comp(const double& a)
	{
		num = a;
	}
	void operator()(const double& a) {
		num = a;
	}
	static void write(const string &p = "res_comp.txt");
	static void read(const string &p = "real_numbs.txt");
	static void print();
	static void clean();
	Comp& operator= (const Comp& other);
};

