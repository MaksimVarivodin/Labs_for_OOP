#include "Comp_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	create_file();
	system("pause");
	for (;;) {
	 
		Comp::read();
		Comp::print();
		cout << endl;
		Comp::write();
		remove("real_numbs.txt");
		Comp::clean();
		int size = 3;
		cout << endl;
		system("pause");
		string * menu = new string[size]{
			"Продолжить?",
			"1- да",
			"2- нет"
		};
		if (Menu_show(menu, size) == 2) {
			delete[]menu;
			break;
		}
		else { delete[]menu; }
			
	}	
}