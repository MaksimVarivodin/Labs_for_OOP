#include "manufact_cl.h"

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
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 3;
	
	MANUFACTURER *mas = new MANUFACTURER[size]{ { "Oracle",1,2488000000, 31.1 },
	{ "IBM", 3 , 2392000000, 29.9 },
	{ "Microsoft", 2 ,1048000000, 13.1 }
	};
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
		system("cls");
		switch (Case) 
		{
		case 1:
			cout << "Вывод" << endl;
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Перегрузка \"=\"" << endl;
			MANUFACTURER::resize(mas, size);
			mas[size - 1] = mas[size - 2];
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		
		case 3:
			cout << "Перегрузка \"+\"" << endl;
			MANUFACTURER::resize(mas, size);
			mas[size - 1] = mas[size - 2] + mas[size - 3];
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Перегрузка \"==\"" << endl;
			MANUFACTURER::print(mas, size);
			MANUFACTURER::equal(mas[size - 1], mas[size - 2]);
			MANUFACTURER::equal(mas[size - 2], mas[size - 3]);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Перегрузка \">>\"" << endl;
			MANUFACTURER::resize(mas, size);
			cin >> mas[size - 1];
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		}
		if (Case == 6)
			break;
	}
	system("pause");
	delete[]mas;
}