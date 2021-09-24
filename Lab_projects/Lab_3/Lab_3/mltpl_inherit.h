#pragma once
#include <iostream>		
using namespace std;


//À¿¡Œ–¿“Œ–Õ¿ﬂ –¿¡Œ“¿ π 3
/*

 B1           B2
 private  public
       D1
public	   private
D2           D3

*/

class B1 {
	int a;
public:
	B1(const int &a0 = 0)
	{
		a = a0;
	}
	virtual void show() {
		cout << __FUNCTION__<< "" << endl;
	}
};
class B2 {
	int b;
public:
	B2(const int &b0 = 0)
	{
		b = b0;
	}
	virtual void show() {
		cout << __FUNCTION__ << "" << endl;
	}
};
class D1: private B1, public B2 {
	int c;
public:
	D1(const int & c0 = 0, const int &a0 = 0, const int &b0 = 0) :B1{ a0 }, B2{b0}
	{
		c = c0;
	}
	void show() override {
		cout << __FUNCTION__ << "" << endl;
		B1::show();
		B2::show();
	}
};
class D2: virtual public D1{
	int d;
public:
	D2(const int& d0 = 0, const int & c0 = 0, const int &a0 = 0, const int &b0 = 0) :D1{c0, a0, b0}
	{
		d = d0;
	}
	void show() override{
		cout << __FUNCTION__ << "" << endl;
		D1::show();
	}
};
class D3: virtual private D1 {
	int e;
public:
	D3(const int& e0 = 0, const int & c0 = 0, const int &a0 = 0, const int &b0 = 0) :D1{ c0, a0, b0 }
	{
		e = e0;
	}
	void show()override {
		cout << __FUNCTION__ << "" << endl;
		D1::show();
	}
};