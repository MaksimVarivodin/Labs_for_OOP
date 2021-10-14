#include "zav_cl.h"

void Zav_kaf::print()
{
	cout << "ФИО: " << this->ret_fio();
	putter2();
	cout << "Возраст: " << this->ret_age();
	putter2();
	cout << "Должность: " << position;
	putter2();
}

int Zav_kaf::who()
{
	return 2;
}

int Zav_kaf::ask()
{
	return ret_age();
}

void Zav_kaf::init()
{

}
