#pragma once
#include "main_h.h"
class Persona {
protected:
	string fio;
	int age;	
	static int cols;
	static int lines;
	static int lines_i;
	void putter();// помещение в заданные начальные координаты 
	void putter2();// перенос строки(не может идти перед путтер1)
	void putter3();// добавление колонки, если последняя, переход на новую строку
	void putter4();// перенос строки
public:
	Persona(const int & a = 0, const string & f = "")
	{
		age = a;
		fio = f;
	}
	string ret_fio() { return fio; }
	int ret_age() { return age; }
	virtual void init();
	virtual void print() = 0;
	virtual int who() = 0;
	virtual int ask() = 0;
	void enul();
};