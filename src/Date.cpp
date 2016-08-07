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
//	time_t mytime;
//	k_time(&mytime);
//	std::cout << "date mytime is " << mytime << std::endl;
	//monthsLengthNormalYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	//set_offset(mytime);
}


Date::~Date() {
//	//delete [] monthsLengthNormalYear
}

int Date::monthsLengthNormalYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void Date::set_offset(long int currTime) {

	offset = (currTime / 60 / 60 / 24) + days_between(kStartYear, kUnixStart);
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

int Date::year() {
	int tentative_years = offset / 365;
	std::cout << "tentyears" << tentative_years << std::endl;
	int remainingDays = offset % 365;
	std::cout << "remainingdays" << remainingDays << std::endl;
	if(leap_years_between(kStartYear, kStartYear + tentative_years) >= remainingDays) {
		tentative_years--;
	}
	return kStartYear + tentative_years;
}

int Date::month() {
	int currYear = year();
	int daysOffsetCurrYear = offset - days_between(kStartYear, currYear);
	bool isLeapYear =  is_leap_year(currYear);
	int index = 0;
	while(daysOffsetCurrYear > 0) {
		daysOffsetCurrYear -= monthsLengthNormalYear[index];
		if(index == 1 && isLeapYear) {
			daysOffsetCurrYear -= 1;
		}
		index++;
	}
	return index;
}



