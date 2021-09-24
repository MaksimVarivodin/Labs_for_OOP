#include "manuf_cl.h"
void man_b::SetCompany(const string & c)
{
	this->company = c;
}

void man_b::SetQuantity(const short & q)
{
	this->quantity = q;
}

void man_b::SetYearSales(const long long int & y)
{
	this->yearSales = y;
}

void man_b::SetMarketPart(const double & m)
{
	this->marketPart = m;
}

const string & man_b::GetCompany()
{
	// TODO: insert return statement here
	return this->company;
}

const short & man_b::GetQuantity()
{
	// TODO: insert return statement here
	return this->quantity;
}

const long long int & man_b::GetYearSales()
{
	// TODO: insert return statement here
	return this->yearSales;
}

const double & man_b::GetMarketPart()
{
	// TODO: insert return statement here
	return this->marketPart;
}

int man_b::col_count(const int & a, const int & b)
{
	// a - размер строки, в - размер колонки
	int c = a + (b - a) / 2;
	return c;
}


ostream& operator<< (ostream & out, man_b & a)
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
istream& operator>> (istream & in, man_b & a)
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

int man_b::operator[](int & a)
{
	a = this->company.length();
	return a;
}

void man_b::operator()(const string & c = "", const short & q = 0, const long long int & y = 0, const double & m = 0)
{
	company = c;
	marketPart = m;
	quantity = q;
	yearSales = y;
}

void man_b::shapka()
{
	cout << "  ________________________________________________________________________________________\n";
	cout << " /                               Фирмы - производители СКБД                               \\\n";
	cout << " ------------------------------------------------------------------------------------------\n";
	cout << "|       Фирма       | Количество. продуктов  | Годовой объем продажи ($) | Часть рынка (%) |\n";
	cout << " ------------------------------------------------------------------------------------------\n";
}
void man_b::equal(man_b a, man_b b) {
	cout << endl;
	cout << a;
	cout << "и" << endl;
	cout << b;
	if (a == b) {
		cout << "равны " << endl;
	}
	else
		cout << "не равны " << endl;
}
void man_b::resize(man_b*& a, int & b) {
	man_b* new_a = new man_b[b + 1];
	if (b > 0) {
		for (int i = 0; i < b; i++)
			new_a[i] = a[i];
	}
	delete[]a;
	a = new_a;
	b++;
	new_a = nullptr;
}
void man_b::print(man_b*& a, int & b)
{
	shapka();
	for (int i = 0; i < b; i++)
		cout << a[i];
}

 bool operator==(const man_b & that, const man_b & other) {
	 bool eq = true;
	 if (that.company != other.company)
		 eq = false;
	 if (that.marketPart != other.marketPart)
		 eq = false;
	 if (that.quantity != other.quantity)
		 eq = false;
	 if (that.yearSales != other.yearSales)
		 eq = false;
	 return eq;
 }
 man_b operator+(const man_b & that, const man_b & other) {
	 man_b A{ that };
	 A.company += other.company;
	 A.marketPart += other.marketPart;
	 A.quantity += other.quantity;
	 A.yearSales += other.yearSales;
	 return A;
 }