#include "arr_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	for (;;)
	{
		cout << "���������� �����" << endl;
		fill_file();
		Array a;
		a.write_new_arr();
		system("pause");
		int size = 3;
		string * menu = new string[size]{
		"���������� ?", 
		"1- ��", 
		"2- ���"
		};
		if (Menu_show(menu, size) == 2) { 
			delete[]menu;
			break; 
		}
		else { delete[] menu; }
	}

}