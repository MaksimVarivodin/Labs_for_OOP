#include "pers_cl.h"
int Persona::cols = 0;
int Persona::lines = 0;
int Persona::lines_i = 1;
void Persona::putter() {

	COORD p{ cols * 37, lines * 9 };
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//получение хендла
	SetConsoleCursorPosition(hCons, p);
}

void Persona::putter2()
{
	COORD p{(cols) * 37, lines * 9 + (lines_i) };
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//получение хендла
	SetConsoleCursorPosition(hCons, p);

	if (lines_i < 8) { lines_i++; }
	else {
		lines_i = 1;
	}
}

void Persona::putter3() {
	if (cols < 2) {
		cols++;
		lines_i = 1;
	}
	else {
		lines++;
		cols = 0;
		lines_i = 1;
	}
}

void Persona::putter4() {
	if(cols!=0)
	lines++;
	cols = 0;
	lines_i = 1;
	
}
void Persona::enul()
{
	cols = 0;
	lines = 0;
	lines_i = 1;
}
void Persona::init()
{
	age = rand() % (80 - 18 + 1) + 18;
	string n_arr[20] = {
		"Федосеев Юлиан Пётрович",
		"Мартынов Ираклий Андреевич",
		"Медведев Лукьян Альвианович",
		"Шилов Велор Федорович",
		"Логинов Юстин Тимурович",
		"Туров Юрий Филиппович",
		"Моисеев Адам Егорович",
		"Игнатов Корнелий Львович",
		"Юдин Харитон Дамирович",
		"Семёнов Леонтий Феликсович",
		"Капустина Фелиция Даниловна",
		"Маслова Феодосия Артёмовна",
		"Анисимова Ирэн Даниловна",
		"Прохорова Дэнна Валерьяновна",
		"Воробьёва Юланта Степановна",
		"Овчинникова Данна Юрьевна",
		"Лапина Флора Максовна",
		"Чернова Агата Владиславовна",
		"Селиверстова Фая Святославовна",
		"Киселёва Анжела Аристарховна"
	};
	fio = n_arr[ rand() % 20];
}
