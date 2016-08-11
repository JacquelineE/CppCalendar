/*
 * Julian.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#include "date.hpp"
#include "julian.hpp"
#include "kattistime.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h> //abs
#include <typeinfo> //typeid

namespace lab2 {

Julian::Julian() {
	time_t mytime;
	k_time(&mytime);
	std::cerr << "julian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Julian::Julian(Julian const& ref) {
	std::cerr << "copy" << std::endl;
	(*this).offset = ref.offset;
}

Julian::Julian(int year, int month, int day) {
	int a = (month > 2) ? 0 : 1;
	int y = year+4800-a;
	int m = month+12*a-3;
	(*this).julian_day_number = day + (153*m+2)/5 + 365*y + y/4 - 32045 - 1; //seem to be off by 1
	std::cerr << "julian day number: " << (*this).julian_day_number << std::endl;
	//TODO sätt offset relativt julian day!
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
	Date::set_offset(currTime);
	offset -= kJulOffsetDiff1858;
	std::cerr << "in set_offset jul " << offset << std::endl;
}

Julian& Julian::operator++() {
	std::cerr << "pre++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	return *this;
}

Julian& Julian::operator--() {
	std::cerr << "pre-- " << ((*this).offset) << std::endl;
	--(*this).offset;
	return *this;
}

const Julian Julian::operator++(int) {
	std::cerr << "post++ " << std::endl;
	const Julian preValue = *this;
	++(*this).offset;
	return preValue;
}

const Julian Julian::operator--(int) {
	std::cerr << "post-- " << std::endl;
	const Julian preValue = *this;
	--(*this).offset;
	return preValue;
}

Julian& Julian::operator+=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cerr << "+= " << std::endl;
	(*this).offset += n;
    return *this; // return the result by reference
}

Julian& Julian::operator-=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cerr << "-= " << std::endl;
	(*this).offset -= n;
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
