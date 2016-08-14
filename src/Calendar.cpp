/*
 * Calender.cpp
 *
 *  Created on: 14 aug. 2016
 *      Author: Mitra
 */

#include "Calendar.h"
#include "gregorian.hpp"
#include "julian.hpp"
#include "date.hpp"
#include <iostream>
#include <vector>

namespace lab2 {

template<class DateType>
Calendar<DateType>::Calendar() {
	std::cerr << "default calendar" << std::endl;
	Date* d = new DateType();
	this->date = *d;
	std::cerr << date << std::endl;
}

template<class DateType>
Calendar<DateType>::~Calendar() {
	// TODO Auto-generated destructor stub
}


template class Calendar<Gregorian>;
template class Calendar<Julian>;
}
