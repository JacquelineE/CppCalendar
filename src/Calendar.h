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
public:
	class Event {
	public:
		DateType eventDate; //use unique_pointer
		std::string eventDescription;

		Event(std::string description, DateType date) {
			this->eventDescription = description;
			this->eventDate = date;
		}
		bool operator==(const Event& ref) const {
			return (this->eventDate == ref.eventDate) && ((this->eventDescription).compare(ref.eventDescription) == 0);
		}
		DateType const getDate() {
			return eventDate;
		}
		std::string const getDesc() {
			return eventDescription;
		}
	};
	Calendar();
	Calendar(Calendar const & ref);
	template <class DateType2> Calendar(Calendar<DateType2> const & ref) {
		std::cerr << "copy different calendars "  << date << std::endl; //translates automatically!?
	}
	virtual ~Calendar();

	bool set_date(int year, int month, int day);
	bool add_event (std::string description);
	bool add_event (std::string event_name, int day);
	bool add_event (std::string event_name, int day, int month);
	bool add_event (std::string event_name, int day, int month, int year);
	bool delete_event (std::string event_name);
	bool delete_event (std::string event_name, int day);
	bool delete_event (std::string event_name, int day, int month);
	bool delete_event (std::string event_name, int day, int month, int year);
	friend std::ostream& operator<<(std::ostream& out, const Calendar<DateType>& ref) {
		return out << ref.to_icalendar();
	}
//	Calendar<DateType> const & ref

private:
	DateType date;
	std::vector<Event> events;

	bool has_event(Event const event) const;
	std::string to_icalendar() const;
	std::string get_date_ical_format(Event event) const;
};

//std::ostream& operator<<(std::ostream& out, const Calendar& ref); //iCalendar format

}
#endif /* CALENDAR_H_ */
