#include "dog_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DOG a;
	cin >> a;
	cout << "Class Dog:" << endl;
	cout << a;
	a.golos();
	SpanielD b;
	cin >> b;
	cout << "Class SpanielD" << endl;
	cout << b;
	b.golos();
	system("pause");
}