#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Book {
protected:
	string a_name;
	string b_name;
	int pages;
public:
	Book(const string &a, const string & b, const int & p)
	{
		a_name = a;
		b_name = b;
		pages = p;
	}
	Book() :Book{"", "", 0} {};
	void show();
	string nm_ret() {
		return b_name;
	}
};
class Library: public Book {
	bool present;
	int cat;
public:
	Library() : Book{ "", "", 0 }  {
		cat = 0;
		present = false;
	}
	Library(const string &a, const string & b, const int & p, const int & c, const bool & f) :Book{ a,b, p } {
		cat = c;
		present = f;
	}
	bool is_present() {
		return present ? true : false;
	}
	void take_book() {
		cout << cat <<" - Book taken." << endl;
		present = false;
	}
	void ret_book() {
		cout << cat << " - Book returned." << endl;
		present = true;
	}
	void show();
};
void print( Library* a, const int & size);