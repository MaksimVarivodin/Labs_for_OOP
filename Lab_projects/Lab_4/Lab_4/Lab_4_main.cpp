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
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	COMPANY a;

	int Case = 0,num = 0 ;
	for (;;) {
		cout << "�������� �����:" << endl;
		cout << "1- �����" << endl;
		cout << "2- ���������� \"=\"" << endl;
		cout << "3- ���������� \"+\"" << endl;
		cout << "4- ���������� \"==\"" << endl;
		cout << "5- ���������� \">>\"" << endl;
		cout << "6- ����� �������� ������� �� ���������� �������" << endl;
		cout << "7- �������� ����������" << endl;
		cout << "8- ����������" << endl;
		cout << "9- �����" << endl;
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
		case 6:
			cout << "����� �������� ������� �� ���������� �������" << endl;		
			cin >> num;
			cout << a[num];
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "�������� ����������" << endl;
			a.del();
			a.print();
			cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "����������" << endl;
			a.sort();
			a.print();
			system("pause");
			system("cls");
			break;
		}
		if (Case == 9)
		{
			system("pause");
			break;
		}
	}
}