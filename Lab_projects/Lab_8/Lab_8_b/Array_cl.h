#pragma once
/*
Создать класс-шаблон для работы с массивом:
ПОЛЯ – динамический массив, максимальный размер массива (size), индекс (0 < ind < size  для работы не со всеми элементами массива);
ФУНКЦИИ
– конструктор по умолчанию (выделяет память под массив и инициализирует переменные size=100, ind=0);
– функция заполнения одного элемента массива (в main() реализовать в цикле заполнение массива до значения ind);
– функция подсчета суммы значений в массиве размером ind;
– функция подсчета среднеарифметического значений в массиве размером ind;
– функция печати массива размером ind;
– перегрузить операцию [ ] для подсчета максимального значения в массиве любого размера (<=ind);
– деструктор для удаления динамического массива.
*/
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
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
void С_gray(const string& a);
// функция которая показывает какую строку выбрали
void Choose(const string& a);
// фунция вывода любого меню(ЮИ)
int Menu_show(const string* arr, const int & size);

template <class T>
class Arr {
	//ПОЛЯ – \
	динамический массив, \
	максимальный размер массива (size), \
    индекс (0 < ind < size  для работы не со всеми элементами массива);
	T* arr;
	int size;
	int ind;
	bool ind_b() { return GETind() > 0 ? true : false; }
	void breaker() { if (!ind_b()) {
		string b = "g";
		stoi(b);
	} }
	void SETind(const int & a) { ind = a; }
	int& GETind() { return ind; }
	T& GETel(int & a) { return arr[a]; }
	// инициализатор
	void operator()(T &a);
	// подсчет суммы до ind
	T s();
	// подсчет среднего арифметического до ind
	T a();
	// печать до ind
	template<class T> friend ostream& operator<< (ostream& out, Arr<T> a);
	// поиск мах по массиву до ind
	T operator[](int & ind);
public:
	Arr()
	{
		size = 100;
		arr = new T[size];
		ind = 0;
	}
	~Arr() {
		delete[] this->arr;
		arr = nullptr;
	}

	void use();
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
		{
			cout << setw(11 + arr[i].length()) << arr[i] << endl;
		}

		choice = _getch();
		if (choice == 224)
		{
			choice = _getch();
		}


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
			if (pos == 1) { pos = size - 1; }
			else { pos--; }
			break;
		case 80:
			if (pos == size - 1) { pos = 1; }
			else { pos++; }
			break;
		}
	}

}

template<class T>
void Arr<T>::operator()(T & a)
{
	double buf = rand() % 199 - 99;

	double buf2 = rand() % 100 * (buf < 0 ? -0.01 : 0.01);
	T b = buf + buf2;
	if (b == buf) {
		a = buf;
	}

	else
	{
		a = buf + buf2;
	}
}

template<class T>
inline T Arr<T>::s()
{
	T S = 0;
	for (int i = 0; i < ind; i++) {
		S += arr[i];
	}
	return S;
}

template<class T>
inline T Arr<T>::a()
{
	return  s() / (ind + 1);
}

template<class T>
inline T Arr<T>::operator[](int & ind)
{
	T max = -100.0;
	for (int i = 0; i < ind; i++) {
		if (max < arr[i]) { max = arr[i]; }
	}
	return max;
}

template<class T>
inline void Arr<T>::use()
{
	int size1 = 8, a = 0;
	string* menu1 = new string[size1]{
		"Выберите метод:",
		"1 - Задать ind",
		"2 - Функция заполнения всех элементов в массиве до ind",
		"3 – Функция подсчета суммы значений в массиве размером ind",
		"4 – Функция подсчета среднеарифметического значений в массиве размером ind",
		"5 – Функция печати массива размером ind",
		"6 – Перегрузка операции[] для подсчета максимального значения в массиве любого размера",
		"7 - Выход"
	};
	for (;;) {
		switch (Menu_show(menu1, size1)) {
		case 1:
			for (;;) {
				cout << "Введите ind: ";
				cin >> a;
				if (a >= 0 && a < size) {
					SETind(a);
					break;
				}
			}
			cout << "ind стал " << GETind() << endl;
			break;
		case 2:
			try
			{
				this->breaker();
				cout << "Функция заполнения всех элементов в массиве до ind" << endl;
				cout << "Ячейка: ";
				for (int i = 0; i <= GETind(); i++) {
					cout << i << " ";
					(*this)(GETel(i));
				}
				cout << "заполнена." << endl;
			}
			catch (const std::exception&)
			{
				cout << "Вы не ввели ind";
			}
			break;
		case 3:
			try
			{
				this->breaker();
				cout << "Функция подсчета суммы значений в массиве размером ind вернула " << s() << "." << endl;
				s();
			}
			catch (const std::exception&)
			{
				cout << "Вы не ввели ind";
			}

			break;
		case 4:
			try
			{
				this->breaker();
				cout << "Функция подсчета среднеарифметического значений в массиве размером ind вернула " << this->a() << "." << endl;

			}
			catch (const std::exception&)
			{
				cout << "Вы не ввели ind";
			}
			break;
		case 5:
			try
			{
				this->breaker();
				cout << "Функция печати массива размером ind" << endl;
				cout << *this;
			}
			catch (const std::exception&)
			{
				cout << "Вы не ввели ind";
			}

			break;
		case 6:
			try
			{
				this->breaker();
				cout << "Перегрузка операции[] для подсчета максимального значения в массиве любого размера вернула " << this->operator[](GETind()) << "." << endl;
			}
			catch (const std::exception&)
			{
				cout << "Вы не ввели ind";
			}
			break;
		case 7:
			cout << "Выход" << endl;
			delete[] menu1;
			return;
			break;

		}
		system("pause");
	}


}

template<class T>
inline ostream & operator<<(ostream & out, Arr<T> a)
{
	// TODO: insert return statement here
	for (int i = 0; i <= a.GETind(); i++) {
		cout << a.arr[i] << " ";
		if (i % 4 == 3) {
			cout << endl;
		}
	}
	return out;
}

