#include "matrix_cl.h"
int MATRIX::size_x = 0;
int MATRIX::size_y = 0;
MATRIX** MATRIX::mtrx = NULL;
void MATRIX::creator()
{
	cout << "Enter two numbers to create a matrix" << endl;
	int *a = new int[2];
	for (int i = 0; i < 2;i++)
	{   
		for (;;) {
			cout << "Enter " << i + 1 << " number: ";
			cin >> a[i];			
			cout << endl;
			if (cin)break;
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			
		}
	}
	set_size(a[0], a[1]);
	MATRIX::mtrx = new MATRIX*[size_y];
	for (int i = 0; i < size_y; i++)
	{
		MATRIX::mtrx[i] = new MATRIX[size_x];
	}
	delete[] a;
}

void MATRIX::cleaner()
{
	if (mtrx != NULL)
	{
		for (int i = 0; i < size_y; i++)
		{
			delete[] mtrx[i];
		}
		delete[] mtrx;
		mtrx = nullptr;
		size_x = 0;
		size_y = 0;	
	}
}

ostream & operator<<(ostream & out, MATRIX & a)
{
	// TODO: вставьте здесь оператор return
	if (a.num < 10) {
		cout << "0" << a.num << " ";
	}
	else
	{
		cout << a.num << " ";
	}
	return out;
}

istream& operator>>(istream& in, MATRIX& a)
{
	// TODO: вставьте здесь оператор return
	cin >> a.num;
	return in;

}

void MATRIX::printer(int size_y, int size_x, MATRIX** mtrx)
{
	if (mtrx == NULL) {
		mtrx = MATRIX::mtrx;
		size_y = MATRIX::size_y;
		size_x = MATRIX::size_x;
	}		
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
			cout << mtrx[i][j];
		cout << endl << endl;
	}
}

void MATRIX::search(const int & Case)
{
	int min = 50;
	int min_x = 0;
	int min_y = 0;
	int a[2] = { 0, 0 };
	MATRIX ** buf = NULL;
	// ввод координат для изменения элемента и начальной координаты копирования
	if(Case == 0 || Case == 1){
		//  получение элемента по номеру
		cout << "Getting";
		switch (Case)
		{
		case 0:
			cout <<" element";
			break;
		case 1:
			cout << " submatrix";
			break;
		}
		cout << ", by entered coords"<< endl;
		cout << "the count starts from 1x1(X x Y)" << endl;
		cout << "Enter coordinates: " << endl;
		cin >> min_x;
		min_x--;
		cout << "x"<< endl;
		cin >> min_y;
		min_y--;
		
	}

	switch (Case) {
	case 0:
		//  изменение элемента по введенным координатам
		if ((min_y >= 0 && min_x >= 0) && (min_y < size_y && min_x < size_x))
		{
			cout << "Current element is: " << mtrx[min_y][min_x]<< endl;
			cout << "Enter your number: ";
			cin >> mtrx[min_y][min_x];
			printer();
		}
		else
		{
			cout << "Wrong coordinates!" << endl;
		}
		system("pause");
		system("cls");
		break;
	case 1:

		// получение подматрицы по введенным данным
		
		if ((min_y >= 0 && min_x >= 0) && (min_y < size_y && min_x < size_x))
		{
			
			cout << "Enter size:(X x Y)" << endl;
			cin >> a[0];
			cout << "x"<< endl;
			cin >> a[1];
			if ((a[0]> 0 && a[1] > 0) && (min_y + a[1] < size_y + 1 && min_x + a[0] < size_x + 1)) 
			{
				buf = new MATRIX*[a[1]];
				for (int i = 0; i < a[1]; i++) {				
					buf[i] = new MATRIX[a[0]];
					for (int j = 0; j < a[0]; j++)
					{
						buf[i][j] = mtrx[min_y + i][min_x + j];
					}
				}
				printer(a[1], a[0], buf);
				for (int i = 0; i < a[1]; i++) 
					delete[] buf[i];
				delete[] buf;
			}
			else 
			{
				cout << "couldn't copy matrix of this size" << endl;
			}
			


		}
		else
		{
			cout << "Wrong coordinates!" << endl;
		}
		
		system("pause");
		system("cls");
		break;
	default:

		// просто поиск минимального элемента
		cout << "Searching for minimal element:" << endl;
		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
				if (mtrx[i][j].num < min)
				{
					min = mtrx[i][j].num;
					min_x = j;
					min_y = i;
				}
		}

		cout << "minimal element is on pos: x: " << min_x + 1<< " y: " << min_y + 1<< endl;
		cout << "this element is: "<< mtrx[min_y][min_x] << endl<< endl;
		system("pause");
		system("cls");
		break;
	}

}

void MATRIX::set_size(const int & a, const int & b)
{
	MATRIX::size_x = a;
	MATRIX::size_y = b;
}

void MATRIX::Mat_user()
{
	MATRIX::cleaner();
	MATRIX::creator();
	MATRIX::printer();
	MATRIX::search();
	MATRIX::printer();
	MATRIX::search(0);
	MATRIX::printer();
	MATRIX::search(1);
	MATRIX::cleaner();
}
