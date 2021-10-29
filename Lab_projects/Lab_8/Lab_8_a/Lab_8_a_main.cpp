#include "Num_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Num<double> a0;
	Num<double> b0;
	Num<double> c0;
	Num<int> a;
	Num<int> b;
	Num<int> c;
	cout << "¬ведите вещественное a0: ";
	cin >> a0;
	cout << "¬ведите вещественное b0: ";
	cin >> b0;
	cout << "a0:";
	a0.fu();
	cout<< "b0:";
	b0.fu();
	c0 = a0 / b0;
	c0.fu();
	cout << "¬ведите целое a: ";
	cin >> a;
	cout << "¬ведите целое b: ";
	cin >> b;
	cout << "a:";
	a.fu();
	cout << "b:";
	b.fu();
	c = a / b;
	c.fu();
	system("pause");
}