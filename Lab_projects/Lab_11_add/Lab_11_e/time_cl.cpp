#include "time_cl.h"
// ������	
time_t TIME::getter()
{
	return this->sec;
}
// ��������
TIME TIME::substract(TIME & other)
{
	tm t_other, t_this;	
	t_other = *localtime(&other.sec);
	t_this= *localtime(&this->sec);
	TIME A;
	// ���� ������ ������ �� ���������� �����, �� �������� �� ����
	if (t_other.tm_hour > t_this.tm_hour) 
	{  
		t_other.tm_hour -= t_this.tm_hour;
		// ���� � ���� ����� ������
		if (t_other.tm_min < t_this.tm_min) {
			t_other.tm_hour--;
			t_other.tm_min += 60;
		}
		t_other.tm_min -= t_this.tm_min;
		// ���� � ���� ������ ������
		if (t_other.tm_sec < t_this.tm_sec) {
			if (t_other.tm_min - 1 < 0) 
			{
				t_other.tm_hour--;
				t_other.tm_min += 60;
			}
			t_other.tm_min--;
			t_other.tm_sec += 60;
		}
		t_other.tm_sec -= t_this.tm_sec;
		A.sec = mktime(&t_other);
	}
	// ���� � ������� ������ �� ���������� �����, �� �������� �� ����
	else 
	{
		t_this.tm_hour -= t_other.tm_hour;
		// ���� � ���� ����� ������
		if (t_other.tm_min > t_this.tm_min) {
			t_this.tm_hour--;
			t_this.tm_min += 60;
		}
		t_this.tm_min -= t_other.tm_min;
		// ���� � ���� ������ ������
		if (t_this.tm_sec < t_other.tm_sec) {
			if (t_this.tm_min - 1 < 0) {
				t_this.tm_hour--;
				t_this.tm_min += 60;
			}
			t_this.tm_min--;
			t_this.tm_sec += 60;
		}
		t_this.tm_sec -= t_other.tm_sec;
		A.sec = mktime(&t_this);
	}
	 return A;
}
// ������ ������
bool TIME::is_bigger(const TIME & other)
{
	tm t_other, t_this;
	t_other = *localtime(&other.sec);
	t_this = *localtime(&this->sec);
	return t_other.tm_hour < t_this.tm_hour ? true : t_other.tm_hour > t_this.tm_hour ? false :\
		t_other.tm_min < t_this.tm_min ? true : t_other.tm_min > t_this.tm_min ? false :\
		t_other.tm_sec < t_this.tm_sec ? true : false;
}
// ������ ����
double TIME::angle_calc()
{
	this->sec;
	tm timeinfo = *localtime(&this->sec);
	double hour = 30 * (timeinfo.tm_hour % 12) + timeinfo.tm_min/2;
	double min = 6 * timeinfo.tm_min;
	double angle = hour> min ? hour - min: min - hour;
	if (angle > 180)angle = 360 - angle;
	return angle;
}
// ���������� ��������� ������
ostream& operator<< (ostream& out, TIME& a) 
{
	// TODO: �������� ����� �������� return
	tm timeinfo = *localtime(&a.sec);
	cout << "hour -> " << timeinfo.tm_hour<< endl;
	cout << "min -> " << timeinfo.tm_min<< endl;
	cout << "sec -> " << timeinfo.tm_sec<< endl;
	return out;
}
// ���������� ��������� �����
istream& operator>> (istream & in, TIME & a) 
{

	tm timeinfo;
	int h, m, s;
	// ��������� ���������, ������ ���� � �����
	time_t sec0 = a.sec;
	time(&sec0);
	timeinfo = *localtime(&a.sec);
	bool err = true;
	// ���� ��������� ����� �����
	while (err)
	{
		system("cls");
		cout << "Enter hour: ";
		cin >> h;
		if (!cin.fail() && h < 24 && h >= 0) {
			timeinfo.tm_hour = h;
			cin.ignore(32767, '\n');
			err = false;
		}			
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error of hour entering" << endl;
		}
	}
	err = true;
	// ���� ��������� ����� �����
	while (err)
	{
		system("cls");
		cout << "Enter min: ";
		cin >> m;
		if (!cin.fail() && m < 61 && m >= 0){
			timeinfo.tm_min = m;
			cin.ignore(32767, '\n');
			err = false;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error of min entering" << endl;
		}
	}
	err = true;
	// ���� ��������� ����� ������
	while (err)
	{
		system("cls");
		cout << "Enter sec: ";
		cin >> s;
		if (!cin.fail() && s < 61 && s >= 0){
			timeinfo.tm_sec = s;
			cin.ignore(32767, '\n');
			err = false;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error of sec entering" << endl;
		}
	}
	// ��������� ��������� ��������() ������� ���������� ������ ��������� ������ 1900-��
	a.sec = mktime(&timeinfo);
	return in;
}
