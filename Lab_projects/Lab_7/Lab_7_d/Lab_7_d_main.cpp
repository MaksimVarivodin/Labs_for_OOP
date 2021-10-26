#include "manuf_cl.h"
int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int s = 3;
	MANUFACTURER *mas = new MANUFACTURER[s]{ { "Oracle",1,2488000000, 31.1 },
	{ "IBM", 3 , 2392000000, 29.9 },
	{ "Microsoft", 2 ,1048000000, 13.1 }
	};
	for (;;) {

		int size = 8;
		string * menu = new string[size]{
			"МЕНЮ", 
			"1- Печать таблицы",
			"2- Добавление элемента",
			"3- Добавление элемента в файл",
			"4- Чтение элемента из файла", 
			"5- Сохранение таблицы в файл", 
			"6- Восстановление таблицы из файла", 
			"7- Выход"
		};
		int Case = Menu_show(menu, size);
		int s1 = 0;
		MANUFACTURER buf1;
		
		MANUFACTURER *buf2 = NULL;
		int s2 = 0;

		switch (Case) 
		{
		case 1: 
			MANUFACTURER::print(mas, s);
			break;
		case 2: 
			MANUFACTURER::resize(mas, s);
			MANUFACTURER::gener(mas[s - 1]);
			break;
		case 3:			
			MANUFACTURER::gener(buf1);
			MANUFACTURER::printFL(buf1, s);
			break;
		case 4:
			MANUFACTURER::resize(mas, s);
			MANUFACTURER::readF(buf2, s2);
			MANUFACTURER::print(buf2, s2);
			cout<< endl << "Введите какой элемент из файла считать: " << endl;
			cout << "(по порядку от 1 до "<< s2 <<")";
			if (s2 == 0) { 
				s--;
				MANUFACTURER::resize(mas, s);
				cout << "Недостаточно элементов в файле" << endl;
				break; 
			}
			else {
				Enter_check(s1, size);
				s1--;
			}		
			MANUFACTURER::readFL(mas, s, s1);
			break;
		case 5: 
			MANUFACTURER::printF(mas, s);
			break;
		case 6:
			MANUFACTURER::readF(mas, s);
			break;
		}
		delete[]buf2;
		delete[] menu;
		if (Case == 7) {
			MANUFACTURER::saved_check(mas, s);
			delete[] mas;
			break; 
		}
		cout << endl;
		system("pause");
		system("cls");


	}
}