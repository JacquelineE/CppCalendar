/*
 * Date.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "julian.hpp"
#include "kattistime.hpp"
#include <iostream>
#include <time.h>
#include <math.h>       /* ceil */
#include <algorithm>    // std::max
#include <typeinfo> //typeid

namespace lab2 {

Date::Date() {
	//	time_t mytime;
	//	k_time(&mytime);
	//	std::cout << "date mytime is " << mytime << std::endl;
	//	//monthsLengthNormalYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	//	set_offset(mytime);
}

Date::~Date() {
	//	//delete [] monthsLengthNormalYear
}

int Date::getOffset() {
	return offset;
}

int Date::getJulian() {
	return julian_day_number;
}

//	int Date::offset_protected() {
//		return offset;
//	}

int Date::get_difference_in_days(const Date& ref, int startYear, int endYear) {
	//leap days for *this
	int leapDaysThis = (*this).leap_years_between(startYear, endYear);
	//leap days for ref
	int leapDaysRef = ref.leap_years_between(startYear, endYear);
	return leapDaysThis-leapDaysRef;
}

//Checks the difference between the actual days
int Date::operator-(const Date& ref) {
	int diff;
	if(typeid(ref) == typeid(*this)) {
		diff = (*this).offset - ref.offset;
	} else {
		//leap days for *this
		int leapDaysThis = leap_years_between(kStartYear, (*this).year());
		//leap days for ref
		int leapDaysRef = leap_years_between(kStartYear, ref.year());
		int diff = leapDaysThis - leapDaysRef;
		diff = (*this).offset - ref.offset + kJulOffsetDiff1858 + diff;
	}
	//std::cout << "diff " << typeid(*this).name() << "-" << typeid(ref).name() << " = " << diff << std::endl;
	return diff;
}

bool Date::operator==(const Date& ref) {
	return ((*this) - ref) == 0;
}

bool Date::operator!=(const Date& ref) {
	return ((*this) - ref) != 0;
}

//less than
bool Date::operator<(const Date& ref) {
	return ((*this) - ref) < 0;
}

//greater than
bool Date::operator>(const Date& ref) {
	return ((*this) - ref) > 0;
}

bool Date::operator<=(const Date& ref) {
	return ((*this) - ref) <= 0;
}

bool Date::operator>=(const Date& ref) {
	return ((*this) - ref) >= 0;
}

Date& Date::operator=(const Date& ref) {
	(*this).offset = ref.offset;
	(*this).julian_day_number = ref.julian_day_number;
	if(typeid(*this)!=typeid(ref)) {
		if(typeid(ref)==typeid(Julian)) {
			//int diff = (*this).get_difference_in_days(ref, kStartYear, ref.year());
			std::cerr << "lol hello different julian:" << std::endl;
			//(*this).offset -= diff;
			(*this).offset += kJulOffsetDiff1858;
			//TODO store julian_day_number
		} else {
			//int diff = (*this).get_difference_in_days(ref, kStartYear, ref.year());
			std::cerr << "lol hello different gregorian:" << std::endl;
			//(*this).offset += diff;
			(*this).offset += kJulOffsetDiff1858;
			//TODO store julian_day_number
		}
	}
	return *this;
}

//Date& Date::operator++() {
//	std::cout << "pre++ " << ((*this).offset) << std::endl;
//	++(*this).offset;
//	return *this;
//}

int Date::monthsLengthNormalYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
		30, 31 };
std::string Date::monthsName[12] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November",
		"December" };

void Date::set_offset(long int currTime) {
	offset = (ceil((double) currTime / (60 * 60 * 24)))
			+ days_between(kStartYear, kUnixStart);
	std::cerr << "in set_offset " << offset << std::endl;
}

// Returns number of leap years, exclusive endYear
int Date::leap_years_between(int startYear, int endYear) const {
	return leap_years_before(endYear) - leap_years_before(startYear + 1);
}

int Date::days_between(int startYear, int endYear) const {
	int diff = endYear - startYear;
	return diff * 365 + leap_years_between(startYear, endYear);
}

unsigned int Date::year() const {
	int tentative_years = offset / 365;
	int remainingDays = offset % 365;
	if (leap_years_between(kStartYear, kStartYear + tentative_years)
			>= remainingDays) {
		tentative_years--;
	}
	return kStartYear + tentative_years;
}

unsigned int Date::month() const {
	int currYear = year();
	int daysOffsetCurrYear = offset - days_between(kStartYear, currYear);
	//std::cout << "dayOffset" << daysOffsetCurrYear << std::endl;
	bool isLeapYear = is_leap_year(currYear);
	unsigned int index = 0;
	while (daysOffsetCurrYear > 0) {
		daysOffsetCurrYear -= monthsLengthNormalYear[index];
		if (index == 1 && isLeapYear) {
			daysOffsetCurrYear -= 1;
		}
		index++;
	}
	return index;
}

unsigned int Date::day() const {
	unsigned int currYear = year();
	unsigned int currMonth = month();
	unsigned int daysOffsetCurrYear = offset
			- days_between(kStartYear, currYear);
	unsigned int daysToStartOfMonth = 0;
	for (unsigned int i = 0; i < currMonth - 1; i++) {
		if (i == 1 && is_leap_year(currYear)) {
			daysToStartOfMonth += 1;
		}
		daysToStartOfMonth += monthsLengthNormalYear[i];
	}
	return daysOffsetCurrYear - daysToStartOfMonth;

}

unsigned int Date::days_per_week() const {
	return 7;
}

void Date::add_year(int n) {
	if (n == 0) {
		return;
	}
	int daysToAdd = 0;
	if(is_leap_year(year()) && month() <= 2) {
		//must add extra day
		daysToAdd++;
	}
	//add remaining days on currYear
	for(unsigned int i = 12; i > month(); --i) {
		daysToAdd  += monthsLengthNormalYear[i-1];
	}
	daysToAdd += (monthsLengthNormalYear[month()-1] - day());

	//add all years in between curr year and last year
	int i = 1;
	while(i<n) {
		if(is_leap_year(year()+i)) {
			daysToAdd++;
		}
		daysToAdd += 365;
		i++;
	}
	//add remaining days on last year

	if(is_leap_year(year()+n)) {
		if(month() > 2) {
			daysToAdd++;
		}
	} else {
		if(month() == 2 && day()== 29) {
			daysToAdd--;
			std::cout << "ghjl"<< month() << day() ;
		}
	}
	//add startdays + days in startmonths
	for(int i = 0; i <month()-1; i++) {
		daysToAdd += monthsLengthNormalYear[i];
	}
	daysToAdd += day();

	offset += daysToAdd;

}


unsigned int Date::days_this_month() const {
	int currMonth = month();
	int daysInCurrMonth = monthsLengthNormalYear[currMonth - 1];
	if (currMonth == 2 && is_leap_year(year())) {
		daysInCurrMonth += 1;
	}
	return daysInCurrMonth;
}
void Date::add_month(int n) {

	int daysToAdd = 0;
	int startDay = day();
	int startMonth = month();

	//add days to get curr offset == 1 jan next month
	if(!(startMonth == 2 && startDay == 29)) {
		offset += monthsLengthNormalYear[startMonth-1] -startDay + 1;
	}
	//compensate for feb having one extra day on leap_years
	if(is_leap_year(year()) && startMonth == 2) {
		offset++;
	}
	//add whole months
	int index = month();
	for(int i = 0; i < n-1; i++) {
		if(is_leap_year(year()) && index == 2) {
			offset++;
		}
		offset += monthsLengthNormalYear[index-1];
		index++;
		if(index > 12) {
			index = index % 12;
		}
	}
	//minus 1 since we are on 1st jan instead of last day in month
	if(startDay > monthsLengthNormalYear[month()-1]) {
		startDay = monthsLengthNormalYear[month()-1];
		if(is_leap_year(year()) && month() == 2) {
			startDay++;
		}
	}
	offset += startDay -1;


}

int Date::mod_julian_day() const {
		return (*this).julian_day_number - 2400000;
}

//just for testing purpose
void Date::add_day(int n) {
	offset += n;
}

std::ostream& operator<<(std::ostream& out, const Date& ref) {
	return out << ref.year() << '-' << ref.month() << "-" << ref.day();
}

}
