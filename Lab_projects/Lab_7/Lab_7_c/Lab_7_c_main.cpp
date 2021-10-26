#include "arr_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	for (;;)
	{
		cout << "Заполнение файла" << endl;
		fill_file();
		Array a;
		a.write_new_arr();
		system("pause");
		int size = 3;
		string * menu = new string[size]{
		"Продолжить ?", 
		"1- Да", 
		"2- Нет"
		};
		if (Menu_show(menu, size) == 2) { 
			delete[]menu;
			break; 
		}
		else { delete[] menu; }
	}

}