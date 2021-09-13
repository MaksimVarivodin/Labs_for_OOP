#include "multi_cl.h"
// ���������� ������������� ��������
int MULTIPLICITY::max_val()
{
	cout << __FUNCTION__ << " returns ";
	int max = this->min;
	for (int i = 0; i < this->count; i++)	
		if (max< mltplct[i]) 
			max = mltplct[i];		
	return max;
}
// �����������
MULTIPLICITY MULTIPLICITY::intersection
( const MULTIPLICITY & b)
{
	int count = 0;
	int* buf_arr = NULL;// �������� ������� �����
	
	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < b.count; j++)
		{
			// ���� ���� � ����� ����������
			if (this->mltplct[i] == b.mltplct[j])
			{
				// �� ����������� ������ �� 1 � ���������� � ���� ����� �����
				add_one_arr(buf_arr, count);
				buf_arr[count - 1] = this->mltplct[i];
			}
		}
	}
	// ������� ����� ��������� � ��������� ����������� ���������
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
// ��������
MULTIPLICITY MULTIPLICITY::substract
(const MULTIPLICITY & b)
{
	int buf_count = 0;
	int* buf_arr = NULL;

	// ������������ ������ � ��������� �� ����������
	for (int i = 0; i < this->count; i++)
	{
		bool match_found = false;
		// ���� � ������� ���������� ������� ���� \
				������� ����� �� ��� �� ��������� ��������, \
        �� �� ����� ��������
		for (int j = 0; j < b.count; j++) {
			if (this->mltplct[i] == b.mltplct[j])
			{
				match_found = true;
			}				
		}			
		// ���� ������� �� �������, �� ����������
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
// �����������
MULTIPLICITY MULTIPLICITY::merge
(const MULTIPLICITY & b)
{

	int buf_count = 0;
	int* buf_arr = NULL;
	// ������ ������������ ������
	for (int i = 0; i < this->count; i++)
	{
		add_one_arr(buf_arr, buf_count);
		buf_arr[buf_count - 1] = this->mltplct[i];
	}
    // ������������ ������ � ��������� �� ����������
	for (int i = 0; i < b.count; i++) 
    {
		bool match_found = false;
		// ���� � ������� ���������� ������� ���� \
		������� ����� �� ��� �� ��������� ��������, \
        �� �� ����� ��������
		for (int j = 0; j < this->count; j++)
			if (buf_arr[j] == b.mltplct[i])
				match_found = true;
		// ���� ������� �� �������, �� ����������
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
// �������������� ��������
MULTIPLICITY MULTIPLICITY::symmetric_dif
( const MULTIPLICITY & b)
{
	// ��� �������� ��� ���� �����,��� �������� ����������� � ���������(����������  ��� ��� � ��������)
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