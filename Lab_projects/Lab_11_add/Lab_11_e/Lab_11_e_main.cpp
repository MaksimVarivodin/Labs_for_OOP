#include "time_cl.h"

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

int main() 
{
	TIME a;  
	cout << "Enter time a" << endl;
	cin >> a;
	system("pause");
	system("cls");
	cout<< "Seconds all in all: " <<a.getter()<< endl;
	cout << a<< endl;
	system("pause");
	system("cls");
	TIME b;
	cout << "Enter time b" << endl;
	cin >> b;
	system("pause");
	system("cls");
	cout << a<< endl;
	cout << b<< endl;

	cout<< "Substract: "<<endl << a.substract(b);
	if (a.is_bigger(b))
		cout << "A is bigger than B" << endl;
	else
		cout << "B is bigger than A" << endl;
	cout<< "Angle between hour and minute hands: " << a.angle_calc()<< endl;
	system("pause");
}