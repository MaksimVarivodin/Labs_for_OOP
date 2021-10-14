#pragma once
#include "main_h.h"
class Persona {
protected:
	string fio;
	int age;	
	static int cols;
	static int lines;
	static int lines_i;
	void putter();// ��������� � �������� ��������� ���������� 
	void putter2();// ������� ������(�� ����� ���� ����� ������1)
	void putter3();// ���������� �������, ���� ���������, ������� �� ����� ������
	void putter4();// ������� ������
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