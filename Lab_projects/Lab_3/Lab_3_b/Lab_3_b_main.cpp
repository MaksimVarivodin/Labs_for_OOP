#include "lib_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 3;
	Library* a = new Library[size];
	for (int i = 0; i < size; i++) {
		string a1 = "Autor"+ to_string(i+1);
		string a2 = "Book" + to_string(i+1);
		int c = i + 1;
		int n = c * 100;
		bool f = i % 2 == 0 ? true: false;
		a[i] = Library{a1, a2, n, c, f};
	}
	for (;;) {
		int i = 0;
		string search = "";
		system("cls");
		cout << "Choose function: " << endl;
		cout << "1 - Show" << endl;
		cout << "2 - Search" << endl;
		cout << "3 - Check presence" << endl;
		cout << "4 - Take one" << endl;
		cout << "5 - Return one" << endl;
		cin >> i;
		
		if (cin.fail())break;
		system("cls");
		switch (i) {
		case 1:
			cout << "Show" << endl;
			print(a, size);
			break;
		case 2:
			cout << "Search" << endl;
			print(a, size);
			cout << "Enter Name of the book:" << endl;
			cin >> search;
			for (int k = 0; k < size; k++) {
				if (a[k].nm_ret() == search) {
					a[k].show();
					cout << endl;
				}
				
			}				
			break;
		case 3:
			cout << "Check presence" << endl;
			print(a, size);
			cout << "Enter Name of the book:" << endl;
			cin >> search;
			for (int k = 0; k < size; k++) {
				if (a[k].nm_ret() == search && a[k].is_present()) {
					cout << a[k].nm_ret() << " Is present." << endl;
					cout << endl;
				}				
				else if(a[k].nm_ret() == search){
					cout << a[k].nm_ret() << " Is absent." << endl;
					cout << endl;
				}				
			}
			break;
		case 4: 
			cout << "Take one" << endl;
			print(a, size);
			cout << "Enter Name of the book:" << endl;
			cin >> search;
			for (int k = 0; k < size; k++) {
				if (a[k].nm_ret() == search && a[k].is_present()) {
					cout << a[k].nm_ret() << " Is present." << endl;
					a[k].take_book();
					cout << endl;
				}
				else if (a[k].nm_ret() == search) {
					cout << a[k].nm_ret() << " Is absent." << endl;
					cout << endl;
				}
			}
			break;
		case 5:
			cout << "Return one" << endl;
			print(a, size);
			cout << "Enter Name of the book:" << endl;
			cin >> search;
			for (int k = 0; k < size; k++) {
				if (a[k].nm_ret() == search && !a[k].is_present()) {
					cout << a[k].nm_ret() << " Is absent." << endl;
					a[k].ret_book();
					cout << endl;
				}
				else if (a[k].nm_ret() == search) {
					cout << a[k].nm_ret() << " Is present." << endl;					
					cout << endl;
				}
			}
			break;
		default:
			cout << "Invalid numb." << endl;
			break;
		}
		system("pause");
	}
	delete[] a;
}