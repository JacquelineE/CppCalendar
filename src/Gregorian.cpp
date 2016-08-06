/*
 * Gregorian.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "gregorian.hpp"
#include "kattistime.hpp"
#include <iostream>
#include <time.h>

Gregorian::Gregorian() {
	time_t mytime;
	k_time(&mytime);
	std::cout << "gregorian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Gregorian::~Gregorian() {
	// TODO Auto-generated destructor stub
}

int Gregorian::leap_years_before(int year) {
	 year--;
	 return (year / 4) - (year / 100) + (year / 400);
}

//int Gregorian::year() {
//	return 0;
//}

