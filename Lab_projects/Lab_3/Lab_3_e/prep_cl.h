#include "pers_cl.h"
class Prepod : protected Persona {
protected:
	string subject;
	int degree;
public:
	Prepod(const int & a = 0, const string & f = "", const int & d1 = 0, const string & d2 = "")
		: Persona{ a, f }
	{
		subject = d2;
		degree = d1;
	}
	void init() override;
	void print() override;
	int who()  override;
	int ask()  override;
};