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
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	COMPANY a;

	int Case = 0,num = 0 ;
	for (;;) {
		cout << "Выберите метод:" << endl;
		cout << "1- Вывод" << endl;
		cout << "2- Перегрузка \"=\"" << endl;
		cout << "3- Перегрузка \"+\"" << endl;
		cout << "4- Перегрузка \"==\"" << endl;
		cout << "5- Перегрузка \">>\"" << endl;
		cout << "6- Вывод элемента массива по введеноому индексу" << endl;
		cout << "7- Удаление последнего" << endl;
		cout << "8- Сортировка" << endl;
		cout << "9- Выход" << endl;
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
		case 6:
			cout << "Вывод элемента массива по введеноому индексу" << endl;		
			cin >> num;
			cout << a[num];
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Удаление последнего" << endl;
			a.del();
			a.print();
			cout << "Удалено" << endl;
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "Сортировка" << endl;
			a.sort();
			a.print();
			system("pause");
			system("cls");
			break;
		}
		if (Case == 9)
		{
			system("pause");
			break;
		}
	}
}