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
	std::cout << "time is " << tp << std::endl;
	set_k_time(tp);
//
//	std::cout << std::endl << "lets build gregorian!" << std::endl;
//	Date * g = new Gregorian();
//	Gregorian g2;
//	std::cout << std::endl << "lets copy construct gregorian!" << std::endl;
//	Gregorian g3(g2);
//	std::cout << std::endl << "lets decrement gregorian!" << std::endl;
//	std::cout << "g2 offset: " << g2.getOffset() << std::endl;
//	--g2; //pre-decrement
//	std::cout << "g2 offset: " << g2.getOffset() << std::endl;
//	g2--;
//	std::cout << "g2 offset: " << g2.getOffset() << std::endl;
//	g2-=10;
//	std::cout << "g2 offset: " << g2.getOffset() << std::endl;
//	std::cout << "diff g2-g3: " << g2-g3 << std::endl;
//	std::cout << "g2!=g3: " << (g2!=g3) << std::endl;
//	std::cout << "g*!=g3: " << (*g!=g3) << std::endl;
//
//	int year = g -> year();
//	std::cout << year << g->month() << "day" << g->day() << std::endl;
//
//	std::cout << std::endl << "lets build julian!" << std::endl;
//	Date * j = new Julian();
//	Julian j2;
//	std::cout << std::endl << "lets copy construct Julian!" << std::endl;
//	Julian j3(j2);
//	std::cout << std::endl << "lets decrement Julian!" << std::endl;
//	std::cout << "j2 offset: " << j2.getOffset() << std::endl;
//	--j2; //pre-decrement
//	std::cout << "j2 offset: " << j2.getOffset() << std::endl;
//	j2--;
//	std::cout << "j2 offset: " << j2.getOffset() << std::endl;
//	j2 += 10;
//	std::cout << "j2 offset: " << j2.getOffset() << std::endl;
//	std::cout << "j3!=g3: " << (j3!=g3) << "  j3==g3: " << (j3==g3) << std::endl;
//	std::cout << "*j-*g: " << (*j-*g) << std::endl;
//	std::cout << "*j==*g: " << (*j==*g) << std::endl;
//	std::cout << "*j<=*g: " << (*j<=*g) << std::endl;
//	std::cout << "j2<=*j: " << (j2<=*j) << "  j2>=*j: " << (j2>=*j) << std::endl;
//	std::cout << *j << "." << std::endl;


//	std::cout << j -> year() << j->month() << "day" << j->day() << std::endl;
//	std::cout << "days in month g: " << g-> days_this_month()  << "jul: " << j->days_this_month() << std::endl;
//	std::cout << "monthname g: " << g-> month_name()  << "jul: " << j->month_name() << std::endl;
//	g->add_year(200);
//	std::cout << "addYear"  << "new year" << g->year() << std::endl;

	Date * g2 = new Gregorian();
	cout << *g2 << endl;
	//Date * j1 = new Julian();
	//cout << *j1 << endl;
	Gregorian g;
	Gregorian g3(g);

	cout << g << endl;
	return 0;
}
