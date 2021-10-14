#include "fig_cl.h"

void Figure1::show(const int & x0, const int& y0, const int& z0)
{
	double Chisl = ((-1)*(pow(x0, 4)+ pow(y0, 4)+ pow(z0, 4))+2*(pow(x0*y0, 2)+pow(y0*z0, 2)+ pow(x0*z0, 2)))/16 ;
	cout << "Square: "<< pow( Chisl, 0.5) << endl;
	cout << "while x: "<< x0<< " y: "<< y0 << " z: " << z0 << endl;
}

void Figure2::show(const int & x0, const int& y0, const int& z0)
{
	cout << "Square: " << x0*y0 << endl;
	cout << "while x: " << x0 << " y: " << y0 << endl;
}

void Figure3::show(const int & x0, const int& y0, const int& z0)
{
	cout << "Square: " << pow(x0, 2)* 3.14 << endl;
	cout << "while x: " << x0 << endl;
}
