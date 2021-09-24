#include "../Lab_2/manufact_cl.h"
#include "../Lab_2/manufact_cl.cpp"
class man_a : public MANUFACTURER{
public:
	man_a()
	{
		company = "";
		quantity = 0;
		yearSales = 0;
		marketPart = 0;
	}
	man_a(const man_a & a) :man_a{ a.marketPart, a.quantity, a.yearSales }
	{
		this->company = a.company;
	}
	man_a(const string &c, const short & q, const long long int &y, const double &m) :man_a{ m, q, y }
	{
		company = c;
	}
	man_a(const double &m, const short & q, const long long int &y): man_a { q, y }
	{
		marketPart = m;
	}
	man_a(const short & q, const long long int &y) :man_a{ y } {
		quantity = q;
	}
	man_a(const long long int &y) {
		yearSales = y;
	}


};