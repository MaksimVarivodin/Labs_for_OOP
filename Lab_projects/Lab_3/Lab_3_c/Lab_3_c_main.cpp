#include "filt_cl.h"
int main() {
	srand(time(0));
	for (;;) {
		system("cls");
		int cont;
		int size = 100;
		B* a = new B[size];
		P1* b = new P1[size];
		P2* d = new P2[size];
		P2* c = new P2[size];

		for (int i = 0; i < size; i++)
		{
			a[i]();
			b[i](a[i].ret_X());
			d[i](a[i].ret_X());
			c[i](b[i].ret_X());
		}
		cout << "Initial array: " << endl;
		for (int i = 0; i < size; i++) {
			if (i % 25 == 0)
				cout << endl;
			a[i].show();			
		}
			
		cout << endl;
		cout << endl<< "init_arr % 7 == 3: " << endl;
		for (int i = 0; i < size; i++) {
			if (i % 25 == 0)
				cout << endl;
			b[i].show();
		}
			
		cout << endl;
		cout << endl << "derivative_ arr % 5 == 2: " << endl;
		for (int i = 0; i < size; i++) {
			if (i % 25 == 0)
				cout << endl;
			d[i].show();
		}
		cout << endl;
		cout << endl << "derivative_ arr % 5 == 2 + init_arr % 7 == 3: " << endl;
		for (int i = 0; i < size; i++) {
			if (i % 25 == 0)
				cout << endl;
			c[i].show();
		}
		system("pause");
		delete[]a;
		delete[]b;
		delete[]c;
		cout << "Continue?" << endl;
		cout << "1 - Yes" << endl;
		cout << "2 - No" << endl;
		cin >> cont;
		if (cont != 1 || cin.fail())
			break;
	}
		
}