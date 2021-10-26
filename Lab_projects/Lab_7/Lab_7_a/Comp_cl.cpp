#include "Comp_cl.h"
Comp* Comp::p = 0;
int Comp::size = 0;
void Comp::write(const string & p)
{
	cout << "Метод записи в файл" << endl;
	ofstream out;
	out.open(p);
	for (int i = 0; i < size; i++) {
		if (i % 4 == 0 && i != 0)out << "\n";
		out << Comp::p[i].num<< " + "<< Comp::p[i].num2<< "*i";
		if (i % 4 != 3) out << " ";
	}
	out.close();
}
void Comp::read(const string & p)
{
	cout << "Метод чтения файла!" << endl;
	bool ev_ok = false;
	while (!ev_ok) {
		try
		{
			ifstream in;
			in.open(p);
			while (!in.eof())
			{
				string s;
				getline(in, s);
				string *buf = new string[4];				
				int iter = 0, i = 0;
				while (iter != s.length())
				{
					if (s[iter] == ' ') { i++; iter++; }
					if (s[iter] != ' ') {
						buf[i] += s[iter];
						iter++;
					}					
				}
				add(stod(buf[0]), stod(buf[1]));
				add(stod(buf[2]), stod(buf[3]));
				delete[] buf;
				ev_ok = true;
			}
			
			in.close();
		}
		catch (const std::exception&)
		{
			cout << "Файл для считывания не был создан" << endl;
			create_file(p);
			cout << "Теперь файл " << p << " находится в файловой системе и готов к использованию" << endl;
		}	
	}
	
}

void Comp::print()
{
	cout << "Метод печати массива комплексных чисел" << endl;
	for (int i = 0; i < size; i++) {
		if (i % 4 == 0 && i != 0)cout << "\n";
		cout << Comp::p[i].num << " + " << Comp::p[i].num2 << "*i";
		if (i % 4 != 3) cout << " ";
	}
}

void Comp::add(const double & val1,const double & val2)
{
	int n_size =size + 1;
	Comp* n_arr = new Comp[n_size];
	for (int i = 0; i < size; i++)
	{
		n_arr[i] = p[i];
	}
	Comp::clean();
	Comp::p = n_arr;
	size = n_size;
	p[n_size - 1].num = val1;
	p[n_size - 1].num2 = val2;
}

void Comp::del()
{
	int n_size = size - 1;
	Comp* n_arr = new Comp[n_size];
	for (int i = 0; i < n_size; i++)
	{
		n_arr[i] = p[i];
	}
	clean();
	p = n_arr;
	n_arr = p;
	size = n_size;
}

void Comp::clean()
{
	delete[] p;
	size = 0;
	p = nullptr;
}

Comp & Comp::operator=(const Comp & other)
{
	// TODO: insert return statement here
	this->num = other.num;
	this->num2 = other.num2;
	return *this;
}

void create_file(const string & p)
{
	cout << "Функция генерации файла"<<endl;
	ofstream out;
	out.open(p);
	for (int i = 0; i < 60; i++) {
		if (i % 4 == 0 && i != 0)out << "\n";
		int integ = rand() % 100, fract = rand() % 100;
		if (integ < 10)out << "0";
		out << integ << "." << fract;
		if (fract < 10)out << "0";
		if (i % 4 != 3) out << " ";
	}
	out.close();
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

