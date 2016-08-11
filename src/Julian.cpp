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

Julian::~Julian() {
	// TODO Auto-generated destructor stub
}

//TODO should count differently since this object only see this method (the
//other way to count leap years is private... why do we get the same result?)
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
