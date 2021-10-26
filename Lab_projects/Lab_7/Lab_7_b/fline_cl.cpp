#include "fline_cl.h"
void Fline::show()
{
	cout << "Строка введенная в файл: " << endl;
	cout << Rline<< endl;
}
void Fline::write(const string & p)
{
	ofstream out;
	out.open(p);
	out << *this;
	out.close();
}
void setter(char a[], const int & min, const int & max) {
	for (int i = min; i < max; i++) {
		a[i - min] = i;
	}
}
bool one_checker(const char & a, char b[], const int & size) {
	for (int i = 0; i < size; i++) {
		if (a == b[i])return true;
	}
	return false;
}
bool add_checker(const char & a)
{
	const int s_n = 10;
	const int s_e = 91 - 65;
	const int s_r = 224 - 192;
	char nums[s_n]{};
	char eng_L[s_e]{};
	char rus_L[s_r]{};
	setter(nums, 48, 58);
	setter(eng_L, 65, 91);
	setter(rus_L, 192, 224);
	if (one_checker(a, nums, s_n))return true;
	if (one_checker(a, eng_L, s_e))return true;
	if (one_checker(a, rus_L, s_r))return true;
	return false;
}
ofstream & operator<<(ofstream & out, Fline & a) {
	for (int i = 0; i < a.line.length(); i++) {
		if (!add_checker(a.line[i])) {
			a.Rline += a.line[i];
		}
	}
	out << a.Rline;
	return out;
}
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