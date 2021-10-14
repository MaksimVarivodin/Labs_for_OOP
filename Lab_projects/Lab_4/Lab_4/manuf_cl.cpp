#include "manuf_cl.h"

void MANUFACTURER::SetCompany(const string & c)
{
	this->company = c;
}

void MANUFACTURER::SetQuantity(const short & q)
{
	this->quantity = q;
}

void MANUFACTURER::SetYearSales(const long long int & y)
{
	this->yearSales = y;
}

void MANUFACTURER::SetMarketPart(const double & m)
{
	this->marketPart = m;
}

const string & MANUFACTURER::GetCompany()
{
	// TODO: insert return statement here
	return this->company;
}

const short & MANUFACTURER::GetQuantity()
{
	// TODO: insert return statement here
	return this->quantity;
}

const long long int & MANUFACTURER::GetYearSales()
{
	// TODO: insert return statement here
	return this->yearSales;
}

const double & MANUFACTURER::GetMarketPart()
{
	// TODO: insert return statement here
	return this->marketPart;
}

int MANUFACTURER::col_count(const int & a, const int & b)
{
	// a - размер строки, в - размер колонки
	int c = a + (b - a) / 2;
	return c;
}

MANUFACTURER MANUFACTURER::operator=(const MANUFACTURER & other)
{
	// TODO: insert return statement here
	this->company = other.company;
	this->yearSales = other.yearSales;
	this->marketPart = other.marketPart;
	this->quantity = other.quantity;
	return *this;
}

MANUFACTURER MANUFACTURER::operator+(const MANUFACTURER & other)
{
	// TODO: insert return statement here

	MANUFACTURER A{ *this };
	A.company += other.company;
	A.marketPart += other.marketPart;
	A.quantity += other.quantity;
	A.yearSales += other.yearSales;
	return A;
}

bool & MANUFACTURER::operator==(const MANUFACTURER & other)
{
	// TODO: insert return statement here
	bool eq = true;
	if (this->company != other.company)
		eq = false;
	if (this->marketPart != other.marketPart)
		eq = false;
	if (this->quantity != other.quantity)
		eq = false;
	if (this->yearSales != other.yearSales)
		eq = false;
	return eq;
}

ostream& operator<< (ostream & out, MANUFACTURER & a)
{
	// раземеры колонок
	int COL1 = 20,
		COL2 = 25,
		COL3 = 28,
		COL4 = 18;
	string f = to_string(a.marketPart * 10 / 10);

	// размеры текстов
	int txt1 = a.company.length(),
		txt2 = to_string(a.quantity).length(),
		txt3 = to_string(a.yearSales).length(),
		txt4 = f.length() - 4;
	// размер сетва для каждой колонки
	int col1 = a.col_count(txt1, COL1),
		col2 = a.col_count(txt2, COL2),
		col3 = a.col_count(txt3, COL3),
		col4 = a.col_count(txt4, COL4);

	cout << "|" << setw(col1) << a.GetCompany() << setw(COL1 - col1) << "|";
	cout << setw(col2) << a.GetQuantity() << setw(COL2 - col2) << "|";
	cout << setw(col3) << a.GetYearSales() << setw(COL3 - col3) << "|";
	cout << setw(col4) << a.GetMarketPart() << setw(COL4 - col4) << "|" << endl;
	cout << " ------------------------------------------------------------------------------------------\n";
	return out;
}
istream& operator>> (istream & in, MANUFACTURER & a)
{
	string e;
	short b;
	long long c;
	double d;
	cout << "Company: ";
	cin >> e;
	a.SetCompany(e);
	cout << "Quantity: ";
	cin >> b;
	a.SetQuantity(b);
	if (b <= SHRT_MAX && b >= 0) {
		a.SetQuantity(b);
	}
	else
		a.SetQuantity(0);
	cout << "YearSales: ";
	cin >> c;
	if (c <= LLONG_MAX && c >= 0) {
		a.SetYearSales(c);
	}
	else
		a.SetYearSales(0);
	cout << "MarketPart: ";
	double n = 1.7*(10 ^ 308);

	cin >> d;
	if (d <= n && d >= 0)
	{
		a.SetMarketPart(d);
	}
	else a.SetMarketPart(0);
	return in;
}


