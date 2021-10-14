#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class B {
protected:
	int x;
public:
	void show() {
		cout << x << " ";
	}
	virtual void operator()(const int & x0 = 0);
	int ret_X() { return x; }
};
class P1 : public B {
public:
	void operator()(const int & x0)override;
};
class P2 :public P1 {
public:
	void operator()(const int & x0)override;
};