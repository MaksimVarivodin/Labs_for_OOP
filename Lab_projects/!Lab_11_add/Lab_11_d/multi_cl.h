#pragma once
#define _CRT_SECURE_NO_WARNINGS // отключаем предупреждения о небезопасности
#include <iostream> 
#include <string> // для работы со строками
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для работы функции time()
#include <iomanip>
using namespace std;


// ЛАБОРАТОРНАЯ РАБОТА № 11Д.
/*

Разработать класс для представления объекта множество чисел (элементы не повторяются).
– Определить конструктор с тремя параметрами (количество элементов, минимальный и 
максимальный в диапазоне генерируемых чисел), 
который задаёт элементы множества (конструктор с параметрами).\/
– Определить конструктор, который генерирует 
множество из 10 элементов в диапазоне [-20; 20] (конструктор по умолчанию).\/
– Определить конструктор, которые копирует в 
новое множество элементы другого множества, не превышающие заданное значение (конструктор копирования).\/
– Создать функцию, которая находит максимальное значение в множестве.
– Создать функции для построения 
объединения, \/
пересечения, \/
разности \/
и дизъюнктивной суммы двух числовых множеств.\/

*/


template <typename T>
void add_one_arr(T*&arr, int& size) {
	T* new_arr = new T[size + 1];
	if (arr != NULL) {
		for (int i = 0; i < size; i++)
			new_arr[i] = arr[i];
		delete[]arr;
	}
	size++;
	arr = new_arr;
}
template <typename T>
void del_one_arr(T*&arr, int& size) {
	T* new_arr = new T[size + 1];
	if (arr != NULL) {
		for (int i = 0; i < size; i++)
			new_arr[i] = arr[i];
		delete[]arr;
	}
	size++;
	arr = new_arr;
}
class MULTIPLICITY
{	
	int* mltplct = NULL;
	int count = 0;
	int max = 0;
	int min = 0;

    // шаблонные функции добавления одного 
	template <typename T> friend void add_one_arr(T*&arr, int&size);
	template <typename T> friend void del_one_arr(T*&arr, int&size);

public:
	// общий конструктор
	MULTIPLICITY(const int & count)
	{
		this->count = count;
		this->mltplct = new int[count];
	}
	// инициализация при помощи массива
	MULTIPLICITY(const int * arr, const int & count0) : MULTIPLICITY(count0)
	{
		this->max = arr[0];
		this->min = max;
		for (int i = 0; i < count; i++)
		{
			this->mltplct[i] = arr[i];
			if (max < mltplct[i])
			{
				max = mltplct[i];
			}
			if (min > mltplct[i])
			{
				min = mltplct[i];
			}			
		}
	}
	// конструктор с параметрами
	MULTIPLICITY(const int & max, const int & min, const int & count0) : MULTIPLICITY(count0) {
		// случайное опеределение первого элемента в диапазоне минус количество создаваемых элементов
		int j = rand() % (max - count - min + 1) + min;
		for (int i = 0; i < this->count; i++)
		{
			mltplct[i] = j;
			j++;
		}
		this->max = mltplct[0];
		this->min = this->max;
		for (int i = 0; i < count; i++)
		{
			if (this->max< mltplct[i])
			{
				this->max = mltplct[i];
			}
			if (this->min > mltplct[i])
			{
				this->min = mltplct[i];
			}
		}
	}
	// конструктор по умолчанию
	MULTIPLICITY() :MULTIPLICITY(20, -20, 10) {}
	// конструктор копирования
	MULTIPLICITY(const MULTIPLICITY & other):MULTIPLICITY(other.count) {		
		this->max = other.max;
		this->min = other.min;
		for (int i = 0; i < other.count; i++)
			this->mltplct[i] = other.mltplct[i];
	}
	// поиск максимального элемента
	int max_val();
	// пересечение
	MULTIPLICITY intersection( const MULTIPLICITY& b);
	// симметрическая разность
	MULTIPLICITY symmetric_dif( const MULTIPLICITY& b);
	// разность
	MULTIPLICITY substract( const MULTIPLICITY&b);
	// объеденение
	MULTIPLICITY merge( const MULTIPLICITY& b);
	// перегруженный оператор вывода
    friend ostream&  operator<<( ostream & out, const MULTIPLICITY & a);
};