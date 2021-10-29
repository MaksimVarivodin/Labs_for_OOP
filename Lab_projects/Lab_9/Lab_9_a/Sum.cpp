#include "Sum.h"

bool Sum::operator==(const Sum & other)
{
	if (this->a == other.a && this->b == other.b && this->s == other.s)
		return true;
	else return false;
}
