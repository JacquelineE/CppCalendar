/*
 * Gregorian.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "gregorian.hpp"
#include "kattistime.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h> //abs
#include <typeinfo> //typeid

namespace lab2 {

Gregorian::Gregorian() {
	time_t mytime;
	k_time(&mytime);
	std::cerr << "gregorian mytime is " << mytime << std::endl;
	set_offset(mytime);
	this->julian_day_number = calc_julian_day_number(this->year(), this->month(), this->day());
}

//Gregorian::Gregorian(Gregorian const& ref) {
//	std::cerr << "copy" << std::endl;
//	(*this).offset = ref.offset;
//	(*this).julian_day_number = ref.julian_day_number;
//}
Gregorian::Gregorian(const Date & ref) : Date(ref) {}

Gregorian::Gregorian(const Date * ptr) : Date(*ptr) {}

Gregorian::Gregorian(int year, int month, int day) {
	(*this).julian_day_number = (*this).calc_julian_day_number(year, month, day);
	std::cerr << "julian day number: " << (*this).julian_day_number << std::endl;
	(*this).offset = (*this).get_offset_from_julian_day((*this).julian_day_number);
}

//helper
int Gregorian::calc_julian_day_number(int year, int month, int day) const {
	int a = (month > 2) ? 0 : 1;
	int y = year+4800-a;
	int m = month+12*a-3;
	return day + (153*m+2)/5 + 365*y + y/4 - y/100 + y/400 - 32045 - 1; //off by 1
}

int Gregorian::get_offset_from_julian_day(int julian_day) const {
	return julian_day - this->julian_day_on_start_offset();
}

int Gregorian::julian_day_on_start_offset() const {
	return 2399679;
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
	//std::cerr << "pre++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	++(*this).julian_day_number;
	return *this;
}

Gregorian& Gregorian::operator--() {
	//std::cerr << "pre-- " << ((*this).offset) << std::endl;
	--(*this).offset;
	--(*this).julian_day_number;
	return *this;
}

const Gregorian Gregorian::operator++(int) {
	//std::cerr << "post++ " << std::endl;
	const Gregorian preValue = *this;
	++(*this).offset;
	++(*this).julian_day_number;
	return preValue;
}

const Gregorian Gregorian::operator--(int) {
	//std::cerr << "post-- " << std::endl;
	const Gregorian preValue = *this;
	--(*this).offset;
	--(*this).julian_day_number;
	return preValue;
}

Gregorian& Gregorian::operator+=(const int& n) {
	std::cerr << "+= " << std::endl;
	(*this).offset += n;
	(*this).julian_day_number += n;
    return *this;
}

Gregorian& Gregorian::operator-=(const int& n) {
	std::cerr << "-= " << std::endl;
	(*this).offset -= n;
	(*this).julian_day_number -= n;
    return *this;
}

//Gregorian& Gregorian::operator=(const Date& ref) {
//	if(typeid(*this)==typeid(ref)) {
//		//(*this).offset = ref.offset;
//	} else {
//		std::cout << "lala = lalala" << std::endl;
//	}
//	return *this;
//}

//void Gregorian::julian_day_to_gregorian

}
