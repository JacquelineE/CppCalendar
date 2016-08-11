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
	std::cout << "gregorian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Gregorian::Gregorian(Gregorian const& ref) {
	std::cout << "copy" << std::endl;
	(*this).offset = ref.offset;
}

//Gregorian::Gregorian(int year, int month, int day) {
//
//}

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
	std::cout << "pre++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	return *this;
}

Gregorian& Gregorian::operator--() {
	std::cout << "pre-- " << ((*this).offset) << std::endl;
	--(*this).offset;
	return *this;
}

const Gregorian Gregorian::operator++(int) {
	std::cout << "post++ " << std::endl;
	const Gregorian preValue = *this;
	++(*this).offset;
	return preValue;
}

const Gregorian Gregorian::operator--(int) {
	std::cout << "post-- " << std::endl;
	const Gregorian preValue = *this;
	--(*this).offset;
	return preValue;
}

Gregorian& Gregorian::operator+=(const int& n) {
	std::cout << "+= " << std::endl;
	(*this).offset += n;
    return *this;
}

Gregorian& Gregorian::operator-=(const int& n) {
	std::cout << "-= " << std::endl;
	(*this).offset -= n;
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

}
