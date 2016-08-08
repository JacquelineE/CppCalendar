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
using namespace std;

int main() {
	//set current time before testing
	time_t tp;
	time(&tp);
	std::cout << "time is " << tp << std::endl;
	set_k_time(tp);

	std::cout << std::endl << "lets build gregorian!" << std::endl;
	Date * g = new Gregorian();
	int year = g -> year();
	std::cout << year << g->month() << "day" << g->day() << std::endl;
	std::cout << std::endl << "lets build julian!" << std::endl;
	Date * j = new Julian();
	std::cout << j -> year() << j->month() << "day" << j->day() << std::endl;

	return 0;
}
