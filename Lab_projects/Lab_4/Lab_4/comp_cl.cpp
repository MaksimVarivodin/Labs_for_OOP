#include "comp_cl.h"
MANUFACTURER & COMPANY::operator[](int index)
{
	if (index - 1 < 0 || index - 1 >= size) { 
		cout << "������� ������ ������ �������" << endl;
		return arr[0]; 
	}
	return arr[index - 1];
}
void COMPANY::shapka()
{
	cout << "  ________________________________________________________________________________________\n";
	cout << " /                               ����� - ������������� ����                               \\\n";
	cout << " ------------------------------------------------------------------------------------------\n";
	cout << "|       �����       | ����������. ���������  | ������� ����� ������� ($) | ����� ����� (%) |\n";
	cout << " ------------------------------------------------------------------------------------------\n";
}
void COMPANY::equal(MANUFACTURER a, MANUFACTURER b) {
	cout << endl;
	cout << a;
	cout << "�" << endl;
	cout << b;
	if (a == b) {
		cout << "����� " << endl;
	}
	else
		cout << "�� ����� " << endl;
}
void COMPANY::resize() {
	MANUFACTURER* new_a = new MANUFACTURER[size + 1];
	if (size > 0) {
		for (int i = 0; i < size; i++)
			new_a[i] = arr[i];
	}
	delete[]arr;
	arr = new_a;
	size++;
	new_a = nullptr;
}
void COMPANY::del() {
	MANUFACTURER* new_a = new MANUFACTURER[size - 1];
	if (size > 0) {
		for (int i = 0; i < size - 1; i++)
			new_a[i] = arr[i];
	}
	delete[]arr;
	arr = new_a;
	size--;
	new_a = nullptr;
}

void COMPANY::sort()
{
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0 && arr[j - 1].GetCompany()> arr[j].GetCompany(); j--) {
			MANUFACTURER buf = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = buf;
		}
	}
}

void COMPANY::print()
{
	shapka();
	for (int i = 0; i < size; i++)
		cout << arr[i];
}