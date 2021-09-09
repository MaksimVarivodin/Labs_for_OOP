#include "train_cl.h"
TRAIN* TRAIN::mas = NULL;
int TRAIN::count = 0;
// * ������������� �������� ������
ostream & operator<<(ostream & out, TRAIN & a)
{
	// TODO: �������� ����� �������� return
	cout << "Place to go: " << a.go_to << endl;
	cout << "Number of a train: " << a.id << endl;
	tm timeinfo = *localtime(&a.dep_time);
	cout << "Departure time: " << timeinfo.tm_hour << " : " << timeinfo.tm_min << endl;
	return out;
}
// * ������ ������� ��� ������ ��� ���������� ��������
void TRAIN::prnt(const int & num)
{
	switch (num)
	{
	case 0:
		for (int i = 0; i < 5; i++)
			cout << TRAIN::mas[i];
	default:
		for (int i = 0; i < 5; i++)
			if (TRAIN::mas[i].id == num)
				cout << TRAIN::mas[i];
		break;
	}

}
// * ������� �������
void TRAIN::clean()
{
	count = 0;
	if (mas != NULL)
	{
		delete[] mas;
		mas = NULL;
	}
}
// * �������� �������
void TRAIN::create()
{
	mas = new TRAIN[5];
}
// * ���������� �� ������ � �� ������ ����������(���� ��� ���������, �� �� �����������)
void TRAIN::sort(const int Case)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i; j++) {

			switch (Case)
			{
			case 1:

				if (mas[i].go_to < mas[i + 1].go_to)
					swap(mas[i], mas[i + 1]);
				else if (mas[i].go_to == mas[i + 1].go_to)
				{
					if (mas[i].dep_time < mas[i + 1].dep_time)
						swap(mas[i], mas[i + 1]);
				}
				break;

			default:
				if (mas[j].id < mas[j + 1].id) {
					// ������ �������� �������
					swap(mas[j], mas[j + 1]);
				}

				break;
			}

		}
	}

}
// * ����� ������ ���������� �������
void TRAIN::swap(TRAIN & a, TRAIN & b)
{
	TRAIN buf = a;
	a = b;
	b = buf;

}
// * ���������� ��������� �����
TRAIN TRAIN::operator=(TRAIN & other)
{
	this->dep_time = other.dep_time;
	this->go_to = other.go_to;
	this->id = other.id;
	return *this;
}
// * ����� ������� ����������
void TRAIN::setter(const int Case)
{


	switch (Case) {
	case 1:
		clean();
		create();
		for (int i = 0; i < 5; i++)
			cin >> TRAIN::mas[i];
		break;
	default:
		clean();
		TRAIN::mas = new TRAIN[5]{
			{ "dest2", 5, 30 },
			{ "dest1", 6, 30 },
			{ "dest3", 7, 30 },
			{ "dest5", 8, 30 },
			{ "dest4", 9, 30 }
		};

		break;

	}
}
// * ���������� ��������� �����
istream & operator>>(istream & in, TRAIN & a)
{
	// TODO: �������� ����� �������� return
	cout << "Enter destination:";
	cin >> a.go_to;
	// ��������� ���� � �������
	tm timeinfo;

	// ��������� ���������, ������ ���� � �����
	time(&a.dep_time);
	timeinfo = *localtime(&a.dep_time);
	cout << "Enter your hour: ";
	cin >> timeinfo.tm_hour;
	cout << endl << "Enter your minute: " << endl;
	cin >> timeinfo.tm_min;

	// ��������� ��������� ��������() ������� ���������� ������ ��������� ������ 1900-��
	a.dep_time = mktime(&timeinfo);
	return in;

}
// * ��������� ����� ����� ������������ ������������ ������
void TRAIN::tr_user()
{
	TRAIN a;
	// ����� ��������� ������ �� ���������
	// �� ���� ����������� �������� �������� (1)
	// � ����� ������ ����� ����� ������� �������
	a.setter();
	// ����� ��������� ���������� �� ���������
	// �� ���� ����������� �������� �������� (1)
	// � ����� ������������� ����� �� ������ ����������
	cout << "ARRAY of TRAINS before sorting" << endl;
	a.prnt();
	system("pause >> void");
	system("cls");

	a.sort();
	cout << "ARRAY of TRAINS after sorting" << endl;
	a.prnt();
	system("pause >> void");
	system("cls");
	cout << "Enter number of a train to show: " << endl;
	int b;
	cin >> b;
	// ����� ��������� ������ � ����������
	// �� ���� ����������� �� ���������� ��������
	// � ����� ���������� ����� ���� ������
	a.prnt(b);
	system("pause >> void");
	system("cls");
	cout << "ARRAY of TRAINS after sorting by destination" << endl;
	a.sort(1);
	a.prnt();
	system("pause >> void");
	system("cls");
}