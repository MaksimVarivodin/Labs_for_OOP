#include "vuz_cl.h"

int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (;;) {
		system("cls");
		int quantity;
		cout << "������� ���������� �����������(<0 ��� ����� -> break;)" << endl;
		cout << "����������->";
		cin >> quantity;
		if (cin.fail() || quantity <= 0) break;
		Vuz a{quantity};
		system("cls");
		a.print();		
		a.youngsters();
		a.low_ac_performance();
		system("pause");
		a.enul();
	}	
	
}