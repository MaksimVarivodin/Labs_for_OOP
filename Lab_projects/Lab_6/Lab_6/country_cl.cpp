#include "country_cl.h"

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


void Country::operator()(const string & n, const string & c, const int & p, const int & a)
{
	name = n;
	capital = c;
	population = p;
	area = a;
}

int Enter_check(int & a, const int & max, const int & min)
{
	bool ok = false;
	while (!ok) {
		try
		{
			string a0;
			getline(cin, a0);
			a = stoi(a0);
			// если раньше выскочит ошибка, то ок не станет тру
			if (a <= max && a >= min) {
				ok = true;
				return 1;
			}				
			else {
				cout << "Соблюдайте диапазон значений!" << endl;
				if (a == -1) return -1;
			}
			cin.ignore(32767, '\n');
		}
		catch (const std::exception&)
		{
			cout << "Введите число еще раз, обнаружены сторонние символы" << endl;
			
		}
	}
}

void Shapka()
{
	cout << "                            СТРАНА: \n";
	cout << "----------------------------------------------------------------\n";
	cout << "|  Название  |   Столица   |  Население  |  Площадь территории |\n";
	cout << "----------------------------------------------------------------\n";
}

void Print(Country* World, const int & size)
{
	Shapka();
	for (int i = 0; i < size; i++) {
		cout << "|" << setw(10) << World[i].name << setw(3) << "|" << setw(10) << World[i].capital;
		cout << setw(4) << "|" << setw(11) << World[i].population << setw(3) << "|" << setw(20) << World[i].area << setw(2) << "|"<< "\n";
	}
	cout << "----------------------------------------------------------------\n";
}

void Sort(Country * World, const int & size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0 && World[j - 1].name>World[j].name; j--) {
			Country buf = World[j - 1];
			World[j - 1] = World[j];
			World[j] = buf;
		}
	}
}
