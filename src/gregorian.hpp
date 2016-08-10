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
	//Gregorian(Julian const& ref);
	~Gregorian();
	//int year();


	Gregorian& operator++();
	Gregorian& operator--();
	const Gregorian operator++(int);
	const Gregorian operator--(int);
	Gregorian& operator+=(const int& n);
	Gregorian& operator-=(const int& n);
};

}

#endif /* LAB2_SRC_GREGORIAN_HPP_ */
