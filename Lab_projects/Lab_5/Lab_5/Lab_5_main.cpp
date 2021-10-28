// Напишите программу которая будет просить ввести строку символов , \
   после этого он печатает её на экране \
1) все буквы в нижнем регистре , \
2) все буквы в большом регистре , \
3) все числа в строке выводить в HEX формате , \
4) вывод с заменой всех пробелов на символ #
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void С_gray(const string & a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	cout << a;
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}

void Choose(const string & a)
{
	cout << setw(11) << "--> ";
	С_gray(a);
	cout << endl;
}

int Menu_show(const string * arr, const int & size)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//получение хендла
	CONSOLE_CURSOR_INFO cursor = { 100,false };//число от 1 до 100 размер курсора в процентах; false\true - видимость
	SetConsoleCursorInfo(hCons, &cursor);
	bool done = false;
	int choice;
	int pos = 1;
	for (;;)
	{
		system("cls");
		cout << setw(19) << arr[0] << endl;
		int i = 1;
		for (; i < pos; i++)
			cout << setw(11 + arr[i].length()) << arr[i] << endl;
		Choose(arr[pos]);
		i++;
		for (; i < size; i++)
			cout << setw(11 + arr[i].length()) << arr[i] << endl;

		choice = _getch();
		if (choice == 224)
			choice = _getch();


		if (choice == 13)
			// enter
		{
			system("cls");
			return pos;
		}

		if (choice == 27 || done == true)
		{
			done = false;
			break;
		}

		switch (choice) {
		case 72:
			if (pos == 1)	pos = size - 1;
			else pos--;
			break;
		case 80:
			if (pos == size - 1)pos = 1;
			else pos++;
			break;
		}
	}

}

template<typename T>
void resize(T*& a, int &b){
	T* n = new T[b + 1];
	for (int i = 0; i < b; i++)
		n[i] = a[i];
	b++;
	delete[]b;
	b = n;
	n = nullptr;
}
void hexer(string x) {
	bool end = true;
	string buf = "";
	for each (char var in x)
	{
		bool conv = false;
		try
		{
			int a = var;
			conv = true;
		}
		catch (const std::exception&)
		{

		}
		if(!(::isalpha(var)) && var !=  ' ' && conv) {
			end = false;
			buf += var;
			if (var == x[x.length() - 1]) {
				try
				{
					cout << hex << stoi(buf);
				}
				catch (const exception&)
				{
					cout << var;
				}
			}
			
			
		}		 
		else { 
		if (!end) {
		        if (buf.length()>0) {
					try
					{
						cout << hex << stoi(buf);
					}
					catch (const exception&)
					{
						cout << buf;
					}
				}
				buf = "";
				end = true;
			}
		cout << var; 
		}
	}
}
void flipcase(string x, const int & Case = 1)
{
	// case 1 - Маленькие буквы
	// case 2 -  Большие буквы
	// isalpha возвращает 1, если буква маленькая, 2 если большая, 0 не буква
	char buf;
	for each (char var in x)	{
		if (::isalpha(var) == Case) { buf =  var ^ 32; }
		else buf = var;
		cout << buf;
	}
		
	
}
void fill(string x, char & filler) {
	for each (char var in x)
	{
		if (var == ' ')cout << filler;
		else cout << var;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a;
	cout << "Введите строку: ";
	getline(cin, a);
	string *menu = new string[6]{
	"Выберите способ вывода: ", 
	"1- Все буквы маленькие", 
	"2- Все буквы большие",
	"3- Все цифры в режиме HEX", 
	"4- Все пробелы заменяются введенным символом", 
	"5- Выход"
	};
	char symbol_filler;
	for (;;) {
		int Case = Menu_show(menu, 6);
		cout << "Initial line:\n"<< a << endl;
		cout << "Result line:\n";
		switch (Case) {
		case 1: 
			flipcase(a, Case);
			break;
		case 2: 
			flipcase(a, Case);
			break;
		case 3: 
			hexer(a);
			break;
		case 4: 
			system("cls");
			cout << "Введите символ-филлер: ";
			cin >> symbol_filler;
			cout << "Initial line:\n" << a << endl;
			cout << "Result line:\n" << endl;
			fill(a, symbol_filler);
			break;
		}
		if (Case == 5) break;
		cout << endl;
		system("pause");
	}
	
	delete[] menu;
}