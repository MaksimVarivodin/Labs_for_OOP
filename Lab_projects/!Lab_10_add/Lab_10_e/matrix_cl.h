#pragma once
#define _CRT_SECURE_NO_WARNINGS // отключаем предупреждения о небезопасности
#include <iostream> 
#include <string> // для работы со строками
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для работы функции time()
using namespace std;

// ЛАБОРАТОРНАЯ РАБОТА № 10Е.
/*

Создать класс, описывающий двумерную матрицу. Реализовать функции:
– генерация массива (заполнение случайными числами);\/
– вывод массива на экран;\/
– поиск координат элемента с минимальными значениями;\/
– получение элемента по позиции и запись по заданным координатам;
– получение подматрицы по начальным позициям заданного размера.
Например, для матрицы размера 4х4
01 02 03 04
05 06 07 08
09 10 11 12
13 14 15 16
выделить подматрицу размером 3х2 с позиции 1х1
06 07
10 11
14 15

*/

class MATRIX
{

	// двумерный указатель на общий массив
	static MATRIX** mtrx;
    // число 
	int num;
	// размер массива по длине
	static int size_x;
	// размер массива по высоте
	static int size_y;	
	// метод создания массива
	static void creator();
	// очистка массива например, если будет задан бесконечный цикл
	static void cleaner();
	// печать массива
	static void printer( int size_y = 0, int size_x = 0, MATRIX** mtrx = NULL);
	// три вида поиска
	static  void search(const int &  Case = 2);
	// вывод элемента массива
	friend ostream& operator<< (ostream& out, MATRIX& a);
	// ввод в элемент массива
	friend istream& operator>> (istream& in, MATRIX& a);
	// a = size_x, b = size_y \
	определение размера массива
	static void set_size(const int & a = 1, const int & b = 1);
public:
	// конструктор по умолчанию
	MATRIX()
	{
		if(size_x >0 && size_y>0)
		num = rand() % 51;
	}
	// метод использующий все внутренние методы(типa main)\
	 с помощью него возможно использовать все методы при \
     этом не нарушая принципы инкапсуляции
	void Mat_user();
};

// _________________________
