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

void fill_file(const string & p = "numbs.bin");
int* read_file(const string & p = "numbs.bin", const int & size = 10);
class Array {
	int * numbs;
	int size;
	void change_arr();
	void print();
	friend int* read_file(const string & p, const int & size);
public:
	Array()
	{
		size = 10;
		numbs = read_file();
	}
	~Array() {
		delete[]numbs;
		size = 0;
	}
	void write_new_arr(const string & p = "numbs.bin");
	
};