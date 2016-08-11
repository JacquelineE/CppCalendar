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
#include <string> //to_string
#include <sstream> //str()

namespace lab2 {

Gregorian::Gregorian() {
	time_t mytime;
	k_time(&mytime);
	std::cerr << "gregorian mytime is " << mytime << std::endl;
	set_offset(mytime);
}

Gregorian::Gregorian(Gregorian const& ref) {
	std::cerr << "copy" << std::endl;
	(*this).offset = ref.offset;
}

//Gregorian::Gregorian(int year, int month, int day) {
//	//beräkna offset från inmatat datum
//	std::string y = static_cast<std::ostringstream*>( &(std::ostringstream() << year) )->str();
//	std::string m = static_cast<std::ostringstream*>( &(std::ostringstream() << month) )->str();
//	std::string d = static_cast<std::ostringstream*>( &(std::ostringstream() << day) )->str();
//	std::cout << y << "-" << m << "-" << d << std::endl;
//	std::string date = (y+"-"+m+"-"+d);
//	const char *time_details = date.c_str();
//	struct tm tm;
//	strptime(time_details, "%H:%M:%S", &tm);
////	time_t t = mktime(&tm);  // t is now your desired time_t
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
	std::cerr << "pre++ " << ((*this).offset) << std::endl;
	++(*this).offset;
	return *this;
}

Gregorian& Gregorian::operator--() {
	std::cerr << "pre-- " << ((*this).offset) << std::endl;
	--(*this).offset;
	return *this;
}

const Gregorian Gregorian::operator++(int) {
	std::cerr << "post++ " << std::endl;
	const Gregorian preValue = *this;
	++(*this).offset;
	return preValue;
}

const Gregorian Gregorian::operator--(int) {
	std::cerr << "post-- " << std::endl;
	const Gregorian preValue = *this;
	--(*this).offset;
	return preValue;
}

Gregorian& Gregorian::operator+=(const int& n) {
	std::cerr << "+= " << std::endl;
	(*this).offset += n;
    return *this;
}

Gregorian& Gregorian::operator-=(const int& n) {
	std::cerr << "-= " << std::endl;
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
