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
	std::cout << "julian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Julian::Julian(Julian const& ref) {
	std::cout << "copy" << std::endl;
	(*this).offset = ref.offset;
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
	std::cout << "in set_offset jul " << offset << std::endl;
}

Julian& Julian::operator++() {
	std::cout << "pre++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	return *this;
}

Julian& Julian::operator--() {
	std::cout << "pre-- " << ((*this).offset) << std::endl;
	--(*this).offset;
	return *this;
}

const Julian Julian::operator++(int) {
	std::cout << "post++ " << std::endl;
	const Julian preValue = *this;
	++(*this).offset;
	return preValue;
}

const Julian Julian::operator--(int) {
	std::cout << "post-- " << std::endl;
	const Julian preValue = *this;
	--(*this).offset;
	return preValue;
}

Julian& Julian::operator+=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cout << "+= " << std::endl;
	(*this).offset += n;
    return *this; // return the result by reference
}

Julian& Julian::operator-=(const int& n) {
    /* addition of rhs to *this takes place here */
	std::cout << "-= " << std::endl;
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
