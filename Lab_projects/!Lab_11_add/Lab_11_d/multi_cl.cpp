#include "multi_cl.h"
// нахождение максимального значения
int MULTIPLICITY::max_val()
{
	cout << __FUNCTION__ << " returns ";
	int max = this->min;
	for (int i = 0; i < this->count; i++)	
		if (max< mltplct[i]) 
			max = mltplct[i];		
	return max;
}
// пересечение
MULTIPLICITY MULTIPLICITY::intersection
( const MULTIPLICITY & b)
{
	int count = 0;
	int* buf_arr = NULL;// создание массива чисел
	
	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < b.count; j++)
		{
			// если есть в обоих множествах
			if (this->mltplct[i] == b.mltplct[j])
			{
				// то увеличиваем массив на 1 и записываем в него общее число
				add_one_arr(buf_arr, count);
				buf_arr[count - 1] = this->mltplct[i];
			}
		}
	}
	// создаем новое множество с известным количеством элементов
	if (buf_arr != NULL) {
		MULTIPLICITY A{ buf_arr, count };
		delete[] buf_arr;
		return A;
	}	
	else 
	{
		MULTIPLICITY A{ 0, 0, 0 };
		return A;
	}	
}
// разность
MULTIPLICITY MULTIPLICITY::substract
(const MULTIPLICITY & b)
{
	int buf_count = 0;
	int* buf_arr = NULL;

	// переписываем массив с проверкой на повторение
	for (int i = 0; i < this->count; i++)
	{
		bool match_found = false;
		// если в текущем записанном массиве есть \
				элемент такой же как мы планируем записать, \
        то он будет пропущен
		for (int j = 0; j < b.count; j++) {
			if (this->mltplct[i] == b.mltplct[j])
			{
				match_found = true;
			}				
		}			
		// если сходств не найдено, то записываем
		if (!match_found)
		{
			add_one_arr(buf_arr, buf_count);
			buf_arr[buf_count - 1] = this->mltplct[i];
		}
	}
	MULTIPLICITY A{ buf_arr, buf_count };
	delete[] buf_arr;
	return A;
}
// объеденение
MULTIPLICITY MULTIPLICITY::merge
(const MULTIPLICITY & b)
{

	int buf_count = 0;
	int* buf_arr = NULL;
	// просто переписываем массив
	for (int i = 0; i < this->count; i++)
	{
		add_one_arr(buf_arr, buf_count);
		buf_arr[buf_count - 1] = this->mltplct[i];
	}
    // переписываем массив с проверкой на повторение
	for (int i = 0; i < b.count; i++) 
    {
		bool match_found = false;
		// если в текущем записанном массиве есть \
		элемент такой же как мы планируем записать, \
        то он будет пропущен
		for (int j = 0; j < this->count; j++)
			if (buf_arr[j] == b.mltplct[i])
				match_found = true;
		// если сходств не найдено, то записываем
		if (!match_found)
		{
			add_one_arr(buf_arr, buf_count);
			buf_arr[buf_count - 1] = b.mltplct[i];
		}
	}
	MULTIPLICITY A{ buf_arr, buf_count };
	delete[] buf_arr;
	return A;
}
// симметрическая разность
MULTIPLICITY MULTIPLICITY::symmetric_dif
( const MULTIPLICITY & b)
{
	// сим разность это тоже самое,что разность объеденения и пересения(собственно  тут это и написано)
	MULTIPLICITY buf1 = this->merge(b);
	MULTIPLICITY buf2 = this->intersection(b);
	MULTIPLICITY A = buf1.substract(buf2);
	return A;
}

ostream&  operator<<(ostream & out, const MULTIPLICITY & a) {
	cout<< endl <<setw(7);
	int COL;
	if (a.count >= 10)
	{
		COL = 10;
	}
	else {
		COL = a.count; 
	}

	for (int i = 0; i < COL; i++) 
	{
		if (i>0)cout << setw(4);
		cout << i + 1;
	}
	for (int i = 0; i < a.count; i++)
	{
		if ((i + 1) % COL != 1) {
			cout << setw(4);
		}
		else {
			int a = i/COL + 1;
			cout << endl << endl<<setw(2) << a<< setw(5);
		}
		cout << a.mltplct[i];
	}
	cout << endl<< endl;
	cout << "Min el: " << a.min<< endl;
	cout << "Max el: " << a.max << endl;
	return out;
}