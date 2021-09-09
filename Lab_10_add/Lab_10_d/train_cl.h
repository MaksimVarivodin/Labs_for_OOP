#pragma once
#define _CRT_SECURE_NO_WARNINGS // отключаем предупреждения о небезопасности
#include <iostream> 
#include <ctime> // эти два для работы с временем
#include <chrono> 
#include <string> // для работы со строками
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
using namespace std;

// ЛАБОРАТОРНАЯ РАБОТА № 10Д.
/*

Создайте класс с именем train,
содержащую поля:
*название пункта назначения, \/
*номер поезда,\/
*время отправления.\/
Ввести данные в массив из пяти элементов
типа train, упорядочить элементы по номерам
поездов.\/
Добавить возможность вывода информации
о поезде, номер которого введен пользователем.\/
Добавить возможность сортировки массив по пункту
назначения\/,
причем поезда с одинаковыми пунктами
должны быть упорядочены по времени отправления.\/

*/

class TRAIN {
	static TRAIN* mas;
	static int count;
	string go_to;
	int id;
	time_t dep_time;
	friend ostream& operator<< (ostream& out, TRAIN& a);
	friend istream& operator>> (istream& in, TRAIN& a);

	TRAIN(const string & a, const int & h, const int & m) {
		count++;
		id = count;
		this->go_to = a;
		// структура даты и времени
		tm timeinfo;
		// используя структуру, меняем дату и время
		time(&dep_time);
		timeinfo = *localtime(&dep_time);
		timeinfo.tm_hour = h;
		timeinfo.tm_min = m;
		// пользуясь функуцией эмкатайм() считаем количество секунд прошедших января 1900-го
		dep_time = mktime(&timeinfo);
	};

	static void clean();
	static void create();
	static void sort(const int Case = 0);
	static void setter(const int Case = 0);
	static void prnt(const int & num = 0);
	static void swap(TRAIN & a, TRAIN &b);
	TRAIN operator= (TRAIN & other);
public:
	void tr_user();
	TRAIN() {
		count++;
		id = count;
	};
};
// _________________________
