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
	cout << "������� ������������ a0: ";
	cin >> a0;
	cout << "������� ������������ b0: ";
	cin >> b0;
	cout << "a0:";
	a0.fu();
	cout<< "b0:";
	b0.fu();
	c0 = a0 / b0;
	c0.fu();
	cout << "������� ����� a: ";
	cin >> a;
	cout << "������� ����� b: ";
	cin >> b;
	cout << "a:";
	a.fu();
	cout << "b:";
	b.fu();
	c = a / b;
	c.fu();
	system("pause");
}