#pragma once
/*

ЋјЅќ–ј“ќ–Ќјя –јЅќ“ј є 10       “естирование
—делать 3 функции-шаблоны (шаблон дл€ целых, м.б. вещественных, символьных) и 3 теста.
‘ункции:
а) min() Ц нахождени€ минимального;
б) sort() Ц сортировка массива по возрастанию;
в) sum() Ц нахождени€ в массиве суммы положительных.
“есты:
а) дл€ ф. min() Ц проверить результаты сравнени€ полож., отриц., и смешанных:
Ц с помощью ф. min() найти минимум двух чисел (символов);
Ц сравнить результаты (assert()).
б) дл€ ф. sort():
Ц создать массив1 неотсортированный;
Ц создать массив2 ожидаемый отсортированный;
Ц отсортировать массив1, использу€ ф. sort();
Ц в цикле поэлементно сравнить результаты (assert()).
в)  дл€  ф. sum():
Ц создать массив;
Ц с помощью sum() найти сумму положительных;
Ц сравнить результаты ожидаемый и полученный (assert()).
—моделировать ситуации, когда assert() выдает ошибки:
Ц в ф. min() помен€ть знак в сравнении (знак > на знак  <);
Ц в ф. sort()помен€ть знак при сортировке (т.е. будет сортировка по убыванию);
Ц в ф. sum() убрать условие нахождени€ положительных.

*/
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cassert>
using namespace std;
template <typename T>
T assrt_val(T a, T b) {
	bool check = a == b;
	assert(check && "Error in value element " );
	return a;
}
template <typename T>
void assrt_arr(T*a, T b[], int size) {
	for (int i = 0; i < size; i++) {
		bool check = a[i] == b[i];
		assert(check && "Error in array element ");
	}
		
}
template <typename T>
void print(T * arr1, const int & size) {
	for (int i = 0; i < size; i++)
		cout << arr1[i] << " ";
	cout << endl;
}

template<typename T>
void del(T*& arr, int & size, int & pos) {
	--size;
	if (size <= 0) {
		delete[] arr;
		arr = nullptr;
		return;
	}
	T* n = new T[size];
	int i = 0;
	for (; i < pos; i++)
		n[i] = arr[i];
	i++;
	for (; i < size + 1; i++)
		n[i - 1] = arr[i];
	delete[] arr;
	arr = n;
	n = nullptr;
}

template<typename T>
void del(T**& arr, int & size, int & pos) {
	--size;
	if (size == 0) {
		delete[] arr;
		arr = nullptr;
		return;
	}
	T** n = new T*[size];

	int i = 0;
	for (; i < pos; i++)
		n[i] = arr[i];
	delete[]arr[i];
	i++;
	for (; i < size + 1; i++)
		n[i - 1] = arr[i];
	delete[] arr;
	arr = n;
	n = nullptr;
}

template <typename T>
T** M_creator(int *& s, const int &size, const T & c) {
	int S = sqrt(size);
	s = new int[S];
	T ** arr1 = new T *[S];

	if (typeid(T).name() == typeid(char).name()) {
		for (int i = 0; i < size; i++)
		{
			int j = S - (S - i % 3);
			s[j] = S;
			if (j == (S - 1))
				s[j] += size % S;
			arr1[j] = new T[s[i]];
			arr1[j][i == size - 1? (j*size)+ 1: i%S] = c+ i;
		}
		
	}
	else {
		for (int i = 0; i < S; i++)
		{
			s[i] = S;
			if (i == (S - 1))
				s[i] += size % S;
			arr1[i] = new T[s[i]];
			for (int j = 0; j < s[i]; j++) {

				arr1[i][j] = (i*S + j)*c;
			}
		}
	}
	
	return arr1;
}

template <typename T>
T * filler(const int & size, const T& c = 1) {
	int S = sqrt(size);
	int* s = NULL;
	T *arr = new T[size];
	T **buf = M_creator(s, size, c);

	for (int i = 0; i < size; i++) {

		int a = rand() % S;
		int b = rand() % s[a];
		arr[i] = buf[a][b];
		del(buf[a], s[a], b);
		if (s[a] == 0) {
			del(buf, S, a);
			S++;
			del(s, S, a);
		}
	}

	return arr;
}

template<typename T>
T minml(T* arr, int & size, const int & c = 1) {
	T m = arr[0];
	int counter = 0;
	for (int i = 1; i < size; i++) {
		if (c == 1 ? m > arr[i] : m < arr[i]) {
			m = arr[i];
		}
	}
	return m;
}

template<typename T>
void sort(T* arr, int & size, const int & c = 1) {
	int counter = 0;
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && (c == 1 ? arr[j - 1] > arr[j]: arr[j - 1] < arr[j]); j--) {
			counter++;
			string buf = "Iteration " + to_string(counter) + " of " + __FUNCTION__;
			swap(arr[j - 1], arr[j]);
		}
	}
}

template<typename T>
T sum(T* arr, int & size, const int & c = 1) {
	T m = 0;
	int counter = 0;
	if (typeid(T).name() == typeid(char).name()) {
		for (int i = 1; i < size - 1; i++) {
			if (c == 1 ? arr[i - 1] < arr[i + 1]: arr[i - 1] > arr[i + 1]) {
				m += arr[i - 1];
			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			if (c == 1 ? arr[i] > 0: m < arr[i]) {
				m += arr[i];
			}
		}
	}
	return m;
}

