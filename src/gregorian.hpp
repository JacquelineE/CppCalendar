/*
 * Gregorian.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_GREGORIAN_HPP_
#define LAB2_SRC_GREGORIAN_HPP_

namespace lab2 {

class Gregorian : public Date {
protected:
	virtual int leap_years_before(int year) const;
	virtual bool is_leap_year(int year) const;
	//int year();
public:
	Gregorian();// = default;
	Gregorian(Gregorian const& ref);
	Gregorian(int year, int month, int day);
	~Gregorian();
	//int year();

	//we can't instantiate date because of pure virtual methods in Date?
	//therefore they are implemented in subclasses...
	virtual Gregorian& operator++();
	virtual Gregorian& operator--();
	const Gregorian operator++(int);
	const Gregorian operator--(int);
	virtual Gregorian& operator+=(const int& n);
	virtual Gregorian& operator-=(const int& n);
	friend Date& Date::operator=(const Date& ref);
};

}

#endif /* LAB2_SRC_GREGORIAN_HPP_ */
