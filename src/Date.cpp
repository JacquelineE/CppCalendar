/*
 * Date.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "kattistime.hpp"
#include <iostream>
#include <time.h>

Date::Date() {
	time_t mytime;
	k_time(&mytime);
	std::cout << "date mytime is " << mytime << std::endl;
	//set_offset(mytime);
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

void Date::set_offset(long int currTime) {
	int startYear = 1859;
	int unixStart = 1970;
	offset = (currTime / 60 / 60 / 24) + days_between(startYear, unixStart);
	std::cout << "in set_offset " << offset << std::endl;
}

// Returns number of leap years, exclusive endYear
int Date::leap_years_between(int startYear, int endYear) {
	return leap_years_before(endYear) - leap_years_before(startYear+1);
}

int Date::days_between(int startYear, int endYear) {
	int diff = endYear - startYear;
	return diff * 365 + leap_years_between(startYear, endYear);
}

