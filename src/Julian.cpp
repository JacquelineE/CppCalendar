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

Julian::~Julian() {
	// TODO Auto-generated destructor stub
}

//TODO should count differently since this object only see this method (the
//other way to count leap years is private... why do we get the same result?)
int Julian::leap_years_before(int year) {
	 year--;
	 return (year / 4);
}

