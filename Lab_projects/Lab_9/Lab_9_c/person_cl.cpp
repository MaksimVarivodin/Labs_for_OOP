#include "person_cl.h"

void Staff::filler(string a[20], int b[20])
{
	string names[20] = {
		"Виктор Волков",
		"Степан Горячев",
		"Глеб Жаров",
		"Евгений Калашников",
		"Матвей Макаров",
		"Роман Серов",
		"Михаил Сорокин",
		"Тимофей Суворов",
		"Демьян Терентьев",
		"Григорий Фролов",
		"Полина Агеева",
		"Анастасия Быкова",
		"Светлана Данилова",
		"Варвара Ермолаева",
		"Вероника Жилина",
		"Василиса Ковалева",
		"Екатерина Лебедева",
		"Анастасия Леонова",
		"Василиса Макарова",
		"София Моисеева"

		/* */ };
	string buf = "Unsuccessfull filler fu";
	try
	{
		int count = stff1.size(), iter = 0;
		for each (string var in a)
		{
			bool found = false;
			for each(string var2 in names)
			{
				if (var2 == var) found = true;
			}
			if (!found) throw buf;
		}
		for each(int & var in b) {
			++count;
			if (var < 0 || var > 19) throw buf;
			stff1.insert({ Person{ a[iter], var },  count });
			stff2.insert({ Person{ a[iter], var }, count });
			iter++;
		}
		cout <<  count << " elems in maps" << endl;
	}
	catch (const string &buf)
	{
		throw buf;
	}
	

}

void Staff::printer(const int& c)
{
	system("cls");
	cout << "Staff1 " << endl<< endl;
	for (const auto &x : stff1) {
		switch (c)
		{
		case 1:
			cout << "\t" << const_cast<Person&>(x.first).GETname() << "\t" << x.second << endl;
			break;
		case 2:
			cout << "\t" <<	const_cast<Person&>(x.first).GETage() << "\t" << x.second << endl;
			break;
		default:
			cout << "\t" << const_cast<Person&>(x.first).GETname() << "\t" <<
				const_cast<Person&>(x.first).GETage()<< "\t" << x.second << endl;
			break;
		}
		
	}
	
	cout << endl << "Staff2 " << endl<< endl;
	for (const auto &x : stff2) 
	{
		switch (c)
		{
		case 1:
			cout << "\t" << const_cast<Person&>(x.first).GETname() << "\t" << x.second << endl;
			break;
		case 2:
			cout << "\t" <<	const_cast<Person&>(x.first).GETage() << "\t" << x.second << endl;
			break;
		default:
			cout << "\t" << const_cast<Person&>(x.first).GETname() << "\t" <<
				const_cast<Person&>(x.first).GETage() << "\t" << x.second << endl;
			break;
		}
		
	}
		

}

void Staff::cutter(const string & a)
{
	int counter1 = 0, counter2 = 0;
	for (auto p = begin(stff1); p != end(stff1); )
	{
		if (const_cast<Person&>(p->first).GETname().find(a) != string::npos) {
			cout << "Deleting: ";
			cout << "\t" << const_cast<Person&>(p->first).GETname() << "\t" <<
				const_cast<Person&>(p->first).GETage() << "\t" << p->second << "..."<< endl;			
			p = stff1.erase(p);
			counter1++;
		}
		else p++;
	}
	for (auto p = begin(stff2); p != end(stff2); )
	{
		if (const_cast<Person&>(p->first).GETname().find(a) != string::npos) {
			cout << "Deleting: ";
			cout << "\t" << const_cast<Person&>(p->first).GETname() << "\t" <<
				const_cast<Person&>(p->first).GETage() << "\t" << p->second << "..." << endl;
			p = stff2.erase(p);
			counter2++;
		}
		else p++;
	}
	cout << "Deleted in stff1: " << counter1 << " Deleted in stff2: " << counter2<< endl;
}

void Staff::add_master(const Person & a)
{
	stff1.insert({ a, stff1.size() + 1 });
	stff2.insert({ a, stff2.size() + 1 });
	cout << "Added 1 elem." << endl;
}

void Staff::search_machine(const int& a)
{
	int counter1 = 0, counter2 = 0;
	for (auto p = begin(stff1); p != end(stff1); p++)
	{
		if (const_cast<Person&>(p->first).GETage() == a) {
			cout << "Found: ";
			cout << "\t" << const_cast<Person&>(p->first).GETname() << "\t" <<
				const_cast<Person&>(p->first).GETage() << "\t" << p->second << endl;

			counter1++;
		}

	}
	for (auto p = begin(stff2); p != end(stff2); p++)
	{
		if (const_cast<Person&>(p->first).GETage() == a) {
			cout << "Found: ";
			cout << "\t" << const_cast<Person&>(p->first).GETname() << "\t" <<
				const_cast<Person&>(p->first).GETage() << "\t" << p->second << endl;
			counter2++;
		}

	}
	cout << "Found in stff1: " << counter1 << " Found in stff2: " << counter2 << endl;
}

void Staff::search_machine(const string& a)
{
	int counter1 = 0, counter2 = 0;
	for (auto p = begin(stff1); p != end(stff1); p++)
	{
		if (const_cast<Person&>(p->first).GETname().find(a) != string::npos) {
			cout << "Found: ";
			cout << "\t" << const_cast<Person&>(p->first).GETname() << "\t" <<
				const_cast<Person&>(p->first).GETage() << "\t" << p->second << endl;			
			counter1++;
		}
	}
	for (auto p = begin(stff2); p != end(stff2); p++)
	{
		if (const_cast<Person&>(p->first).GETname().find(a) != string::npos) {
			cout << "Found: ";
			cout << "\t" << const_cast<Person&>(p->first).GETname() << "\t" <<
				const_cast<Person&>(p->first).GETage() << "\t" << p->second << endl;
			counter2++;
		}
		
	}
	cout << "Found in stff1: " << counter1 << " Found in stff2: " << counter2 << endl;
}

void Enter_check(int & a, const int & max, const int & min)
{
	bool ready = false;
	string er = "Число не входит в диапазон значений!\n Введите число еще раз: ";
	while (!ready) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{

		string b;
		getline(cin, b);
		try
		{
			a = stoi(b);
			if (a < min || a> max)  throw er;
			ready = true;
		}
		catch (const string & er)
		{
			cout << er;
		}
		catch (const std::exception&)
		{
			cout << "Замечены сторонние символы!\n Введите число еще раз: ";
		}
	}
}

void Enter_check(string & a) {
	string b;
	getline(cin, b);
	a = b;
}

int Menu_show(const string  arr[], const int & size)
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
			return 0;
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