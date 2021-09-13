#pragma once
#define _CRT_SECURE_NO_WARNINGS // ��������� �������������� � ��������������
#include <iostream> 
#include <string> // ��� ������ �� ��������
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������ ������� time()
#include <iomanip>
using namespace std;


// ������������ ������ � 11�.
/*

����������� ����� ��� ������������� ������� ��������� ����� (�������� �� �����������).
� ���������� ����������� � ����� ����������� (���������� ���������, ����������� � 
������������ � ��������� ������������ �����), 
������� ����� �������� ��������� (����������� � �����������).\/
� ���������� �����������, ������� ���������� 
��������� �� 10 ��������� � ��������� [-20; 20] (����������� �� ���������).\/
� ���������� �����������, ������� �������� � 
����� ��������� �������� ������� ���������, �� ����������� �������� �������� (����������� �����������).\/
� ������� �������, ������� ������� ������������ �������� � ���������.
� ������� ������� ��� ���������� 
�����������, \/
�����������, \/
�������� \/
� ������������� ����� ���� �������� ��������.\/

*/


template <typename T>
void add_one_arr(T*&arr, int& size) {
	T* new_arr = new T[size + 1];
	if (arr != NULL) {
		for (int i = 0; i < size; i++)
			new_arr[i] = arr[i];
		delete[]arr;
	}
	size++;
	arr = new_arr;
}
template <typename T>
void del_one_arr(T*&arr, int& size) {
	T* new_arr = new T[size + 1];
	if (arr != NULL) {
		for (int i = 0; i < size; i++)
			new_arr[i] = arr[i];
		delete[]arr;
	}
	size++;
	arr = new_arr;
}
class MULTIPLICITY
{	
	int* mltplct = NULL;
	int count = 0;
	int max = 0;
	int min = 0;

    // ��������� ������� ���������� ������ 
	template <typename T> friend void add_one_arr(T*&arr, int&size);
	template <typename T> friend void del_one_arr(T*&arr, int&size);

public:
	// ����� �����������
	MULTIPLICITY(const int & count)
	{
		this->count = count;
		this->mltplct = new int[count];
	}
	// ������������� ��� ������ �������
	MULTIPLICITY(const int * arr, const int & count0) : MULTIPLICITY(count0)
	{
		this->max = arr[0];
		this->min = max;
		for (int i = 0; i < count; i++)
		{
			this->mltplct[i] = arr[i];
			if (max < mltplct[i])
			{
				max = mltplct[i];
			}
			if (min > mltplct[i])
			{
				min = mltplct[i];
			}			
		}
	}
	// ����������� � �����������
	MULTIPLICITY(const int & max, const int & min, const int & count0) : MULTIPLICITY(count0) {
		// ��������� ������������ ������� �������� � ��������� ����� ���������� ����������� ���������
		int j = rand() % (max - count - min + 1) + min;
		for (int i = 0; i < this->count; i++)
		{
			mltplct[i] = j;
			j++;
		}
		this->max = mltplct[0];
		this->min = this->max;
		for (int i = 0; i < count; i++)
		{
			if (this->max< mltplct[i])
			{
				this->max = mltplct[i];
			}
			if (this->min > mltplct[i])
			{
				this->min = mltplct[i];
			}
		}
	}
	// ����������� �� ���������
	MULTIPLICITY() :MULTIPLICITY(20, -20, 10) {}
	// ����������� �����������
	MULTIPLICITY(const MULTIPLICITY & other):MULTIPLICITY(other.count) {		
		this->max = other.max;
		this->min = other.min;
		for (int i = 0; i < other.count; i++)
			this->mltplct[i] = other.mltplct[i];
	}
	// ����� ������������� ��������
	int max_val();
	// �����������
	MULTIPLICITY intersection( const MULTIPLICITY& b);
	// �������������� ��������
	MULTIPLICITY symmetric_dif( const MULTIPLICITY& b);
	// ��������
	MULTIPLICITY substract( const MULTIPLICITY&b);
	// �����������
	MULTIPLICITY merge( const MULTIPLICITY& b);
	// ������������� �������� ������
    friend ostream&  operator<<( ostream & out, const MULTIPLICITY & a);
};