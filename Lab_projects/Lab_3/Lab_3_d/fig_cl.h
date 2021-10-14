#pragma once
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
class Figure {
	int x, y, z;
public:
	Figure() 
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Figure(const int & x0)
	{
		x = x0;		
		y = 0;
		z = 0;
	}
	Figure(const int & x0, const int& y0)
	{
		x = x0;
		y = y0;
		z = 0;
	}
	Figure(const int & x0, const int& y0, const int& z0)
	{
		x = x0;
		y = y0;
		z = z0;
	}
	virtual void show(const int & x0 = 0, const int& y0 = 0, const int& z = 0) = 0;
	int ret_x() const { return x; }
	int ret_y() const { return y; }
	int ret_z() const { return z; }
	void setter(const int & x0, const int& y0, const int& z0) {
		x = x0;
		y = y0;
		z = z0;
	} 
	
};
class Figure1 :virtual public Figure {
	
public:
	Figure1() :Figure{} {};
	Figure1(const int & x0, const int& y0, const int &z0) :Figure{ x0, y0, z0} {};
   void show(const int & x0, const int& y0, const int& z0)override;
};
class Figure2 :virtual public Figure {	
public:
	Figure2() :Figure{} {};
	Figure2(const int & x0, const int& y0) :Figure{ x0, y0 } {};
   void show(const int & x0, const int& y0, const int& z0 = 0) override;
};
class Figure3 :virtual public Figure {
public:
	Figure3() :Figure{} {};
	Figure3(const int & x0) :Figure{ x0} {};
   void show(const int & x0, const int& y0 = 0, const int& z0 = 0) override;
};