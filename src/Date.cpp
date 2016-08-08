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
#include <math.h>       /* ceil */

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
	offset = (ceil((double)currTime /( 60 * 60 * 24))) + days_between(kStartYear, kUnixStart);
	std::cout << "in set_offset " << offset << std::endl;
}

// Returns number of leap years, exclusive endYear
int Date::leap_years_between(int startYear, int endYear) const {
	return leap_years_before(endYear) - leap_years_before(startYear+1);
}

int Date::days_between(int startYear, int endYear) const {
	int diff = endYear - startYear;
	return diff * 365 + leap_years_between(startYear, endYear);
}

unsigned int Date::year() const {
	int tentative_years = offset / 365;
	int remainingDays = offset % 365;
	if(leap_years_between(kStartYear, kStartYear + tentative_years) >= remainingDays) {
		tentative_years--;
	}
	return kStartYear + tentative_years;
}

unsigned int Date::month() const {
	int currYear = year();
	int daysOffsetCurrYear = offset - days_between(kStartYear, currYear);
	std::cout << "dayOffset" << daysOffsetCurrYear << std::endl;
	bool isLeapYear =  is_leap_year(currYear);
	unsigned int index = 0;
	while(daysOffsetCurrYear > 0) {
		daysOffsetCurrYear -= monthsLengthNormalYear[index];
		if(index == 1 && isLeapYear) {
			daysOffsetCurrYear -= 1;
		}
		index++;
	}
	return index;
}


unsigned int Date::day() const {
	unsigned int currYear = year();
	unsigned int currMonth = month();
	unsigned int daysOffsetCurrYear = offset - days_between(kStartYear, currYear);
	unsigned int daysToStartOfMonth = 0;
	for(unsigned int i = 0; i <currMonth-1; i++) {
		if(i == 1 && is_leap_year(currYear)) {
			daysToStartOfMonth += 1;
		}
		daysToStartOfMonth += monthsLengthNormalYear[i];
	}
	return daysOffsetCurrYear - daysToStartOfMonth;

}
