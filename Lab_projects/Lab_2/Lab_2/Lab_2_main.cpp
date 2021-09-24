#include "manufact_cl.h"

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
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 3;
	
	MANUFACTURER *mas = new MANUFACTURER[size]{ { "Oracle",1,2488000000, 31.1 },
	{ "IBM", 3 , 2392000000, 29.9 },
	{ "Microsoft", 2 ,1048000000, 13.1 }
	};
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
		system("cls");
		switch (Case) 
		{
		case 1:
			cout << "�����" << endl;
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "���������� \"=\"" << endl;
			MANUFACTURER::resize(mas, size);
			mas[size - 1] = mas[size - 2];
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		
		case 3:
			cout << "���������� \"+\"" << endl;
			MANUFACTURER::resize(mas, size);
			mas[size - 1] = mas[size - 2] + mas[size - 3];
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "���������� \"==\"" << endl;
			MANUFACTURER::print(mas, size);
			MANUFACTURER::equal(mas[size - 1], mas[size - 2]);
			MANUFACTURER::equal(mas[size - 2], mas[size - 3]);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "���������� \">>\"" << endl;
			MANUFACTURER::resize(mas, size);
			cin >> mas[size - 1];
			MANUFACTURER::print(mas, size);
			system("pause");
			system("cls");
			break;
		}
		if (Case == 6)
			break;
	}
	system("pause");
	delete[]mas;
}