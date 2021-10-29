#include "Sum.h"
int main(){
	setlocale(0, "");
	srand(time(NULL));
	int size = 100, counter = 0;
	vector<Sum> arr1, arr2;
	arr1.resize(size); arr2.resize(size);

	for (int i = 0; i < size; i++) {
		if (arr1[i] == arr2[i])
			counter++;
	}
	cout<< "ќдинаковых экземпл€ров: " << counter<< endl;
	system("pause");
}