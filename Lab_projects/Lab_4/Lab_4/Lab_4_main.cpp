#include "comp_cl.h"

//Лабораторная работа №2 \
Перегрузка операторов в языке С++
/*
Задание к выполнению аналогично заданию в лабораторной работе №10 (части I),
но программа должна быть составлена с использованием класса,
необходимо предусмотреть функции доступа к полям класса
(функции get() и set()) и необходимо перегрузить следующие операторы:

Присваивание;
Сложение (в случае символьных полей сложение понимается как конкатенация);
Соответствие;
Потоковый ввод;
Потоковый вывод.
*/

// Example:
/*



Oracle                         1 	               2488000000 	           31.1
IBM 	                       3 	               2392000000 	           29.9
Microsoft 	                   2 	               1048000000 	           13.1
Примечание: по данным Gartner Group за 1999г
*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	COMPANY a;
	int Case = 0;
	for (;;) {
		cout << "Выберите метод:" << endl;
		cout << "1- Вывод" << endl;
		cout << "2- Перегрузка \"=\"" << endl;
		cout << "3- Перегрузка \"+\"" << endl;
		cout << "4- Перегрузка \"==\"" << endl;
		cout << "5- Перегрузка \">>\"" << endl;
		cout << "6- Выход" << endl;
		cin >> Case;
		if (cin.fail())break;
		system("cls");
		switch (Case)
		{
		case 1:
			cout << "Вывод" << endl;
			a.print();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Перегрузка \"=\"" << endl;
			a.resize();
			a[a.r_s()] = a[a.r_s() - 1];
			a.print();
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Перегрузка \"+\"" << endl;
			a.resize();
			a[a.r_s()] = a[a.r_s() - 1] + a[a.r_s() - 2];
			a.print();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Перегрузка \"==\"" << endl;
			a.print();
			a.equal(a[a.r_s()], a[a.r_s() - 1]);
			a.equal(a[a.r_s() -1], a[a.r_s() - 2]);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Перегрузка \">>\"" << endl;
			a.resize();
			cin >> a[a.r_s()];
			a.print();
			system("pause");
			system("cls");
			break;
		}
		if (Case == 6)
			break;
	}
	system("pause");
}