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
template <class T>
class Num {
	T num;
public:
	Num()
	{
		num = 0;
	}
	Num(T &a)
	{
		num = a;
	}
	void fu() { cout << "Number: " << num << endl; }
	Num<T> operator/(Num <T> &a);
	Num<T>& operator=(const Num<T> &a);
	template<class T> friend istream& operator>>(istream & in, Num<T> & a);
};
#include "Num_cl.tpp"


