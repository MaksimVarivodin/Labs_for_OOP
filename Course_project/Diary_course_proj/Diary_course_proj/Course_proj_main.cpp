#include "Diary.h"

int WinMain()
{
	Diary a;
	a.setPath(L"data.bin");
	
	if(a.use())return EXIT_SUCCESS;
	else return EXIT_FAILURE;
	
	

  
}