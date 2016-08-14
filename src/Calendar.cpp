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
#include <stdexcept>      // std::invalid_argument

namespace lab2 {

//template<class DateType>
//Calendar<DateType>::Event::Event(string description, DateType date) {
//	this->eventDescription = description;
//	this->eventDate = date;
//}

template<class DateType>
Calendar<DateType>::Calendar() {
	Date* d = new DateType();
	this->date = *d;
	delete d;
	std::cerr << "default calendar " << date << std::endl;
}

template<class DateType>
Calendar<DateType>::Calendar(Calendar<DateType> const & ref) : date(ref.date), events(ref.events){
	std::cerr << "copy calendar "  << date << std::endl;
}

//template <typename DateType>  //class template parameters
//template <typename DateType2> //function template parameters
//Calendar<DateType2>::Calendar(Calendar<DateType2>& ref) {
//	std::cerr << "copy different calendars "  << date << std::endl;
//}

template<class DateType>
Calendar<DateType>::~Calendar() {
	// TODO Auto-generated destructor stub
}

template<class DateType>
bool Calendar<DateType>::set_date(int year, int month, int day) {
	try {
		this->date = new DateType(year, month, day);
		return true;
	} catch(const std::invalid_argument& ia) {
		return false;
	}
}

template<class DateType>
bool Calendar<DateType>::add_event(std::string description) {
	//Event e(description, date);
	//events.add(Event(description, date));
}


template class Calendar<Gregorian>;
template class Calendar<Julian>;
}
