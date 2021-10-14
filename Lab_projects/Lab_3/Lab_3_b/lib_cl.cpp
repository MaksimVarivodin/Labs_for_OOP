#include "lib_cl.h"

void Book::show()
{
	cout << "Autor name: " << a_name << endl;
	cout << "Book name: " << b_name << endl;
	cout << "Quantity of pages: " << pages << endl;
}

void Library::show()
{
	cout << "Catalogue number: " << cat << endl;
	Book::show();
	cout << "Presence: ";
	if (present)
		cout << "present" << endl;
	else
	{
		cout << "is_taken" << endl;
	}

}

void print(Library * a, const int & size)
{
	for (int k = 0; k < size; k++) {
		a[k].show();
		cout << endl;
	}
}
