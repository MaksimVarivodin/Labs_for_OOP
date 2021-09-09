#pragma once
#define _CRT_SECURE_NO_WARNINGS // ��������� �������������� � ��������������
#include <iostream> 
#include <ctime> // ��� ��� ��� ������ � ��������
#include <chrono> 
#include <string> // ��� ������ �� ��������
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������� time()
using namespace std;

// ������������ ������ � 10�.
/*

�������� ����� � ������ train,
���������� ����:
*�������� ������ ����������, \/
*����� ������,\/
*����� �����������.\/
������ ������ � ������ �� ���� ���������
���� train, ����������� �������� �� �������
�������.\/
�������� ����������� ������ ����������
� ������, ����� �������� ������ �������������.\/
�������� ����������� ���������� ������ �� ������
����������\/,
������ ������ � ����������� ��������
������ ���� ����������� �� ������� �����������.\/

*/

class TRAIN {
	static TRAIN* mas;
	static int count;
	string go_to;
	int id;
	time_t dep_time;
	friend ostream& operator<< (ostream& out, TRAIN& a);
	friend istream& operator>> (istream& in, TRAIN& a);

	TRAIN(const string & a, const int & h, const int & m) {
		count++;
		id = count;
		this->go_to = a;
		// ��������� ���� � �������
		tm timeinfo;
		// ��������� ���������, ������ ���� � �����
		time(&dep_time);
		timeinfo = *localtime(&dep_time);
		timeinfo.tm_hour = h;
		timeinfo.tm_min = m;
		// ��������� ��������� ��������() ������� ���������� ������ ��������� ������ 1900-��
		dep_time = mktime(&timeinfo);
	};

	static void clean();
	static void create();
	static void sort(const int Case = 0);
	static void setter(const int Case = 0);
	static void prnt(const int & num = 0);
	static void swap(TRAIN & a, TRAIN &b);
	TRAIN operator= (TRAIN & other);
public:
	void tr_user();
	TRAIN() {
		count++;
		id = count;
	};
};
// _________________________
