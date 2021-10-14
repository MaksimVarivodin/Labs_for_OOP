#include "filt_cl.h"

void B::operator()(const int & x0)
{
	x = rand()%100+ 1;
}

void P1::operator()(const int & x0)
{
	if (x0 % 7 == 3) {
		x = x0;
	}
	else x = 0;
}

void P2::operator()(const int & x0)
{
	if (x0 % 5 == 2) {
		x = x0;
	}
	else x = 0;
}
