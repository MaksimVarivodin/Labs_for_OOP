#include "comp_cl.h"

//������������ ������ �2 \
���������� ���������� � ����� �++
/*
������� � ���������� ���������� ������� � ������������ ������ �10 (����� I),
�� ��������� ������ ���� ���������� � �������������� ������,
���������� ������������� ������� ������� � ����� ������
(������� get() � set()) � ���������� ����������� ��������� ���������:

������������;
�������� (� ������ ���������� ����� �������� ���������� ��� ������������);
������������;
��������� ����;
��������� �����.
*/

// Example:
/*



Oracle                         1 	               2488000000 	           31.1
IBM 	                       3 	               2392000000 	           29.9
Microsoft 	                   2 	               1048000000 	           13.1
����������: �� ������ Gartner Group �� 1999�
*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	COMPANY a;
	int Case = 0;
	for (;;) {
		cout << "�������� �����:" << endl;
		cout << "1- �����" << endl;
		cout << "2- ���������� \"=\"" << endl;
		cout << "3- ���������� \"+\"" << endl;
		cout << "4- ���������� \"==\"" << endl;
		cout << "5- ���������� \">>\"" << endl;
		cout << "6- �����" << endl;
		cin >> Case;
		if (cin.fail())break;
		system("cls");
		switch (Case)
		{
		case 1:
			cout << "�����" << endl;
			a.print();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "���������� \"=\"" << endl;
			a.resize();
			a[a.r_s()] = a[a.r_s() - 1];
			a.print();
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "���������� \"+\"" << endl;
			a.resize();
			a[a.r_s()] = a[a.r_s() - 1] + a[a.r_s() - 2];
			a.print();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "���������� \"==\"" << endl;
			a.print();
			a.equal(a[a.r_s()], a[a.r_s() - 1]);
			a.equal(a[a.r_s() -1], a[a.r_s() - 2]);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "���������� \">>\"" << endl;
			a.resize();
			cin >> a[a.r_s()];
			a.print();
			system("pause");
			system("cls");
			break;
		}
		if (Case == 6)
			break;
	}
	system("pause");
}