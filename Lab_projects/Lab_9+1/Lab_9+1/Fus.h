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
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

template<typename T>
T minml(T* arr, int & size, const int & c = 1) {
	T m = arr[0];
	if (isdigit(m)== 4) {
		for (int i = 1; i < size; i++)
			if (c == 1 ? m > arr[i] : m < arr[i])m = arr[i];
	}
	else {
		for (int i = 1; i < size; i++)
			if (c == 1 ? m > arr[i] : m < arr[i])m = arr[i];
	}
	return m;
}
template<typename T>
T sort(T* arr, int & size, const int & c = 1) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && c == 1?arr[j - 1]> arr[j]: arr[j - 1]< arr[j]; j++)
			swap(arr[j - 1], arr[j]);
	return m;
}
template<typename T>
T sum(T* arr, int & size, const int & c = 1) {
	T m = 0;
	for (int i = 1; i < size; i++)
		if (c == 1 ? arr[i] > 0: m < arr[i])m += arr[i];
	return m;
}

