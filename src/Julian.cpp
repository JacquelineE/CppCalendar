/*
 * Julian.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "julian.hpp"
#include "kattistime.hpp"
#include <iostream>
#include <time.h>

Julian::Julian() {
	time_t mytime;
	k_time(&mytime);
	std::cout << "julian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Julian::Julian(Julian const& ref) {
	std::cout << "copy" << std::endl;
	offset = ref.offset;
}

Julian::~Julian() {
	// TODO Auto-generated destructor stub
}

//TODO should count differently since this object only see this method (the
//other way to count leap years is private... why do we get the same result?)
int Julian::leap_years_before(int year) const {
	 year--;
	 return (year / 4);
}

bool Julian::is_leap_year(int year) const {
	 return (year % 4 == 0);
}

void Julian::set_offset(long int currTime) {
	Date::set_offset(currTime);
	offset -= kJulOffsetDiff1858;
	std::cout << "in set_offset jul " << offset << std::endl;
}
