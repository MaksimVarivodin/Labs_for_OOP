#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class DOG {
protected:
	void err_check(bool a, DOG & b);
	friend ostream & operator<< (ostream & out, const DOG & a);
	friend istream & operator>> (istream & in, DOG & a);
	int weight;
	int age;
public:
	
	DOG()
	{
		cout << "DOGGO ctor" << endl;
	}
	~DOG(){
		cout << "DOGGO dctor" << endl;
	}
	void golos() {
		cout << __FUNCTION__ << endl;
		if (weight >= 10)
			cout << "ÃÀÂ" << endl;
		else {
			cout << "ãàâ" << endl;
		}
		cout << endl;
	}
};
class SpanielD: public DOG {
protected:
	void err_check(bool a, SpanielD& b);
	string color;
	friend ostream & operator<< (ostream & out, const SpanielD & a);
	friend istream & operator>> (istream & in, SpanielD & a);
	
public:
	SpanielD()
	{
		cout << "SpanielD ctor" << endl;
	}
	~SpanielD() {
		cout << "SpanielD dctor" << endl;
	}
};
