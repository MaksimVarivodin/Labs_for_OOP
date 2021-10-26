#include "fline_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (;;) {
		system("cls");
		cout << "Введите строку: ";
		string buf;
		getline(cin, buf);
		Fline a{ buf };	
		a.write();
		a.show();
		int size = 3;
		system("pause");
		string* menu = new string[3]{
		"Продолжить?", 
		"1- Да",
		"2- Нет"
		};
		if (Menu_show(menu, size) == 2) {
			delete[]menu;
			break;
		}
		else
			delete[]menu;
	}
}