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
int Enter_check(int & a, const int & max = 1000, const int & min = 0);
void С_gray(const string& a);
// функция которая показывает какую строку выбрали
void Choose(const string& a);
// фунция вывода любого меню(ЮИ)
int Menu_show(const string* arr, const int & size);

void add_l(string *&arr, int& size);
void read();
class MANUFACTURER {
protected:
	string company;
	short quantity;
	long long int yearSales;
	double marketPart;
public:
	MANUFACTURER(const MANUFACTURER & a) :MANUFACTURER{ a.marketPart, a.quantity, a.yearSales }
	{
		this->company = a.company;
	}
	MANUFACTURER(const string &c = "", const short & q = 0, const long long int &y = 0, const double &m = 0) :MANUFACTURER{ m, q, y }
	{
		company = c;
	}
	MANUFACTURER(const double &m, const short & q, const long long int &y) :MANUFACTURER{ q, y }
	{
		marketPart = m;
	}
	MANUFACTURER(const short & q, const long long int &y) :MANUFACTURER{ y } {
		quantity = q;
	}
	MANUFACTURER(const long long int &y) {
		yearSales = y;
	}
	MANUFACTURER& operator()(MANUFACTURER& other);
	// сеттеры
	void SetCompany(const string &c);
	void SetQuantity(const short & q);	void SetYearSales(const long  long int &y);
	void SetMarketPart(const double &m);
	// геттеры
	const string & GetCompany();
	const short & GetQuantity();
	const long long int & GetYearSales();
	const double & GetMarketPart();
	int col_count(const int& a, const int &b);
	// Потоковый вывод
	friend ostream& operator<< (ostream & out, MANUFACTURER & a);
	friend ofstream& operator<< (ofstream & out, MANUFACTURER & a);
	// Потоковый ввод
	friend istream& operator>> (istream & in, MANUFACTURER & a);
	friend ifstream& operator>> (ifstream & in, MANUFACTURER & a);
	// шапка таблицы
	void shapka();
	friend ofstream& shapkaF(ofstream &out);
	// проверка на соответствие
	bool operator==(MANUFACTURER& other);
	static bool equal(MANUFACTURER*&a, const int s, const string & Fname = "data.txt");
	// изменение размера 
	static void gener(MANUFACTURER & a);
	static void resize(MANUFACTURER*& a, int & b);
	static void clean(MANUFACTURER *&a, int & b);
	// печать
	static void print(MANUFACTURER*& a, int & b);
	static void printF(MANUFACTURER*&a, int & b, const string & Fname = "data.txt");	
	static void printFL(MANUFACTURER &a, int & c1, const string & Fname = "data.txt");
	// чтение
	static void readFL(MANUFACTURER *&a, const int & size, const int &c2, const string & Fname = "data.txt");
	static void readF(MANUFACTURER *&a, int & b, const string & Fname = "data.txt");
	// 
	static void saved_check(MANUFACTURER *&a, int & b, const string & Fname = "data.txt");
};