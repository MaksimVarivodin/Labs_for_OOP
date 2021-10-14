#include "pers_cl.h"
void resize(int*&, int&);
class Student : protected Persona {
	 friend void resize(int*&, int&); 
protected:
	int* Mas;
	int size;		
public:
	Student(const int & a = 0, const string & f = "", const int& size0 = 0) :Persona{ a, f }
	{
		size = size0;
		Mas = nullptr;
	}
	void init() override;
	int who() override;
	int ask() override;
	void print() override;
	~Student() {
		delete[]Mas;
	}
};
