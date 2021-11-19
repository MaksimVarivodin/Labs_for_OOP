#include "Contacts_cl.h"
int main() {
	map<Name, Number> Contacts;
	string menu[] = {
	"Menu",
	"Print",
	"Find",
	"Filtr",
	"Delete", 
	"Exit"
	};
	for (int i = 0; i < 5; i++) {
		string a = i % 2 == 0 ? to_string(i):to_string (i+5), b = "name" + a;		
		Contacts[b] = i;
	}
	string buf ="";
	int counter = 0;
	for (;;) {
		int c = Menu_show(menu, 6);
		if (c == 5)break;
		switch (c) 
		{
		case 1: 
			for (auto p = begin(Contacts);p!= end(Contacts);p++)
			{
				cout << const_cast<Name&>(p->first).GETname() << " ";
				cout << const_cast<Number&>(p->second).GETnum() << endl;
			}
			break;
		case 2: 
			cout << "Enter Name to show: ";
			Enter_check(buf);
			//
			try
			{
				cout<< buf<< " " << Contacts.at(buf).GETnum()<< endl;
			}
			catch (const std::exception&)
			{
				cout << "Trouble! No such an element" << endl;
			}
			
			break;
		case 3: 
			cout << "Enter Letter to show: ";
			Enter_check(buf); 

			for (auto p = begin(Contacts); p != end(Contacts); p++)
			{
				if (const_cast<Name&>(p->first).GETname().find(buf)!= string::npos) {
					cout << const_cast<Name&>(p->first).GETname() << " ";
					cout << const_cast<Number&>(p->second).GETnum() << endl;
					counter++;
				}
				
			}
			cout << "Found elems: " << counter << endl;
			break;
		case 4:
			cout << "Enter Letter to delete: ";
			Enter_check(buf);
			for (auto p = begin(Contacts); p != end(Contacts); )
			{
				if (const_cast<Name&>(p->first).GETname().find(buf) != string::npos) {
					p = Contacts.erase(p);
					counter++;
				} 	
				else p++;
			}
			cout << "Deleted elems: " << counter << endl;
			break;
		}
		buf = "";
		system("pause");
		counter= 0;
	}
}