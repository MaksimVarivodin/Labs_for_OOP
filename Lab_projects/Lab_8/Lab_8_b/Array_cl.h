#pragma once
/*
������� �����-������ ��� ������ � ��������:
���� � ������������ ������, ������������ ������ ������� (size), ������ (0 < ind < size  ��� ������ �� �� ����� ���������� �������);
�������
� ����������� �� ��������� (�������� ������ ��� ������ � �������������� ���������� size=100, ind=0);
� ������� ���������� ������ �������� ������� (� main() ����������� � ����� ���������� ������� �� �������� ind);
� ������� �������� ����� �������� � ������� �������� ind;
� ������� �������� ��������������������� �������� � ������� �������� ind;
� ������� ������ ������� �������� ind;
� ����������� �������� [ ] ��� �������� ������������� �������� � ������� ������ ������� (<=ind);
� ���������� ��� �������� ������������� �������.
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
void �_gray(const string& a);
// ������� ������� ���������� ����� ������ �������
void Choose(const string& a);
// ������ ������ ������ ����(��)
int Menu_show(const string* arr, const int & size);

template <class T>
class Arr {
	//���� � \
	������������ ������, \
	������������ ������ ������� (size), \
    ������ (0 < ind < size  ��� ������ �� �� ����� ���������� �������);
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
	// �������������
	void operator()(T &a);
	// ������� ����� �� ind
	T s();
	// ������� �������� ��������������� �� ind
	T a();
	// ������ �� ind
	template<class T> friend ostream& operator<< (ostream& out, Arr<T> a);
	// ����� ��� �� ������� �� ind
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
void �_gray(const string & a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	cout << a;
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
}

void Choose(const string & a)
{
	cout << setw(11) << "--> ";
	�_gray(a);
	cout << endl;
}

int Menu_show(const string * arr, const int & size)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//��������� ������
	CONSOLE_CURSOR_INFO cursor = { 100,false };//����� �� 1 �� 100 ������ ������� � ���������; false\true - ���������
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
		"�������� �����:",
		"1 - ������ ind",
		"2 - ������� ���������� ���� ��������� � ������� �� ind",
		"3 � ������� �������� ����� �������� � ������� �������� ind",
		"4 � ������� �������� ��������������������� �������� � ������� �������� ind",
		"5 � ������� ������ ������� �������� ind",
		"6 � ���������� ��������[] ��� �������� ������������� �������� � ������� ������ �������",
		"7 - �����"
	};
	for (;;) {
		switch (Menu_show(menu1, size1)) {
		case 1:
			for (;;) {
				cout << "������� ind: ";
				cin >> a;
				if (a >= 0 && a < size) {
					SETind(a);
					break;
				}
			}
			cout << "ind ���� " << GETind() << endl;
			break;
		case 2:
			try
			{
				this->breaker();
				cout << "������� ���������� ���� ��������� � ������� �� ind" << endl;
				cout << "������: ";
				for (int i = 0; i <= GETind(); i++) {
					cout << i << " ";
					(*this)(GETel(i));
				}
				cout << "���������." << endl;
			}
			catch (const std::exception&)
			{
				cout << "�� �� ����� ind";
			}
			break;
		case 3:
			try
			{
				this->breaker();
				cout << "������� �������� ����� �������� � ������� �������� ind ������� " << s() << "." << endl;
				s();
			}
			catch (const std::exception&)
			{
				cout << "�� �� ����� ind";
			}

			break;
		case 4:
			try
			{
				this->breaker();
				cout << "������� �������� ��������������������� �������� � ������� �������� ind ������� " << this->a() << "." << endl;

			}
			catch (const std::exception&)
			{
				cout << "�� �� ����� ind";
			}
			break;
		case 5:
			try
			{
				this->breaker();
				cout << "������� ������ ������� �������� ind" << endl;
				cout << *this;
			}
			catch (const std::exception&)
			{
				cout << "�� �� ����� ind";
			}

			break;
		case 6:
			try
			{
				this->breaker();
				cout << "���������� ��������[] ��� �������� ������������� �������� � ������� ������ ������� ������� " << this->operator[](GETind()) << "." << endl;
			}
			catch (const std::exception&)
			{
				cout << "�� �� ����� ind";
			}
			break;
		case 7:
			cout << "�����" << endl;
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

