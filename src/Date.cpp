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
	int currTime = (int)k_time(&currTime);
	set_offset(currTime);
}

void Date::set_offset(int currTime) {
	offset = (currTime / 60 / 60 / 24) + days_between();
	std::cout << offset << std::endl;
}


Date::~Date() {
	// TODO Auto-generated destructor stub
}

// Returns number of leap years, exclusive endYear
int Date::leap_years_between(int startYear, int endYear) {
	return leap_years_before(endYear) - leap_years_before(startYear+1);
}

int Date::leap_years_before(int year) {
	 year--;
	 return (year / 4) - (year / 100) + (year / 400);
}

int Date::days_between(int startYear, int endYear) {
	int diff = endYear - startYear;
	return diff * 365 + leap_years_between(startYear, endYear);
}

