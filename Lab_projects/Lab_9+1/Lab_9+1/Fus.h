#pragma once
/*

������������ ������ � 10       ������������
������� 3 �������-������� (������ ��� �����, �.�. ������������, ����������) � 3 �����.
�������:
�) min() � ���������� ������������;
�) sort() � ���������� ������� �� �����������;
�) sum() � ���������� � ������� ����� �������������.
�����:
�) ��� �. min() � ��������� ���������� ��������� �����., �����., � ���������:
� � ������� �. min() ����� ������� ���� ����� (��������);
� �������� ���������� (assert()).
�) ��� �. sort():
� ������� ������1 �����������������;
� ������� ������2 ��������� ���������������;
� ������������� ������1, ��������� �. sort();
� � ����� ����������� �������� ���������� (assert()).
�)  ���  �. sum():
� ������� ������;
� � ������� sum() ����� ����� �������������;
� �������� ���������� ��������� � ���������� (assert()).
������������� ��������, ����� assert() ������ ������:
� � �. min() �������� ���� � ��������� (���� > �� ����  <);
� � �. sort()�������� ���� ��� ���������� (�.�. ����� ���������� �� ��������);
� � �. sum() ������ ������� ���������� �������������.

*/
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

template<typename T>
T minml(T* arr, int & size, const int & c = 1) {
	T m = arr[0];
	if (isdigit(m)== 4) {
		for (int i = 1; i < size; i++)
			if (c == 1 ? m > arr[i] : m < arr[i])m = arr[i];
	}
	else {
		for (int i = 1; i < size; i++)
			if (c == 1 ? m > arr[i] : m < arr[i])m = arr[i];
	}
	return m;
}
template<typename T>
T sort(T* arr, int & size, const int & c = 1) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && c == 1?arr[j - 1]> arr[j]: arr[j - 1]< arr[j]; j++)
			swap(arr[j - 1], arr[j]);
	return m;
}
template<typename T>
T sum(T* arr, int & size, const int & c = 1) {
	T m = 0;
	for (int i = 1; i < size; i++)
		if (c == 1 ? arr[i] > 0: m < arr[i])m += arr[i];
	return m;
}

