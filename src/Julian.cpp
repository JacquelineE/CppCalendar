/*
 * Julian.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "julian.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h> //abs
#include <typeinfo> //typeid
#include <stdexcept>//invalid_argument
#include <math.h>       /* ceil */
#include "kattistime.h"

namespace lab2 {

Julian::Julian() {
	time_t mytime = k_time(NULL);
	std::cerr << "julian mytime is " << mytime << std::endl;
	int julian_day = outside_range_error(get_julian_number_from_time(mytime));
	this->julian_day_number = julian_day;
}

Julian::Julian(const Date & ref) : Date(ref) {}

Julian::Julian(const Date * ptr) : Date(*ptr) {}

Julian::Julian(int year, int month, int day) {
	is_valid_date(year, month, day);
	int julian_day = outside_range_error((*this).calc_julian_day_number(year, month, day));
	(*this).julian_day_number = julian_day;
	std::cerr << "julian day number: " << (*this).julian_day_number << std::endl;
	std::cerr << "FROM JDN:" << get_offset_from_julian_day(julian_day_number) << std::endl;
}

int Julian::outside_range_error(int julian_day) const {
	if (julian_day < 2399691) {
		throw std::out_of_range( "date must be 1857-12-31 or later." );
		return 0;
	}
	return julian_day;
}

//helper
int Julian::calc_julian_day_number(int year, int month, int day) const {
	std::cerr << "calc_julian_day_number" << std::endl;
	int a = (month > 2) ? 0 : 1;
	int y = year+4800-a;
	int m = month+12*a-3;
	return day + (153*m+2)/5 + 365*y + y/4 - 32083 -1; //off by 1
}

int Julian::get_offset_from_julian_day(int julian_day) const {
	return julian_day - this->julian_day_on_start_offset();
}

int Julian::julian_day_on_start_offset() const {
	return 2399691; //JDN when offset=0, dvs julianskt datum 1857-12-31
}

Julian::~Julian() {
	// TODO Auto-generated destructor stub
}

int Julian::leap_years_before(int year) const {
	 year--;
	 return (year / 4);
}

bool Julian::is_leap_year(int year) const {
	 return (year % 4 == 0);
}

Julian& Julian::operator++() {
	++(*this).julian_day_number;
	return *this;
}

Julian& Julian::operator--() {
	--(*this).julian_day_number;
	outside_range_error(julian_day_number);
	return *this;
}

Julian Julian::operator++(int) {
	//std::cerr << "post++ " << std::endl;
	Julian preValue = *this;
	++(*this).julian_day_number;
	return preValue;
}

Julian Julian::operator--(int) {
	//std::cerr << "post-- " << std::endl;
	Julian preValue = *this;
	--(*this).julian_day_number;
	outside_range_error(julian_day_number);
	return preValue;
}

Julian& Julian::operator+=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cerr << "+= " << std::endl;
	(*this).julian_day_number += n;
    return *this; // return the result by reference
}

Julian& Julian::operator-=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cerr << "-= " << std::endl;
	(*this).julian_day_number -= n;
	outside_range_error(julian_day_number);
    return *this; // return the result by reference
}

}
