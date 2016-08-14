/*
 * Gregorian.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "gregorian.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h> //abs
#include <typeinfo> //typeid
#include <stdexcept>//invalid_argument
#include "kattistime.h"

namespace lab2 {

Gregorian::Gregorian() {
	time_t mytime = k_time(NULL);
	std::cerr << "gregorian mytime is " << mytime << std::endl;
	this->julian_day_number = get_julian_number_from_time(mytime);
}

Gregorian::Gregorian(const Date & ref) : Date(ref) {}

Gregorian::Gregorian(const Date * ptr) : Date(*ptr) {}

Gregorian::Gregorian(int year, int month, int day) {
	is_valid_date(year, month, day);
	(*this).julian_day_number = (*this).calc_julian_day_number(year, month, day);
	std::cerr << "julian day number: " << (*this).julian_day_number << std::endl;
	std::cerr << "JD FROM JDN:" << (*this).julian_day_number << std::endl;
	std::cerr << "OFFSET FROM JDN:" << (*this).get_offset_from_julian_day(julian_day_number) << std::endl;
}

void Gregorian::is_valid_date(int year, int month, int day) const {
	if((month > 12) || (month < 1)) {
		std::cerr << "ERROR MONTH" << std::endl;
		throw std::invalid_argument( "month must be between 1-12" );
		return;
	}
	else if(day > correct_day_number(year, month) || day < 1) {
		std::cerr << "ERROR DAY tru " << correct_day_number(year, month) << std::endl;
		throw std::invalid_argument( "this month does not have this number of days" );
		return;
	}
}

//helper
int Gregorian::calc_julian_day_number(int year, int month, int day) const {
	int a = (month > 2) ? 0 : 1;
	int y = year+4800-a;
	int m = month+12*a-3;
	return day + (153*m+2)/5 + 365*y + y/4 - y/100 + y/400 - 32045 -1; //off by 1
}

int Gregorian::get_offset_from_julian_day(int julian_day) const {
	return julian_day - this->julian_day_on_start_offset();
}

int Gregorian::julian_day_on_start_offset() const {
	return 2399679; //1857-12-31
}

Gregorian::~Gregorian() {


}


int Gregorian::leap_years_before(int year) const {
	 year--;
	 return (year / 4) - (year / 100) + (year / 400);
}

bool Gregorian::is_leap_year(int year) const {
	 return (year % 4 == 0)  && ((!(year % 100 == 0)) || (year % 400 == 0) );
}

Gregorian& Gregorian::operator++() {
	++(*this).julian_day_number;
	return *this;
}

Gregorian& Gregorian::operator--() {
	--(*this).julian_day_number;
	return *this;
}

Gregorian Gregorian::operator++(int) {
	//std::cerr << "post++ " << std::endl;
	Gregorian preValue = *this;
	++(*this).julian_day_number;
	return preValue;
}

Gregorian Gregorian::operator--(int) {
	//std::cerr << "post-- " << std::endl;
	Gregorian preValue = *this;
	--(*this).julian_day_number;
	return preValue;
}

Gregorian& Gregorian::operator+=(const int& n) {
	std::cerr << "+= " << std::endl;
	(*this).julian_day_number += n;
    return *this;
}

Gregorian& Gregorian::operator-=(const int& n) {
	std::cerr << "-= " << std::endl;
	(*this).julian_day_number -= n;
    return *this;
}

}
