/*
 * Gregorian.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_GREGORIAN_HPP_
#define LAB2_SRC_GREGORIAN_HPP_

#include "date.hpp"

namespace lab2 {

class Gregorian : public Date {

protected:
	virtual int leap_years_before(int year) const; //p
	virtual bool is_leap_year(int year) const; //p
	virtual int calc_julian_day_number(int year, int month, int day) const; //p
	virtual int get_offset_from_julian_day(int julian_day) const; //p
	virtual int julian_day_on_start_offset() const; //p
	virtual int outside_range_error(int julian_day) const;

public:
	Gregorian();
	Gregorian(const Date & ref);
	Gregorian(const Date * ptr);
	Gregorian(int year, int month, int day);
	virtual ~Gregorian();

	//we can't instantiate date because of pure virtual methods in Date?
	//therefore they are implemented in subclasses...
	virtual Gregorian& operator++();
	virtual Gregorian& operator--();
	Gregorian operator++(int);
	Gregorian operator--(int);
	virtual Gregorian& operator+=(const int& n);
	virtual Gregorian& operator-=(const int& n);

	friend Date& Date::operator=(const Date& ref);
};

}

#endif /* LAB2_SRC_GREGORIAN_HPP_ */
