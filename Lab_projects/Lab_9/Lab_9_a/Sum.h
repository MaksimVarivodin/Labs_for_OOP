#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
class Sum
{
	int a, b, s;
public:
	Sum(const int & a0 = rand()%5+ 1, const int &b0 = rand()%5+ 1) {
		a = a0;
		b = b0;
		s = a + b;
	}
	bool operator==(const Sum& other);
	void GETs() { cout << "Sum is " << s << endl; }
	~Sum() {}
};

