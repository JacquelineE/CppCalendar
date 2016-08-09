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

Gregorian::Gregorian() {
	time_t mytime;
	k_time(&mytime);
	std::cout << "gregorian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Gregorian::Gregorian(Gregorian const& ref) {
	std::cerr << "copy" << std::endl;
	offset = ref.offset;
}

Gregorian::~Gregorian() {


}


int Gregorian::leap_years_before(int year) {
	 year--;
	 return (year / 4) - (year / 100) + (year / 400);
}

bool Gregorian::is_leap_year(int year) {
	 return (year % 4 == 0)  && ((!(year % 100 == 0)) || (year % 400 == 0) );
}

Gregorian& Gregorian::operator++() {
	std::cout << "++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	return *this;
}



