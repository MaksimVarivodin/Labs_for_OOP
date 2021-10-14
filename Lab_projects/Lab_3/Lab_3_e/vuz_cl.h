#include "stud_cl.h"
#include "zav_cl.h"
#include "prep_cl.h"


// method that adds one person and randomly initializes it with any inherited class
Persona** randomizer(Persona**& cur, int& size);
class Vuz :public Persona, public  Student, public Zav_kaf, public Prepod{
protected:
	int who() override {	return 0;}
	int ask() override{ return -1; }
	friend Persona** randomizer(Persona**& cur, int& size);	
	// количество работников штата
	int count;
	// указатель на штат
	Persona** Shtat;
	// автоматическое изменение размера
	Persona** resize(int& size);
public:
	Vuz(const int & count0)
	{
		count = 0;
		Shtat = nullptr;
		for (int i = 0; i < count0; i++) {
			Shtat = randomizer(Shtat, count);
			Shtat[i]->Persona::init();// имя фамилия фозраст
			Shtat[i]->init();// инфа генерящаяся для каждого класса отдельно
		}
	}
	~Vuz() {
		for (int i = 0; i < count; i++)
			delete[]Shtat[i];
		delete[]Shtat;
		count = 0;
	}
	void print() override;
	void youngsters();
	void low_ac_performance();
	void enul() {
		Persona::enul();
	}
};
