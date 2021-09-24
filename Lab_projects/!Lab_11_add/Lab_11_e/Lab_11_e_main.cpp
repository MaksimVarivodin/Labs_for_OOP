#include "time_cl.h"

//ЛАБОРАТОРНАЯ РАБОТА № 11Е.
/*

Создать класс Время (часы, минуты, секунды).
– Класс должен содержать гетеры и сеттеры
(методы изменения времени на заданное количество
часов, минут и секунд и вывода значений каждого поля)
с проверкой допустимости вводимых значений.
В случае недопустимых значений полей – корректно
обработать ситуацию.
– Создать функцию вывода всего объекта время на экран.
– Создать функцию подсчета разности времен двух объектов.
– Создать функцию сравнения времен двух объектов.
– Определить угол между часовой и минутной стрелками.

*/

int main() 
{
	TIME a;  
	cout << "Enter time a" << endl;
	cin >> a;
	system("pause");
	system("cls");
	cout<< "Seconds all in all: " <<a.getter()<< endl;
	cout << a<< endl;
	system("pause");
	system("cls");
	TIME b;
	cout << "Enter time b" << endl;
	cin >> b;
	system("pause");
	system("cls");
	cout << a<< endl;
	cout << b<< endl;

	cout<< "Substract: "<<endl << a.substract(b);
	if (a.is_bigger(b))
		cout << "A is bigger than B" << endl;
	else
		cout << "B is bigger than A" << endl;
	cout<< "Angle between hour and minute hands: " << a.angle_calc()<< endl;
	system("pause");
}