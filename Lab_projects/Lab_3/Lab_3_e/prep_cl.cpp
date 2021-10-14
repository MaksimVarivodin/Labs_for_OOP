#include "prep_cl.h"

void Prepod::init()
{
	const int size = 9;
	string subj [size] = {
	    "Математика", "Английский", "Искусство", "Компьютерный дизайн", 
		"Уроки фотографии", "Введение в Точные Науки",
		"Физика", "Испанский", "Французкий"
	};
	subject = subj[rand()%9];
	degree = rand() % 3;
}

void Prepod::print()
{
	
	cout << "ФИО: " << this->ret_fio();
	putter2();
	cout << "Возраст: " << this->ret_age();
	putter2();
	cout << "Предмет: " << subject;
	putter2();
	cout << "Степень: ";
	switch (ask()) {
	case 1:
		cout << "КТН" ;
		break;
	case 2:
		cout << "ДТН";
		break;
	default:
		cout << "Нет";
		break;
	}
	putter2();
	
}

int Prepod::who()
{
	return 1;
}

int Prepod::ask()
{
	return degree;
}
