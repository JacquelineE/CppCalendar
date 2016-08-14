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

namespace lab2 {

template<class DateType> class Calendar {
	class Event {
	private:
		DateType eventDate; //use unique_pointer
		std::string description;
	public:
		Event(std::string desc, Date* dat) {
			this->description = desc;
			this->eventDate = dat;
		}

	};
private:
	DateType date;
	std::vector<Event> events;

public:
	Calendar();
	//	Calendar(Calendar& ref);
	virtual ~Calendar();

	//	bool set_date(int year, int month, int day);
	//	bool add_event (std::string event_name);
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
