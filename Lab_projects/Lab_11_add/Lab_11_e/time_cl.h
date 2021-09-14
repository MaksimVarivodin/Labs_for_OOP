#pragma once
#define _CRT_SECURE_NO_WARNINGS // ��������� �������������� � ��������������
#include <iostream> 
#include <string> // ��� ������ �� ��������
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������ ������� time()
#include <iomanip>
using namespace std;

//������������ ������ � 11�.
/*

������� ����� ����� (����, ������, �������).
� ����� ������ ��������� ������ � ������� 
(������ ��������� ��������� �������� ����������
�����, ����� � ������ � ������ �������� ������� ����) 
� ��������� ������������ �������� ��������.
� ������ ������������ ������������� � ��������� 
���������� ��������.
� ������� ������� ������ ����� ������� ����� �� �����.
� ������� ������� �������� �������� ������ ���� ��������.
� ������� ������� ��������� ������ ���� ��������.
� ���������� ���� ����� ������� � �������� ���������.

*/
class TIME
{
	time_t sec;
	// ������
	
	tm getter();
	time_t difference();
	bool is_bigger(const TIME & other);
	int angle_calc(const TIME & other);
	friend ostream& operator<< (ostream & out, TIME & a);
	friend istream& operator>> (istream & in, TIME & a);
};