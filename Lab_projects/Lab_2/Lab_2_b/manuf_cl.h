#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

//������������ ������ �2 \
���������� ���������� � ����� �++
/*
������� � ���������� ���������� ������� � ������������ ������ �10 (����� I),
�� ��������� ������ ���� ���������� � �������������� ������,
���������� ������������� ������� ������� � ����� ������
(������� get() � set()) � ���������� ����������� ��������� ���������:

������������;
�������� (� ������ ���������� ����� �������� ���������� ��� ������������);
������������;
��������� ����;
��������� �����.
*/

// Example:
/*



Oracle                         1 	               2488000000 	           31.1
IBM 	                       3 	               2392000000 	           29.9
Microsoft 	                   2 	               1048000000 	           13.1
����������: �� ������ Gartner Group �� 1999�
*/
class man_b {
protected:
	string company;
	short quantity;
	long long int yearSales;
	double marketPart;
public:
	man_b()
	{
		company = "";
		quantity = 0;
		yearSales = 0;
		marketPart = 0;
	}
	man_b(const man_b & a) :man_b{ a.marketPart, a.quantity, a.yearSales }
	{
		this->company = a.company;
	}
	man_b(const string &c, const short & q, const long long int &y, const double &m) :man_b{ m, q, y }
	{
		company = c;
	}
	man_b(const double &m, const short & q, const long long int &y) :man_b{ q, y }
	{
		marketPart = m;
	}
	man_b(const short & q, const long long int &y) :man_b{ y } {
		quantity = q;
	}
	man_b(const long long int &y) {
		yearSales = y;
	}
	// �������
	void SetCompany(const string &c);
	void SetQuantity(const short & q);
	void SetYearSales(const long  long int &y);
	void SetMarketPart(const double &m);
	// �������
	const string & GetCompany();
	const short & GetQuantity();
	const long long int & GetYearSales();
	const double & GetMarketPart();
	int col_count(const int& a, const int &b);
	// ��������
	friend man_b operator+(const man_b & that, const man_b & other);
	// ������������
	friend bool operator==(const man_b & that, const man_b & other);
	// ��������� ����
	friend ostream& operator<< (ostream & out, man_b & a);
	// ��������� �����
	friend istream& operator>> (istream & in, man_b & a);
    // �������� []
    int operator[] (int & a);
	// �������� ()
	void operator() (const string &c, const short & q, const long long int &y, const double &m);
	static void shapka();
	static void equal(man_b a, man_b b);
	static void resize(man_b*& a, int & b);
	static void print(man_b*& a, int & b);
};
