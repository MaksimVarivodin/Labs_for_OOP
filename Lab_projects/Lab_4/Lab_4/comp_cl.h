#pragma once
#include "manuf_cl.h"
class COMPANY : public MANUFACTURER {
	MANUFACTURER* arr = NULL;
	int size;
public:
	// ret size;
	int r_s() { return size; }
	COMPANY()
	{	 
		size = 12;
		arr = new MANUFACTURER[size]{ 
		{"Oracle",1,2488000000, 31.1 },
		{ "IBM", 3 , 2392000000, 29.9 },
		{ "Microsoft", 2 ,1048000000, 13.1 }, 
		{ "Oracle",1,2488000000, 31.1 },
		{ "IBM", 3 , 2392000000, 29.9 },
		{ "Microsoft", 2 ,1048000000, 13.1 },
		{ "Oracle",1,2488000000, 31.1 },
		{ "IBM", 3 , 2392000000, 29.9 },
		{ "Microsoft", 2 ,1048000000, 13.1 }, 
		{ "Oracle",1,2488000000, 31.1 },
		{ "IBM", 3 , 2392000000, 29.9 },
		{ "Microsoft", 2 ,1048000000, 13.1 }
		};
	}
	~COMPANY() {
		delete[] arr;
	}
	MANUFACTURER & operator[](int index);
 	void shapka();
	void equal(MANUFACTURER a, MANUFACTURER b);
	void resize();
	void print();
	void del();
	void sort();
};