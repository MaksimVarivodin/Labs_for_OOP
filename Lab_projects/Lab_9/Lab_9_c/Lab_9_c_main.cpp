#include "person_cl.h"

int main() {
	/*

	� �. ���������� (insert());\/
	� �. ������ ���� ����� �� PERSON;\/
	� �. ������ ������ ���� �� PERSON (������ ������� ��� ������ �������);\/
	� �. �������� �� �������;\/
	� �. �������;\/
	� �. ������ �� ������� ����.\/

	*/

	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string buf = "b";
	string menu[7] = {
		"Menu:",
		"Fill",
		"Add",
		"Print",
		"Find",
		"Delete",
		"Exit"
	}, 
	prnt_menu[5]{
		"Choose print type:", 
		"Print everything", 
		"Print name",
		"Print age",
		"Exit"
	},
	srch_menu[4]{
	"Choose search type to search:", 
	"Integer", 
	"String", 
	"Exit"	
	}, 
		names[20] = {
		"������ ������",
		"������ �������",
		"���� �����",
		"������� ����������",
		"������ �������",
		"����� �����",
		"������ �������",
		"������� �������",
		"������ ���������",
		"�������� ������",
		"������ ������",
		"��������� ������",
		"�������� ��������",
		"������� ���������",
		"�������� ������",
		"�������� ��������",
		"��������� ��������",
		"��������� �������",
		"�������� ��������",
		"����� ��������"

		/* */ };
	int numbs[20], i = 0;
	for each (int &var in numbs)
	{
		var = i;
		i++;
	}
	Staff a{};
	for (;;) {
		switch (Menu_show(menu, 7)) {
		case 1:
			a.filler(names, numbs);
			break;
		case 2:
			a.add_master({names[rand()%20], numbs[rand() % 20] });
			break;
		case 3:
			try
			{
				for (;;) {
					switch (Menu_show(prnt_menu, 5)) {
					case 1:
						a.printer();
						break;
					case 2:
						a.printer(1);
						break;
					case 3:
						a.printer(2);
						break;
					case 4:
						stoi(buf);
						break;

					}
					system("pause");
				}
			}
			catch (const std::exception&)
			{
			}			
			break;
		case 4:
			try
			{
				for (;;) {
					string buf2 = "";
					int b_i = 0;
					switch (Menu_show(srch_menu, 4)) {
					case 1:
						cout << "Enter a string or symbol to find and delete an elem: ";

						Enter_check(b_i, 20, 0);
						a.search_machine(b_i);
						break;
					case 2:
						cout << "Enter a number to find and delete an elem: ";

						Enter_check(buf2);
						a.search_machine(buf2);
						break;
					case 3:
						stoi(buf);
						break;
					}
					system("pause");
				}
			}
			catch (const std::exception&)
			{
			}
			break;
		case 5:
			try
			{			
					string buf2 = "";
					cout << "Enter a string or symbol to find and delete an elem: ";
					Enter_check(buf2);
					a.cutter(buf2);	
					
			}
			catch (const std::exception&)
			{
			}
			break;
		case 6:
			return 0;
		}
		system("pause");
	}

}