#include "Fus.h"

int main()
{
	int c1 = 1, c2 = -1;
	double c3 = 0.1, c4 = -0.1;
	char c5 = 'A', c6 = 'K';
	int size = 10;
	int * arr1 = filler(size, c1), *arr2 = filler (size, c2);
	double * arr3 = filler(size, c3),*arr4 = filler(size, c4);
	char * arr5 = filler(size, c5), *arr6 = filler(size, c6);
	int check1[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		check2[]{-9, -8, -7, -6, -5, -4, -3, -2, -1, 0};
	double check3[]{ 0, 1*0.1,2 * 0.1, 3 * 0.1, 4 * 0.1, 
		5 * 0.1, 6 * 0.1, 7 * 0.1, 8 * 0.1, 9 * 0.1 -0},
		   check4[]{ 9*(-0.1), 8 * (-0.1), 7 * (-0.1), 6 * (-0.1),
		5 * (-0.1), 4 * (-0.1), 3 * (-0.1), 2 * (-0.1), 1 * (-0.1), 0 };
	char check5[]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' }, 
		 check6[]{ 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };
		
	int sum1 = 45, sum2 = 0;
    double sum3 = 4.5, sum4 = 0;
	char sum5 = '$', sum6 = 't';	
	
	print(arr1, size);
	print(arr2, size);
	print(arr3, size);
	print(arr4, size);
	print(arr5, size);
	print(arr6, size);

	sort(arr1, size);
	sort(arr2, size);
	sort(arr3, size);
	sort(arr4, size);
	sort(arr5, size);
	sort(arr6, size);

	assrt_arr(arr1, check1, size);
	assrt_arr(arr2, check2, size);
	assrt_arr(arr3, check3, size);
	assrt_arr(arr4, check4, size);
	assrt_arr(arr5, check5, size);
	assrt_arr(arr6, check6, size);

	cout << "Sorting: " << endl;
	print(arr1, size);
	print(arr2, size);
	print(arr3, size);
	print(arr4, size);
	print(arr5, size);
	print(arr6, size);

	cout << "Minimal: " << endl;
	cout << assrt_val(0, minml(arr1, size)) << endl;
	cout << assrt_val(-9, minml(arr2, size) ) << endl;
	cout << assrt_val(0.0, minml(arr3, size)) << endl;
    cout << assrt_val(-0.9, minml(arr4, size)) << endl;
	cout << assrt_val('A', minml(arr5, size)) << endl;
	cout << assrt_val('K', minml(arr6, size)) << endl;


    cout << "Summs: " << endl;
	
    cout << assrt_val(sum1, sum(arr1, size)) << endl;
	cout << assrt_val(sum2, sum(arr2, size)) << endl;
	cout << assrt_val(sum3, sum(arr3, size)) << endl;
	cout << assrt_val(sum4, sum(arr4, size)) << endl;
	cout << assrt_val(sum5, sum(arr5, size)) << endl;
	cout << assrt_val(sum6, sum(arr6, size)) << endl;


	sort(arr1, size, 2);
	sort(arr2, size, 2);
	sort(arr3, size, 2);
	sort(arr4, size, 2);
	sort(arr5, size, 2);
	sort(arr6, size, 2);

	assrt_arr(arr1, check1, size);
//	assrt_arr(arr2, check2, size);
//	assrt_arr(arr3, check3, size);
//	assrt_arr(arr4, check4, size);
//	assrt_arr(arr5, check5, size);
//	assrt_arr(arr6, check6, size);

	cout << "Sorting: " << endl;
	print(arr1, size);
	print(arr2, size);
	print(arr3, size);
	print(arr4, size);
	print(arr5, size);
	print(arr6, size);

	cout << "Minimal: " << endl;

//	cout << assrt_val(0, minml(arr1, size, 2)) << endl;
//	cout << assrt_val(-9, minml(arr2, size, 2)) << endl;
//	cout << assrt_val(0.0, minml(arr3, size, 2)) << endl;
//	cout << assrt_val(-0.9, minml(arr4, size, 2)) << endl;
//	cout << assrt_val('A', minml(arr5, size, 2)) << endl;
//	cout << assrt_val('K', minml(arr6, size, 2)) << endl;

	cout << "Summs: " << endl;
	 
//  cout << assrt_val(sum1, sum(arr1, size, 2)) << endl;
//  cout << assrt_val(sum2, sum(arr2, size, 2)) << endl;
//  cout << assrt_val(sum3, sum(arr3, size, 2)) << endl;
//  cout << assrt_val(sum4, sum(arr4, size, 2)) << endl;
//  cout << assrt_val(sum5, sum(arr5, size, 2)) << endl;
//  cout << assrt_val(sum6, sum(arr6, size, 2)) << endl;
	

	system("pause");
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
}