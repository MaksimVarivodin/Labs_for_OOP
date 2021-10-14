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
	// ������������
	MANUFACTURER operator=(const MANUFACTURER & other);
	// ��������
	MANUFACTURER operator+(const MANUFACTURER & other);
	// ������������
	bool & operator==(const MANUFACTURER & other);
	// ��������� ����
	friend ostream& operator<< (ostream & out, MANUFACTURER & a);
	// ��������� �����
	friend istream& operator>> (istream & in, MANUFACTURER & a); 
};

