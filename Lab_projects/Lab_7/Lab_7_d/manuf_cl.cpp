#include "manuf_cl.h"
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

MANUFACTURER & MANUFACTURER::operator()(MANUFACTURER & other)
{
	// TODO: insert return statement here
	this->SetCompany(other.GetCompany());
	this->SetMarketPart(other.GetMarketPart());
	this->SetQuantity(other.GetQuantity());
	this->SetYearSales(other.GetYearSales());
	return *this;
}

void MANUFACTURER::SetCompany(const string & c)
{
	this->company = c;
}

void MANUFACTURER::SetQuantity(const short & q)
{
	this->quantity = q;
}

void MANUFACTURER::SetYearSales(const long long int & y)
{
	this->yearSales = y;
}

void MANUFACTURER::SetMarketPart(const double & m)
{
	this->marketPart = m;
}

const string & MANUFACTURER::GetCompany()
{
	// TODO: insert return statement here
	return this->company;
}

const short & MANUFACTURER::GetQuantity()
{
	// TODO: insert return statement here
	return this->quantity;
}

const long long int & MANUFACTURER::GetYearSales()
{
	// TODO: insert return statement here
	return this->yearSales;
}

const double & MANUFACTURER::GetMarketPart()
{
	// TODO: insert return statement here
	return this->marketPart;
}

int MANUFACTURER::col_count(const int & a, const int & b)
{
	// a - размер строки, в - размер колонки
	int c = a + (b - a) / 2;
	return c;
}

ostream& operator<< (ostream & out, MANUFACTURER & a)
{
	// размеры колонок
	int COL1 = 20,
		COL2 = 25,
		COL3 = 28,
		COL4 = 18;
	string f = to_string(a.marketPart * 10 / 10);

	// размеры текстов
	int txt1 = a.company.length(),
		txt2 = to_string(a.quantity).length(),
		txt3 = to_string(a.yearSales).length(),
		txt4 = f.length() - 4;
	// размер сетва для каждой колонки
	int col1 = a.col_count(txt1, COL1),
		col2 = a.col_count(txt2, COL2),
		col3 = a.col_count(txt3, COL3),
		col4 = a.col_count(txt4, COL4);

	cout << "\n|" << setw(col1) << a.GetCompany() << setw(COL1 - col1) << "|";
	cout << setw(col2) << a.GetQuantity() << setw(COL2 - col2) << "|";
	cout << setw(col3) << a.GetYearSales() << setw(COL3 - col3) << "|";
	cout << setw(col4) << a.GetMarketPart() << setw(COL4 - col4) << "|";
	cout << "\n ------------------------------------------------------------------------------------------";
	return out;
}
istream& operator>> (istream & in, MANUFACTURER & a)
{
	string e;
	short b;
	long long c;
	double d;
	cout << "Company: ";
	cin >> e;
	a.SetCompany(e);
	cout << "Quantity: ";
	cin >> b;
	a.SetQuantity(b);
	if (b <= SHRT_MAX && b >= 0) {
		a.SetQuantity(b);
	}
	else
		a.SetQuantity(0);
	cout << "YearSales: ";
	cin >> c;
	if (c <= LLONG_MAX && c >= 0) {
		a.SetYearSales(c);
	}
	else
		a.SetYearSales(0);
	cout << "MarketPart: ";
	double n = 1.7*(10 ^ 308);

	cin >> d;
	if (d <= n && d >= 0)
	{
		a.SetMarketPart(d);
	}
	else a.SetMarketPart(0);
	return in;
}

void MANUFACTURER::shapka()
{
	cout << "  ________________________________________________________________________________________";
	cout << "\n /                               Фирмы - производители СКБД                               \\";
	cout << "\n ------------------------------------------------------------------------------------------";
	cout << "\n|       Фирма       | Количество. продуктов  | Годовой объем продажи ($) | Часть рынка (%) |";
	cout << "\n ------------------------------------------------------------------------------------------";
}
bool MANUFACTURER::operator==(MANUFACTURER & other)
{

	return this->GetCompany() != other.GetCompany() ? false : 
	       this->GetMarketPart() != other.GetMarketPart() ? false : 
	       this->GetQuantity() != other.GetQuantity() ? false : 
		   this->GetYearSales() != other.GetYearSales() ? false :
		   true;
}
void MANUFACTURER::gener(MANUFACTURER & a)
{
	MANUFACTURER arr[3] = {
		{ "Oracle", 1, 2488000000, 31.1 },
		{ "IBM", 3 , 2392000000, 29.9 },
		{ "Microsoft", 2 ,1048000000, 13.1 }
	};
	a = arr[rand() % 3];
}
void MANUFACTURER::resize(MANUFACTURER*& a, int & b) {
	MANUFACTURER* new_a = new MANUFACTURER[b + 1];
	if (b > 0) {
		for (int i = 0; i < b; i++)
			new_a[i] = a[i];
	}
	delete[]a;
	a = new_a;
	b++;
	new_a = nullptr;
}
void MANUFACTURER::print(MANUFACTURER*& a, int & b)
{
	a->shapka();
	for (int i = 0; i < b; i++)
		cout << a[i];
}
void MANUFACTURER::printF(MANUFACTURER *& a, int & b, const string & Fname)
{
	ofstream out;
	out.open(Fname);
	shapkaF(out);
	for (int i = 0; i < b; i++)
	{
		out << a[i];
	}
	out.close();
}
void MANUFACTURER::readF(MANUFACTURER *& a, int & b, const string & Fname)
{
	try
	{
		ifstream in;
		MANUFACTURER::clean(a, b);
		in.open(Fname);
		for (int i = 0; i<5; i++) {
			string buf;
			getline(in, buf);
		}
		int count = 0;
		while (!(in.eof())) {
			count++;
			resize(a, b);
			in >> a[b - 1];
		}
		in.close();
	}
	catch (const std::exception&)
	{
		clean(a, b);
		string* menu = new string[3]{
		"Файл отсутствует или вы ввели неправильное имя, создать файл?",
		"1- Да",
		"2- Нет"
		};
		switch (Menu_show(menu, 3))
		{
		case 1: 
			cout << "Файл создан." << endl;
			printF(a, b, Fname);
			break;
		default:
			cout << "Выход." << endl;
			break;
		}
		delete[]menu;
	}


}

void MANUFACTURER::saved_check(MANUFACTURER *& a, int & b, const string & Fname)
{
	string * menu = new string[3]{
	"Изменения в текущем массиве не сохранены, сохранить?",
	"1- Да",
    "2- Нет"
	};
	MANUFACTURER* buf_arr = NULL;
	int size;
	MANUFACTURER::readF(buf_arr, size, Fname);
	if (!MANUFACTURER::equal(a, b, Fname))
	{
		switch (Menu_show(menu, 3))
		{
		case 1: printF(a, b, Fname);
			cout << "Данные сохранились:)" << endl;
			break;
		default:
			cout << "Данные не сохранились:(" << endl;
			break;
		}
	}
	delete[]menu;
}

void MANUFACTURER::printFL(MANUFACTURER & a, int & c1, const string & Fname)
{
	MANUFACTURER * buf_arr = NULL;
	int s = 0;
	MANUFACTURER::readF(buf_arr, s, Fname);
	if (s < 1 || s- 1< c1){
		if ( s - 1 < c1)
			c1 = s;
		else c1 = 0;
		resize(buf_arr, s);
    }
	buf_arr[c1] = a;
	MANUFACTURER::printF(buf_arr, s, Fname);
	MANUFACTURER::clean(buf_arr, s);
}

void MANUFACTURER::readFL(MANUFACTURER *& a, const int & size, const int & c2, const string & Fname)
{
	MANUFACTURER * buf_arr = NULL;
	int s = 0;
	MANUFACTURER::readF(buf_arr, s, Fname);

	a[size -1 ] = buf_arr[c2];
	MANUFACTURER::clean(buf_arr, s);
}

bool MANUFACTURER::equal(MANUFACTURER *& a, const int s, const string & Fname)
{
	MANUFACTURER * buf_arr = NULL;
	int size = 0;
	MANUFACTURER::readF(buf_arr, size, Fname);
	if (s != size)return false;
	bool eq = true;
	for (int i = 0; i < s; i++)
		if (!(a[i] == buf_arr[i]))
			eq = false;
	return eq;
}

void MANUFACTURER::clean(MANUFACTURER *& a, int & b)
{
	if (a != NULL) {
  		delete[] a;
		a = NULL;
	}
	b = 0;
}

ofstream& operator<< (ofstream & out, MANUFACTURER & a) {
	// размеры колонок
	int COL1 = 20,
		COL2 = 25,
		COL3 = 28,
		COL4 = 18;
	string f = to_string(a.marketPart * 10 / 10);

	// размеры текстов
	int txt1 = a.company.length(),
		txt2 = to_string(a.quantity).length(),
		txt3 = to_string(a.yearSales).length(),
		txt4 = f.length() - 4;
	// размер сетва для каждой колонки
	int col1 = a.col_count(txt1, COL1),
		col2 = a.col_count(txt2, COL2),
		col3 = a.col_count(txt3, COL3),
		col4 = a.col_count(txt4, COL4);

	out<< "\n" << "|" << setw(col1) << a.GetCompany() << setw(COL1 - col1) << "|";
	out << setw(col2) << a.GetQuantity() << setw(COL2 - col2) << "|";
	out << setw(col3) << a.GetYearSales() << setw(COL3 - col3) << "|";
	out << setw(col4) << a.GetMarketPart() << setw(COL4 - col4) << "|";
	out << "\n ------------------------------------------------------------------------------------------";
	return out;
}

ifstream& operator>> (ifstream & in, MANUFACTURER & a) {
	string buf;
	getline(in, buf);
	int size = 4;
	string *buf0 = new string[size];
	int length = 1;
	int counter = 0;
	while (length < buf.length()) {
		if (buf[length] != ' ' && (buf[length] != '|' && length != 1))
			buf0[counter] += buf[length];
		else if (buf[length] == '|' && length != 1)
			counter++;
		length++;
	}
	// сеттеры 
	a.SetCompany(buf0[0]);
	a.SetMarketPart(stod(buf0[3]));
	a.SetQuantity(stoi(buf0[1]));
	a.SetYearSales(stoll(buf0[2]));
	delete[] buf0;
	getline(in, buf);
	return in;
}

ofstream & shapkaF(ofstream & out)
{
    out <<  "  ________________________________________________________________________________________";
    out << "\n /                               Фирмы - производители СКБД                               \\";
	out << "\n ------------------------------------------------------------------------------------------";
	out << "\n|       Фирма       | Количество. продуктов  | Годовой объем продажи ($) | Часть рынка (%) |";
	out << "\n ------------------------------------------------------------------------------------------";
	return out;
}
