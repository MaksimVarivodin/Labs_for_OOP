#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <map>
using namespace std;
/*

������������ ������ �9�
������������� �������� � ���������� map.\/
������� ����� PERSON (name, age):\/
� ����, ��� ��� name, ��� ��� age (�������� ��� �������);\/
� get_name(), get_age();\/
� ����������� �������� <  � �. ��������� ��� �������������� �� name;\/
� ����������� �������� () � ������� ��� �������������� �� age.\/
������� ����� STAFF ��� ������ � ������� PERSON.\/
� ������ STAFF:
� �. ���������� (insert());\/
� �. ������ ���� ����� �� PERSON;\/
� �. ������ ������ ���� �� PERSON (������ ������� ��� ������ �������);\/
� �. �������� �� �������;\/
� �. �������;\/
� �. ������ �� ������� ����.\/
� ������ STAFF ������� ��� ���������� map (��� �������) 
��� ���������� �� ����� (��������� �. ���������) �
��� ���������� �� �������� (��������� �������).\/

*/

// ������� �������� �����
void Enter_check(int & a, const int & max, const int & min);

void Enter_check(string & a);

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


void �_gray(const string & a);

void Choose(const string & a);

int Menu_show(const string  arr[], const int & size);

class Staff {

public:
class Person {
	string name;
	int age;
public:
	Person(const string & n) :name(n) {};
	Person(const int & a) :age(a) {};
	Person(const string &n = "", const int& a = 0 ): name(n), age(a) {};	
	string GETname() { return name; }
	int GETage() { return age; }
	friend bool operator>(const Person& a, const Person& b) {
		return a.name > b.name;
	}
	friend bool operator<(const Person& a, const Person& b) {
		return a.name < b.name;
	}
	bool operator()(const Person& a, const Person& b)const {
		return a.age < b.age;
	}
};
private:
	map<Person, int> stff1;
	map<Person, int, Person> stff2;
public:
	Staff()
	{
	}
	void filler(string a[20], int b[20]);
	void printer(const int& c = 0);
	void cutter(const string & a);
	void add_master(const Person & a);
	void search_machine(const int & a);
	void search_machine(const string & a);
};
