#include "manuf_cl.h"
int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 3;

	man_b *mas = new man_b[size]{ { "Oracle",1,2488000000, 31.1 },
	{ "IBM", 3 , 2392000000, 29.9 },
	{ "Microsoft", 2 ,1048000000, 13.1 }
	};

	int Case = 0;
	int str_size = 0;
	for (;;) {
		cout << "Выберите метод:" << endl;
		cout << "1- Вывод" << endl;
		cout << "2- Перегрузка \"[]\"" << endl;
		cout << "3- Перегрузка \"+\"" << endl;
		cout << "4- Перегрузка \"==\"" << endl;
		cout << "5- Перегрузка \">>\"" << endl;
		cout << "6- Перегрузка \"()\"" << endl;
		cout << "7- Выход" << endl;
		cin >> Case;
		system("cls");

		switch (Case)
		{
			
		case 1:
			cout << "Вывод" << endl;
			man_b::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Перегрузка \"[]\"" << endl;
			man_b::print(mas, size);
			
			cout << endl;
			for (int i = 0; i < size; i++) {
				cout << i + 1 << " - " << mas[i][str_size] << endl;
			}
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Перегрузка \"+\"" << endl;
			man_b::resize(mas, size);
			mas[size - 1] = mas[size - 2] + mas[size - 3];
			man_b::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Перегрузка \"==\"" << endl;
			man_b::print(mas, size);
			man_b::equal(mas[size - 1], mas[size - 2]);
			man_b::equal(mas[size - 2], mas[size - 3]);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Перегрузка \">>\"" << endl;
			man_b::resize(mas, size);
			cin >> mas[size - 1];
			man_b::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Перегрузка \"()\"" << endl;
			for (int i = 0; i < size; i++)
				mas[i]("",0,0,0);
			man_b::print(mas, size);			
			system("pause");
			system("cls");
			break;
		}
		if (Case == 7)
			break;
	}
	delete[]mas;
}