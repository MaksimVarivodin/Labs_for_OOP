#include "pers_cl.h"
class Zav_kaf : protected Persona  {
protected:
	string position;		
public:
	Zav_kaf(const int & a = 0, const string & f = "", const string & d = "Заведующий кафедры")
		: Persona{ a, f }
	{
		position = d;
	}
	void print() override;
	int who()  override;
	int ask()  override;
	void init() override;
};