#pragma once
#include <iostream>
using namespace std;
template <class T>
class Num {
	T num;
	Num(const T &a = 0)
	{
		num = a;
	}
	void fu() { cout << "Number: " << num << endl; }
	T operator/(const T &a);
	T Enter_check(T & a, const T & max, const T & min)
	{
		bool ok = false;
		while (!ok) {
			try
			{
				string a0;
				getline(cin, a0);
				a = stoi(a0);
				// ���� ������ �������� ������, �� �� �� ������ ���
				if (a <= max && a >= min) {
					ok = true;
					return 1;
				}
				else {
					cout << "���������� �������� ��������!" << endl;
					if (a == -1) return -1;
				}
				cin.ignore(32767, '\n');
			}
			catch (const std::exception&)
			{
				cout << "������� ����� ��� ���, ���������� ��������� �������" << endl;

			}
		}
	}
};

template<class T>
inline T Num<T>::operator/(const T &a)
{
	T buf = this->num / a.num;
	return buf';
}
