#include "zav_cl.h"

void Zav_kaf::print()
{
	cout << "���: " << this->ret_fio();
	putter2();
	cout << "�������: " << this->ret_age();
	putter2();
	cout << "���������: " << position;
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
