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
#include <typeinfo>	  //typeid
#include <algorithm>	//find
#include <sstream>	//stringstream

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
bool Calendar<DateType>::has_event(Event const event) const {
	if(std::find(events.begin(), events.end(), event) != events.end()) {
		return true;
	} else {
		return false;
	}
}

template<class DateType>
bool Calendar<DateType>::add_event(std::string description) {
	Event e(description, date);
	if(this->has_event(e)) { //does this event already exist?
		return false;
	}
	events.push_back(e);
	return true;
}

template<class DateType>
bool Calendar<DateType>::add_event(std::string event_name, int day) {
	try {
		DateType d(date.year(), date.month(), day);
		Event e(event_name, d);
		if(this->has_event(e)) {
			return false;
		}
		events.push_back(e);
	} catch (const std::invalid_argument& ia) {
		return false;
	}
	return true;
}

template<class DateType>
bool Calendar<DateType>::add_event(std::string event_name, int day, int month) {
	try {
		DateType d(date.year(), month, day);
		Event e(event_name, d);
		if(this->has_event(e)) {
			return false;
		}
		events.push_back(e);
	} catch (const std::invalid_argument& ia) {
		return false;
	}
	return true;
}

template<class DateType>
bool Calendar<DateType>::add_event(std::string event_name, int day, int month, int year) {
	try {
		DateType d(year, month, day);
		Event e(event_name, d);
		if(this->has_event(e)) {
			return false;
		}
		events.push_back(e);
	} catch (const std::invalid_argument& ia) {
		return false;
	}
	return true;
}

template<class DateType>
bool Calendar<DateType>::delete_event (std::string event_name) {
	Event e(event_name, DateType(date.year(), date.month(), date.day()));
	auto i = std::begin(events);
	while (i != std::end(events)) {
		if (*i==e) {
			std::cerr << " (remove " << (*i).getDesc() << ") ";
			i = events.erase(i);
			return true;
		} else {
			++i;
		}
	}
	return false;
	//	for (auto &j : events) {
	//		std::cerr << j.getDesc() << " " << j.getDate() << " | ";
	//	}
}

template<class DateType>
bool Calendar<DateType>::delete_event (std::string event_name, int day) {
	try {
		Event e(event_name, DateType(date.year(), date.month(), day));
		auto i = std::begin(events);
		while (i != std::end(events)) {
			if (*i==e) {
				std::cerr << " (remove " << (*i).getDesc() << ") ";
				i = events.erase(i);
				return true;
			} else {
				++i;
			}
		}
	} catch (const std::invalid_argument& ia) {
		return false;
	}
	return false;
}

template<class DateType>
bool Calendar<DateType>::delete_event (std::string event_name, int day, int month) {
	try {
		Event e(event_name, DateType(date.year(), month, day));
		auto i = std::begin(events);
		while (i != std::end(events)) {
			if (*i==e) {
				std::cerr << " (remove " << (*i).getDesc() << ") ";
				i = events.erase(i);
				return true;
			} else {
				++i;
			}
		}
	} catch (const std::invalid_argument& ia) {
		return false;
	}
	return false;
}

template<class DateType>
bool Calendar<DateType>::delete_event (std::string event_name, int day, int month, int year) {
	try {
		Event e(event_name, DateType(year, month, day));
		auto i = std::begin(events);
		while (i != std::end(events)) {
			if (*i==e) {
				std::cerr << " (remove " << (*i).getDesc() << ") ";
				i = events.erase(i);
				//delete i?
				return true;
			} else {
				++i;
			}
		}
		//delete i;
	} catch (const std::invalid_argument& ia) {
		return false;
	}
	return false;
}

////Calendar<DateType> const & ref
//template<class DateType>
//std::ostream& Calendar<DateType>::operator<<(std::ostream& out) { //, const Calendar<DateType> & ref) {
//
//	return out << "BEGIN:VCALENDAR";
//}

template<class DateType>
std::string Calendar<DateType>::get_date_ical_format(Event event) const {
	std::stringstream datestring;
	datestring << event.eventDate.year();
	if (event.eventDate.month() < 10) {
		datestring << "0";
	}
	datestring << event.eventDate.month();
	if (event.eventDate.day() < 10) {
		datestring << 0;
	}
	datestring << event.eventDate.day();
	return datestring.str();
}

template<class DateType>
std::string Calendar<DateType>::to_icalendar() const {
	std::stringstream ical;
	ical << "BEGIN:VCALENDAR" << std::endl << "VERSION:2.0" << std::endl << "PRODID:-//hacksw//A calendar//";
	auto i = std::begin(events);
	while (i != std::end(events)) {
		if((*i).eventDate >= date) {
			ical << std::endl << "BEGIN:VEVENT" << std::endl << "UID:uid1@example.com";
			ical << std::endl << "DTSTAMP:" << get_date_ical_format(*i) << "T080000Z";
			ical << std::endl << "ORGANIZER;CN=John Doe:MAILTO:john.doe@example.com";
			ical << std::endl << "DTSTART:" << get_date_ical_format((*i)) << "T080000Z";
			ical << std::endl << "DTEND:" << get_date_ical_format((*i)) << "T110000Z";
			ical << std::endl << "SUMMARY:" << (*i).eventDescription;
			ical<< std::endl <<"END:VEVENT";
		}
		++i;
	}
	ical<< std::endl <<"END:VCALENDAR";
	return ical.str();
}

template class Calendar<Gregorian>;
template class Calendar<Julian>;
}
