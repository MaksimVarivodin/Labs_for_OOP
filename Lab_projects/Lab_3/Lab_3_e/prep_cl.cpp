#include "prep_cl.h"

void Prepod::init()
{
	const int size = 9;
	string subj [size] = {
	    "����������", "����������", "���������", "������������ ������", 
		"����� ����������", "�������� � ������ �����",
		"������", "���������", "����������"
	};
	subject = subj[rand()%9];
	degree = rand() % 3;
}

void Prepod::print()
{
	
	cout << "���: " << this->ret_fio();
	putter2();
	cout << "�������: " << this->ret_age();
	putter2();
	cout << "�������: " << subject;
	putter2();
	cout << "�������: ";
	switch (ask()) {
	case 1:
		cout << "���" ;
		break;
	case 2:
		cout << "���";
		break;
	default:
		cout << "���";
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
