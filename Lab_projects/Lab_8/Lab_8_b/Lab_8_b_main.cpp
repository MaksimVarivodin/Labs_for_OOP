#include "Array_cl.h"
/*
??????? ?????-?????? ??? ?????? ? ????????:
???? ? ???????????? ??????, ???????????? ?????? ??????? (size), ?????? (0 < ind < size  ??? ?????? ?? ?? ????? ?????????? ???????);
???????
? ??????????? ?? ????????? (???????? ?????? ??? ?????? ? ?????????????? ?????????? size=100, ind=0);
? ??????? ?????????? ?????? ???????? ??????? (? main() ??????????? ? ????? ?????????? ??????? ?? ???????? ind);
? ??????? ???????? ????? ???????? ? ??????? ???????? ind;
? ??????? ???????? ????????????????????? ???????? ? ??????? ???????? ind;
? ??????? ?????? ??????? ???????? ind;
? ??????????? ???????? [ ] ??? ???????? ????????????? ???????? ? ??????? ?????? ??????? (<=ind);
? ?????????? ??? ???????? ????????????? ???????.
*/
int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Arr<double> a;
	Arr<int>b;
	int size1 = 4;

	string * menu1 = new string[size1]{
	"???????? ?????? ???? ????? ??????: ",
	"1 - double",
	"2 - int", 
	"3 - ?????"
	};	
	for (;;) {
		int c = Menu_show(menu1, size1);
		switch (c) {
		case 1:
			a.use();
			break;
		case 2:
			b.use();
			break;
		}
		if (c == 3)break;
	}
	delete[] menu1;
	a.~Arr();
	b.~Arr();
}