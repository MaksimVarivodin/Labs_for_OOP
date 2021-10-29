#include "Fus.h"
int main() 
{
	int size = 10;
	int * arr1 = new int [size] {
		5, 4, 2, 3, 1, 7, 9, 6, 10, 8
	};
	int * res1 = new int [size] {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	};
	double * arr2 = new double[size] {
		0.5, 0.4, 0.2, 0.3, 0.1, 0.7, 0.9, 0.6, 1, 0.8
	};
	double * res2 = new double[size] {
		0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1
	};

}