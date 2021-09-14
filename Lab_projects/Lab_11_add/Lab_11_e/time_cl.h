#pragma once
#define _CRT_SECURE_NO_WARNINGS // отключаем предупреждени€ о небезопасности
#include <iostream> 
#include <string> // дл€ работы со строками
#include <cstdlib> // дл€ функций rand() и srand()
#include <ctime> // дл€ работы функции time()
#include <iomanip>
using namespace std;

//ЋјЅќ–ј“ќ–Ќјя –јЅќ“ј є 11≈.
/*

—оздать класс ¬рем€ (часы, минуты, секунды).
Ц  ласс должен содержать гетеры и сеттеры 
(методы изменени€ времени†на заданное количество
часов, минут и секунд и вывода значений каждого пол€) 
с проверкой допустимости вводимых значений.
¬ случае недопустимых значений†полей Ц корректно 
обработать ситуацию.
Ц —оздать функцию вывода всего объекта врем€ на экран.
Ц —оздать функцию подсчета разности времен двух объектов.
Ц —оздать функцию сравнени€ времен двух объектов.
Ц ќпределить угол между часовой и минутной стрелками.

*/
class TIME
{
	time_t sec;
	// сеттер
	
	tm getter();
	time_t difference();
	bool is_bigger(const TIME & other);
	int angle_calc(const TIME & other);
	friend ostream& operator<< (ostream & out, TIME & a);
	friend istream& operator>> (istream & in, TIME & a);
};