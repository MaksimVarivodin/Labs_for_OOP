#include "arr_cl.h"

void fill_file(const string & p)
{
	ofstream out;
	out.open(p, ios::binary);
	for (int i = 0; i < 10; i++) {
		int r = rand() % 99 + 1;
		out.write((char*)&r, sizeof(int));
	}
	out.close();
}

int* read_file(const string & p, const int & size)
{
	bool ev_ok = false;
	while (!ev_ok) {
		try
		{
			int* arr = new int[size];
			ifstream in;
			in.open(p, ios::binary);
			for (int i = 0; i < size;i++)
			in.read((char*)&arr[i], sizeof(int));
			ev_ok = true;
			in.close();
			return arr;
		}
		catch (const std::exception&)
		{
			cout << "Файл для считывания не был создан" << endl;
			fill_file(p);
			cout << "Теперь файл " << p << " находится в файловой системе и готов к использованию" << endl;
		}
	}

}

void Array::change_arr()
{
	int pos = 4;
	if (numbs != NULL) {
		if (numbs[pos] % 2 == 0) {
			for (int i = 0; i < pos; i++)
				numbs[i] = 77;
		} 
		else
			for (int i = pos +1	; i < size; i++)
				numbs[i] = 88;	
	}
		
}

void Array::write_new_arr(const string & p)
{
	cout << "Изначальный массив: " <<  endl;
	print();
	change_arr();
	cout << endl << "Массив для файла: " << endl;
	print();
	cout << endl;

	ofstream out;
	out.open(p, ios::binary);
	for (int i = 0; i < 10; i++) {
		out.write((char*)&numbs[i], sizeof(int));
	}
	out.close();
}

void Array::print()
{
	cout << "Числа: " << endl;
	for (int i = 0; i < size; i++)
		cout << numbs[i] << " ";
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