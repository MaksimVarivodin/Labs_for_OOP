#include "fig_cl.h"
int main() {	
	for (;;) {
		system("cls");
		int Case = 0;
		int a0 = 0, b0 = 0, c0 = 0;
		cout << "Enter a, b, c to initialise objects:" << endl;
		cout << "P.S. : Letter to break" << endl;
		cin >> a0 >> b0 >> c0;
		if (cin.fail()) {
			break;
		}
		Figure1 a{ a0, b0, c0 };
		Figure2 b{ a0, b0 };
		Figure3 c{ a0 };
		Figure *buf= NULL;
		for (;;) {
			system("cls");
			cout << "Enter a figure, square of which you want to find:" << endl;
			cout << "1 - Triangle" << endl;
			cout << "2 - Rechtangle" << endl;
			cout << "3 - Circle" << endl;
			cout << "4 - Reenter numbers" << endl;
			cin >> Case;
			if (cin.fail() || Case == 4)break;
			switch (Case)
			{
			case 1:
				system("cls");
				cout << "1 - Triangle" << endl;
				buf = &a;
				buf->show(buf->ret_x(), buf->ret_y(), buf->ret_z());
				break;
			case 2:
				system("cls");
				cout << "2 - Rechtangle" << endl;
				buf = &b;
				buf->show(buf->ret_x(), buf->ret_y());
				break;
			case 3:
				system("cls");
				cout << "3 - Circle" << endl;
				buf = &c;
				buf->show(buf->ret_x());
				break;
			default:
				system("cls");
				cout << "Invalid number" << endl;
				break;
			}
			system("pause");
		}
	}
}