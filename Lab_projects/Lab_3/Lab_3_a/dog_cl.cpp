#include "dog_cl.h"
ostream & operator<< (ostream & out, const DOG & a) {
	cout << &a << " age " << a.age << endl;
	cout << &a << " weight " << a.weight << endl;
	return out;
}
istream & operator>> (istream & in, DOG & a) {
	cout << "Enter age and weight of a dog:" << endl;
	cin >> a.age;
	a.err_check(cin.fail(), a);
	cin >> a.weight;
	a.err_check(cin.fail(), a);
	return in;
}
ostream & operator<< (ostream & out, const SpanielD & a){
	cout << &a << " age " << a.age << endl;
	cout << &a << " weight " << a.weight << endl;
	cout << &a << " color " << a.color << endl;
	return out;
}
istream & operator>> (istream & in, SpanielD & a) {
	cout << "Enter age, weight and color of a dog:" << endl;
	cin >> a.age;
	a.err_check(cin.fail(), a);
	cin >> a.weight;
	a.err_check(cin.fail(), a);
	cin >> a.color;
	a.err_check(cin.fail(), a);
	return in;
}

void DOG::err_check(bool a, DOG & b)
{
	if (a) {
		b.age = 0;
		b.weight = 0;
	}
}

void SpanielD::err_check(bool a, SpanielD & b)
{
	DOG::err_check(a, b);
	if (a)
		b.color = "";
}
