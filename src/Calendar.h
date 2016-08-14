/*
 * Calender.h
 *
 *  Created on: 14 aug. 2016
 *      Author: Mitra
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "date.hpp"
#include <vector>
#include <iostream>

namespace lab2 {

template<class DateType> class Calendar {
	class Event {
	private:
		DateType eventDate; //use unique_pointer
		std::string eventDescription;
	public:
		Event(std::string description, DateType date) {
			this->eventDescription = description;
			this->eventDate = date;
		}
	};
private:
	DateType date;
	std::vector<Event> events;

public:
	Calendar();
	Calendar(Calendar const & ref);
	template <class DateType2> Calendar(Calendar<DateType2> const & ref) {
		std::cerr << "copy different calendars "  << date << std::endl; //translates automatically!?
	}
	virtual ~Calendar();

	bool set_date(int year, int month, int day);
	bool add_event (std::string description);
	//	bool add_event (std::string event_name, int day);
	//	bool add_event (std::string event_name, int day, int month);
	//	bool add_event (std::string event_name, int day, int month, int year);
	//	bool delete_event (std::string event_name);
	//	bool delete_event (std::string event_name, int day);
	//	bool delete_event (std::string event_name, int day, int month);
	//	bool delete_event (std::string event_name, int day, int month, int year);
};

//std::ostream& operator<<(std::ostream& out, const Calendar& ref); //iCalendar format

}
#endif /* CALENDAR_H_ */
