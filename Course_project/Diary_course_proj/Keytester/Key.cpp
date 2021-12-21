#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int main() {
	for (;;) {
		int key = _getch();
		if (key == 27)break;
		string ent = "Entered symbol number: ";
		cout << ent << key << endl;
		cout << "Symbol: " << (char)key << endl;
	}
	

}