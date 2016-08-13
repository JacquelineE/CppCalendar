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
//	time_t mytime;
//	k_time(&mytime);
	time_t mytime = k_time(NULL);
	std::cerr << "julian mytime is " << mytime << std::endl;
//	set_offset(mytime);
//	this->julian_day_number = calc_julian_day_number(this->year(), this->month(), this->day());

	this->julian_day_number = get_julian_number_from_time(mytime);
	this->offset = get_offset_from_julian_day((*this).julian_day_number);
}

int Julian::get_julian_number_from_time(long int currTime) const {
	int julianNumberStart = 2440587;
	int numberOfDays = (floor((double) currTime / (60 * 60 * 24)));
	if(numberOfDays > 0) {
		return julianNumberStart + numberOfDays;
	} else {
		return julianNumberStart - numberOfDays;
	}
}

//Julian::Julian(Julian const& ref) {
//	std::cerr << "copy" << std::endl;
//	(*this).offset = ref.offset;
//	(*this).julian_day_number = ref.julian_day_number;
//}

Julian::Julian(const Date & ref) : Date(ref) {}

Julian::Julian(const Date * ptr) : Date(*ptr) {}



Julian::Julian(int year, int month, int day) {
	is_valid_date(year, month, day);
	(*this).julian_day_number = (*this).calc_julian_day_number(year, month, day);
	std::cerr << "julian day number: " << (*this).julian_day_number << std::endl;
	(*this).offset = (*this).get_offset_from_julian_day((*this).julian_day_number);
	std::cerr << "FROM JDN:" << (*this).offset << std::endl;
}

void Julian::is_valid_date(int year, int month, int day) const {
	std::cerr << "is_valid_date month : " << month << std::endl;
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

void Julian::set_offset(long int currTime) {
	(*this).Date::set_offset(currTime);
	offset -= kJulOffsetDiff1858;
	std::cerr << "in set_offset jul " << offset << std::endl;
}

Julian& Julian::operator++() {
	//std::cerr << "pre++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	++(*this).julian_day_number;
	return *this;
}

Julian& Julian::operator--() {
	//std::cerr << "pre-- " << ((*this).offset) << std::endl;
	--(*this).offset;
	--(*this).julian_day_number;
	return *this;
}

Julian Julian::operator++(int) {
	//std::cerr << "post++ " << std::endl;
	Julian preValue = *this;
	++(*this).offset;
	++(*this).julian_day_number;
	return preValue;
}

Julian Julian::operator--(int) {
	//std::cerr << "post-- " << std::endl;
	Julian preValue = *this;
	--(*this).offset;
	--(*this).julian_day_number;
	return preValue;
}

Julian& Julian::operator+=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cerr << "+= " << std::endl;
	(*this).offset += n;
	(*this).julian_day_number += n;
    return *this; // return the result by reference
}

Julian& Julian::operator-=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cerr << "-= " << std::endl;
	(*this).offset -= n;
	(*this).julian_day_number -= n;
    return *this; // return the result by reference
}

//Julian& Julian::operator=(const Date& ref) {
//	if(typeid(*this)==typeid(ref)) {
//		//(*this).offset = ref.offset;
//	} else {
//		//TODO implementera konstruktor Julian(year, month, day)
//		//och returnera den
//	}
//	std::cout << "implement operator= plz" << std::endl;
//	return *this;
//}

}
