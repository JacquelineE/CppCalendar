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
	std::cout << "diff " << typeid(*this).name() << "-" << typeid(ref).name()
			<< " = " << diff << std::endl;
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
	if(typeid(*this)!=typeid(ref)) {
		if(typeid(ref)==typeid(Julian)) {
			int diff = (*this).get_difference_in_days(ref, kStartYear, ref.year());
			std::cout << "lol hello different julian:" << diff << std::endl;
			(*this).offset += diff;
		} else {
			int diff = (*this).get_difference_in_days(ref, kStartYear, ref.year());
			std::cout << "lol hello different gregorian:" << diff << std::endl;
			(*this).offset -= diff;
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
	std::cout << "in set_offset " << offset << std::endl;
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
	std::cout << "dayOffset" << daysOffsetCurrYear << std::endl;
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
	bool addOneAtEnd = false;
	if (month() == 2 && day() == 29 && is_leap_year(year() + n)) {
		addOneAtEnd = true;
	}
	while (n > 0) {
		if ((month() == 2) && (day() == 29)) {
			offset += 364;
		} else if ((month() <= 2 && is_leap_year(year()))
				|| (month() > 2 && is_leap_year(year() + 1))) {
			offset += 366;
		} else {
			offset += 365;
		}
		n--;
	}
}

unsigned int Date::days_this_month() const {
	int currMonth = month();
	int daysInCurrMonth = monthsLengthNormalYear[currMonth - 1];
	if (currMonth == 2 && is_leap_year(year())) {
		daysInCurrMonth += 1;
	}
	return daysInCurrMonth;
}

std::string Date::month_name() const {
	int currMonth = month();
	return monthsName[currMonth - 1];
}

void Date::add_month(int n) {
	if (n == 0) {
		return;
	}
	int startDay = day();
	int nrOfYears = n / 12;
	add_year(nrOfYears);
	int nrOfMonthsToAdd = n % 12;
	int leapYearFactor = 0;
	if (month() == 2 && is_leap_year(year())) {
		leapYearFactor = 1;
	}
	offset += monthsLengthNormalYear[month() - 1] - startDay + leapYearFactor;
	leapYearFactor = 0;
	int currMonth;
	for (unsigned int i = month(); i < month() + nrOfMonthsToAdd; ++i) {
		currMonth = i;
		if (i > 12) {
			currMonth = i % 12;
		}
		offset += monthsLengthNormalYear[currMonth - 1];
		if (currMonth == 2 && is_leap_year(year())) {
			offset++;
		}
	}
	offset += startDay;
}


//1 dela me 12 + ta hänsyn till skottår för se antalet år -> anroppa ad year på detta om det e >= 1

//2. gå fram till det datum som gäller (kompensera för att det ev inte e möjligt att komma åt just det datumet om månaden e för kort)

//3. jobba dig bakåt tills du kommer till den månad du började me, ta me de dagar som tillhör slutet på den månaden
//
//	if(n == 0) {
//		return;
//	}
//	int startDay = day();
//	while(n>1) {
//		int currMonth = month();
//		if(currMonth > 12) {
//			currMonth = currMonth % 12;
//		}
//		if(currMonth == 2 && is_leap_year(year())) {
//			offset += 29;
//		} else {
//			offset += std::min(monthsLengthNormalYear[currMonth-1], (monthsLengthNormalYear[currMonth] + monthsLengthNormalYear[currMonth-1] - day()));
//		}
//		n--;
//	}
//	int currMonth = month();
//	if(currMonth == 2 && is_leap_year(year())) {
//		offset += 29 - day(); //remaining days in month
//	} else {
//		offset += monthsLengthNormalYear[currMonth-1] - day(); //remaining days in month
//	}
//	int nextMonth = currMonth+1;
//	if(nextMonth >12) {
//		nextMonth = nextMonth % 12;
//	}
//	offset += std::min(startDay, monthsLengthNormalYear[nextMonth-1]); //offset = same day in next month
//}

//just for testing purpose
void Date::add_day(int n) {
	offset += n;
}

std::ostream& operator<<(std::ostream& out, const Date& ref) {
	return out << ref.year() << '-' << ref.month() << "-" << ref.day();
}

}
