#include "comp_cl.h"
MANUFACTURER & COMPANY::operator[](int index)
{
	if (index - 1 < 0 || index - 1 >= size) { 
		cout << "Неверно введен индекс массива" << endl;
		return arr[0]; 
	}
	return arr[index - 1];
}
void COMPANY::shapka()
{
	cout << "  ________________________________________________________________________________________\n";
	cout << " /                               Фирмы - производители СКБД                               \\\n";
	cout << " ------------------------------------------------------------------------------------------\n";
	cout << "|       Фирма       | Количество. продуктов  | Годовой объем продажи ($) | Часть рынка (%) |\n";
	cout << " ------------------------------------------------------------------------------------------\n";
}
void COMPANY::equal(MANUFACTURER a, MANUFACTURER b) {
	cout << endl;
	cout << a;
	cout << "и" << endl;
	cout << b;
	if (a == b) {
		cout << "равны " << endl;
	}
	else
		cout << "не равны " << endl;
}
void COMPANY::resize() {
	MANUFACTURER* new_a = new MANUFACTURER[size + 1];
	if (size > 0) {
		for (int i = 0; i < size; i++)
			new_a[i] = arr[i];
	}
	delete[]arr;
	arr = new_a;
	size++;
	new_a = nullptr;
}
void COMPANY::print()
{
	shapka();
	for (int i = 0; i < size; i++)
		cout << arr[i];
}