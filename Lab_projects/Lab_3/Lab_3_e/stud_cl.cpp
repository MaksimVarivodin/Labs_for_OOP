#include "stud_cl.h"

void Student::init()
{
	resize(this->Mas, size);
	for (int i = 0; i < size; i++)
		Mas[i] = rand() % 5 + 1;
}

int Student::who()
{
	return 3;
}

int Student::ask()
{
	int a = 0;
	for (int i = 0; i < size; i++)
		Mas[i] == 2 ? a++ : a = a;
	return a;
}

void Student::print()
{
	cout << "ФИО: " << this->ret_fio();
	putter2();
	cout << "Возраст: " << this->ret_age();
	putter2();
	cout << "Оценки: ";
	putter2();
	for (int i = 0; i < size; i++) {
		cout << Mas[i] << " ";
		if(i==9)putter2();
	}
	putter2();
}

void resize(int *&arr, int& size)
{
	size = rand()%(20) + 1;
	arr = new int[size];
}
