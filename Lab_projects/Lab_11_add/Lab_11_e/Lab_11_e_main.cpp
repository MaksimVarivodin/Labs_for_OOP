#include "time_cl.h"

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