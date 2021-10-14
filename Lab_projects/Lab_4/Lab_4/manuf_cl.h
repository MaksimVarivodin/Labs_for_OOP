#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

//Лабораторная работа №2 \
Перегрузка операторов в языке С++
/*
Задание к выполнению аналогично заданию в лабораторной работе №10 (части I),
но программа должна быть составлена с использованием класса,
необходимо предусмотреть функции доступа к полям класса
(функции get() и set()) и необходимо перегрузить следующие операторы:

Присваивание;
Сложение (в случае символьных полей сложение понимается как конкатенация);
Соответствие;
Потоковый ввод;
Потоковый вывод.
*/

// Example:
/*



Oracle                         1 	               2488000000 	           31.1
IBM 	                       3 	               2392000000 	           29.9
Microsoft 	                   2 	               1048000000 	           13.1
Примечание: по данным Gartner Group за 1999г
*/

class MANUFACTURER {
protected:
	string company;
	short quantity;
	long long int yearSales;
	double marketPart;
public:
	MANUFACTURER()
	{
		company = "";
		quantity = 0;
		yearSales = 0;
		marketPart = 0;
	}
	MANUFACTURER(const MANUFACTURER & a) :MANUFACTURER{ a.marketPart, a.quantity, a.yearSales }
	{
		this->company = a.company;
	}
	MANUFACTURER(const string &c, const short & q, const long long int &y, const double &m) :MANUFACTURER{ m, q, y }
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
	// сеттеры
	void SetCompany(const string &c);
	void SetQuantity(const short & q);
	void SetYearSales(const long  long int &y);
	void SetMarketPart(const double &m);
	// геттеры
	const string & GetCompany();
	const short & GetQuantity();
	const long long int & GetYearSales();
	const double & GetMarketPart();
	int col_count(const int& a, const int &b);
	// Присваивание
	MANUFACTURER operator=(const MANUFACTURER & other);
	// Сложение
	MANUFACTURER operator+(const MANUFACTURER & other);
	// Соответствие
	bool & operator==(const MANUFACTURER & other);
	// Потоковый ввод
	friend ostream& operator<< (ostream & out, MANUFACTURER & a);
	// Потоковый вывод
	friend istream& operator>> (istream & in, MANUFACTURER & a); 
};

