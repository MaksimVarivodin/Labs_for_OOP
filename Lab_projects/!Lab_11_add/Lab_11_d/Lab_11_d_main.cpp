#include "multi_cl.h" // включение заголовочного файла с классом
int main() {
	srand(time(NULL));
	// ЛАБОРАТОРНАЯ РАБОТА № 11Д.
	/*

	Разработать класс для представления объекта множество чисел (элементы не повторяются).
	– Определить конструктор с тремя параметрами (количество элементов, минимальный и
	максимальный в диапазоне генерируемых чисел),
	который задаёт элементы множества (конструктор с параметрами).\/
	– Определить конструктор, который генерирует
	множество из 10 элементов в диапазоне [-20; 20] (конструктор по умолчанию).\/
	– Определить конструктор, которые копирует в
	новое множество элементы другого множества, не превышающие заданное значение (конструктор копирования).\/
	– Создать функцию, которая находит максимальное значение в множестве.
	– Создать функции для построения
	объединения, \/
	пересечения, \/
	разности \/
	и дизъюнктивной суммы двух числовых множеств.\/

	*/

	MULTIPLICITY a;// (конструктор по умолчанию)
	cout << a;
	cout << a.max_val()<< endl;
	system("pause");
	system("cls");
	
	MULTIPLICITY b{ 100, -100, 100};// (конструктор с параметром)
	cout << b;
	cout<< b.max_val() << endl;
	system("pause");
	system("cls");

	MULTIPLICITY c{b};// (конструктор копирования)
	cout << c;
	cout<< c.max_val() << endl;
	system("pause");
	system("cls");

	MULTIPLICITY d{ 100, -100, 100 };// (конструктор с параметром)
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