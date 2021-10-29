#include "country_cl.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int size = 0;
	cout << "������� ��������: ";
	if (Enter_check(size) == -1)return 0;
	Country* World = new Country[size];
	for (int i = 0; i < size; i++) {
		string name = "NAME";
		string num = to_string(rand() % size + 1);
		name += num;
		string capital = "CAPIT";
		capital += num;
		int pop = 100000 * stoi(num), ar = 100 * stoi(num);
		World[i](name, capital, pop, ar);
	}
	for (;;) {
		system("cls");
		int ent = 0;
		string * menu = new string[5]{
		"����", "1- ������", "2- ����������", "3- ���������", "4- �����"
		};
		string * menu2 = new string[5]{
			"����", "1- ��������", "2- �������", "3- ���������", "4- ������� ����������"
		};
		string name;
		string capital;
		int population;
		int area;
		int c = Menu_show(menu, 5);
		switch (c)
		{
		case 1:
			Print(World, size); 
			break;
		case 2:
			Print(World, size);
			Sort(World, size);
			cout << "����� ����������: " << endl;
			Print(World, size);
			break;
		case 3:
			Print(World, size);
			cout << "�������� �������: " << endl;
			Enter_check(ent, size);
			ent--;
		switch (Menu_show(menu2, 5)) {
		case 1:
			cout << "������� �������� ������: " << endl;
			getline(cin , name);
			World[ent](name, World[ent].GETcapital(), World[ent].GETpopulation(), World[ent].GETarea());
			break;
		case 2:
			cout << "������� �������� �������: " << endl;
			getline(cin , capital);
			World[ent](World[ent].GETname(), capital, World[ent].GETpopulation(), World[ent].GETarea());
			break;
		case 3:
			cout << "������� ���������� ���������: " << endl;
			Enter_check(population, 1000000);
			World[ent](World[ent].GETname(), World[ent].GETcapital(), population, World[ent].GETarea());
			break;
		case 4: 
			cout << "������� ������� ���������: " << endl;
			Enter_check(area);
			World[ent](World[ent].GETname(), World[ent].GETcapital(), World[ent].GETpopulation(), area);

			break;
		}
		Print(World, size);		
			break;
		}
		if (c == 4) break;
		system("pause");		
	}	
	delete[] World;
}