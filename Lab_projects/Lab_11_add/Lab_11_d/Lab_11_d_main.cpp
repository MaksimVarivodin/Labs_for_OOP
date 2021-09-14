#include "multi_cl.h" // ��������� ������������� ����� � �������
int main() {
	srand(time(NULL));
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

	MULTIPLICITY a;// (����������� �� ���������)
	cout << a;
	cout << a.max_val()<< endl;
	system("pause");
	system("cls");
	
	MULTIPLICITY b{ 100, -100, 100};// (����������� � ����������)
	cout << b;
	cout<< b.max_val() << endl;
	system("pause");
	system("cls");

	MULTIPLICITY c{b};// (����������� �����������)
	cout << c;
	cout<< c.max_val() << endl;
	system("pause");
	system("cls");

	MULTIPLICITY d{ 100, -100, 100 };// (����������� � ����������)
	for (;;)
	{
		cout << "Multiplicity b:" << endl << b<< endl;
		cout << "Multiplicity d:" << endl << d<< endl<< endl;		
		cout << "Enter a number:" << endl << "1- intersection";
		cout << endl << "2- merge" << endl;
		cout << "3- substract" << endl;
		cout << "4- symmetric difference" << endl;
		cout << "any letter - break;" << endl;
		int k;
		cin >> k;
		if (!cin)
			break;
		switch (k)
		{
		case 1:
			cout << "INTERSECTION: "<< endl << b.intersection(d);
			break;
		case 2:
			cout << "MERGE: "<< endl << b.merge(d);
			break;
		case 3:
			cout << "SUBSTRACT - choose how\n";
			cout << "1 - [ b - d ]"<< endl;
			cout << "2 - [ d - b ]" << endl;
			int k2;
			cin >> k2;
			switch (k2)
			{
			case 1:
				cout << "SUBSTRACT:  b - d" << endl << b.substract(d);
				break;
			case 2:
				cout << "SUBSTRACT:  d - b" << endl << d.substract(b);
				break;
			default:cout << "Retry enter the numbers"<< endl;
				break;
			}
			break;
		case 4:
			cout<<"SYMMETRIC DIIFERENCE: "<<endl << b.symmetric_dif(d);
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}