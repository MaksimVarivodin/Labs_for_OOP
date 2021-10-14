#include "vuz_cl.h"

// creates new last elem
Persona** reservator(Persona **& cur, int & size) {

	Persona** n_arr = new Persona*[size + 1];
	if (cur != nullptr) {
		for (int i = 0; i < size; i++)
			n_arr[i] = cur[i];
		delete[] cur;
	}
	size++;
	cur = n_arr;
	n_arr = nullptr;
	return cur;
}
// functions that randomly inits last elem
Persona ** randomizer(Persona **& cur, int & size)
{
	reservator(cur, size);
	switch (rand() % 3) {
	case 0:
		cur[size - 1] = new Prepod[1];
		break;
	case 1:
		cur[size - 1] = new Student[1];
		break;
	case 2:
		cur[size - 1] = new Zav_kaf[1];
		break;
	}	
	return cur;
}

Persona ** Vuz::resize(int & size)
{
	Persona ** n_arr = new Persona*[size];
	if (Shtat != nullptr)
	{
		for (int i = 0; i < size > this->count ? this->count : size; i++)
			n_arr[i] = Shtat[i];
		delete[] Shtat;
	}
	Shtat = n_arr;
	count = size;
	return Shtat;
}


void Vuz::print()
{
	
	for (int i = 0; i < count; i++)
	{		
		Persona::putter();
		cout << i + 1;
		Persona::putter2();
		cout << "Кто: ";
		switch (Shtat[i]->who()) {
		case 1:
			cout << "Преподаватель";
			
			break;
		case 2:			
			cout << "Зав_каф";
			break;
		case 3:
			cout << "Студент";
			break;
		}
		Persona::putter2();
		Shtat[i]->print();
		cout << "Ask: ";
		cout << Shtat[i]->ask();
		Persona::putter2();	
		Persona::putter3();
	}
	Persona::putter4();
	Persona::putter();
}

void Vuz::youngsters()
{
	Prepod a;	
	bool found = false;
	Persona::putter3();
	Persona::putter4();
	Persona::putter4();
	Persona::putter(); 
	cout << "Преподаватели младше 50: ";
	for (int i = 0; i < count; i++)
	{
		if (typeid(Shtat[i][0]).name() == typeid(a).name() && Shtat[i]->ret_age() < 50) {
			Persona::putter();
			Persona::putter2();
			Shtat[i]->print();
			Persona::putter3();
			found = true;
		}
	}
	if (!found) { 
		Persona::putter2();
		cout << "Ничего не найдено. ;(";
		Persona::putter3(); 
		Persona::putter();
	}
	Persona::putter4();
	Persona::putter();
}

void Vuz::low_ac_performance()
{
    Student a;
	Persona::putter3();
	Persona::putter4();
	Persona::putter4();
	Persona::putter();
	bool found = false;
	cout << "Студенты с долгами: ";	
	for (int i = 0; i < count; i++)
	{
		if (typeid(Shtat[i][0]).name() == typeid(a).name() && Shtat[i]->ask() > 0) {
			Persona::putter();
			Persona::putter2();
			Shtat[i]->print();
			Persona::putter3();
			found = true;
		}
	}
	if (!found) {
		Persona::putter2();
		cout << "Ничего не найдено. ;(";
		Persona::putter3();		
	}
	Persona::putter4();
	Persona::putter();
}
