//============================================================================
// Name        : lab2.cpp
// Author      : Jacqueline Eriksson, Mitra Strandberg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.hpp"
//using namespace std;
using namespace lab2;
using namespace std;
int main() {
	//set current time before testing
	time_t tp;
	time(&tp);
	std::cerr << "time is " << tp << std::endl;
	set_k_time(tp);


	std::cerr << std::endl << "lets build gregorian!" << std::endl;
	Date * g = new Gregorian();
	std::cerr << *g << std::endl;
	Gregorian g2;
	std::cerr << std::endl << "lets copy construct gregorian!" << std::endl;
	Gregorian g3(g2);
	std::cerr << std::endl << "lets decrement gregorian!" << std::endl;
	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
	--g2; //pre-decrement
	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
	g2--;
	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
	g2-=10;
	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
	std::cerr << "diff g2-g3: " << g2-g3 << std::endl << std::endl;

	int year = g -> year();
	std::cerr << year << g->month() << "day" << g->day() << std::endl;

	std::cerr << std::endl << "lets build julian!" << std::endl;
	Date * j = new Julian();
	std::cerr << *j << std::endl;
	Julian j2;
	std::cerr << std::endl << "lets copy construct Julian!" << std::endl;
	Julian j3(j2);
	std::cerr << std::endl << "lets decrement Julian!" << std::endl;
	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
	--j2; //pre-decrement
	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
	j2--;
	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
	j2 += 10;
	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
	std::cerr << "j2<=*j: " << (j2<=*j) << "  j2>=*j: " << (j2>=*j) << std::endl;
	std::cerr << "*j: " << *j << ". j2: " << j2 << "." << std::endl << "*j = j2" << std::endl;
	std::cerr << "offset *j=" << (*j).getOffset() << std::endl;
	std::cerr << "offset j2=" << (j2).getOffset() << std::endl;
	*j=j2;
	std::cerr << "AFTER: offset *j=" << (*j).getOffset() << std::endl;
	std::cerr << "offset *g=" << (*g).getOffset() << std::endl;
	*g=j2;
	std::cerr << "AFTER: offset j2=" << (j2).getOffset() << std::endl;
	std::cerr << "offset *g=" << (*g).getOffset() << std::endl;
	std::cerr << "j2 " << j2 << "  *g " << *g << std::endl;
	Julian gToday2;
	std::cerr << std::endl << "lets build julian again!" << std::endl;
	Julian gToday(2016, 8, 11);
	std::cerr << "MJD today:" << gToday.mod_julian_day() << " offset:" << gToday.getOffset() << std::endl;
	std::cerr << "MJD today2:" << gToday2.mod_julian_day() << " offset today2:" << gToday2.getOffset() << std::endl;
	Julian g1858(1858, 1, 1);
	std::cerr << "MJD 1858:" << g1858.mod_julian_day() << " offset:" << g1858.getOffset() << std::endl;
	Julian g1857(1857, 12, 31);
	std::cerr << "MJD 1857:" << g1857.mod_julian_day() << " offset:" << g1857.getOffset() << std::endl;

//	//hitta när offset = 0 för julian:
//	int off = gToday2.getOffset();
//	while(off > 0) {
//		--gToday2;
//		--off;
//		if(gToday2.getOffset() == 0) {
//			std::cerr << "offset is 0 on: " << gToday2 << "| julian_day_number:" << gToday2.getJulian() << std::endl;
//		}
//	}


//	std::cerr << j -> year() << j->month() << "day" << j->day() << std::endl;
//	std::cerr << "days in month g: " << g-> days_this_month()  << "jul: " << j->days_this_month() << std::endl;
//	std::cerr << "monthname g: " << g-> month_name()  << "jul: " << j->month_name() << std::endl;
//	g->add_year(200);
//	std::cerr << "addYear"  << "new year" << g->year() << std::endl;

	Date * gr2 = new Gregorian();
	cout << *gr2 << endl;
	Gregorian gr;
	Gregorian gr3(gr);
	gr.add_year(2);
	gr.add_month(7);
	gr.add_day(20);
	/////////////////
	cout << "5y " << gr << endl;
	for(int i = 0; i < 100; i++) {
		gr.add_month(15);
		cout << gr << endl;
	}




	return 0;
}
