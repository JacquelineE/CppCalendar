/*
 * Gregorian.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_GREGORIAN_HPP_
#define LAB2_SRC_GREGORIAN_HPP_


class Gregorian : public Date {

protected:
	virtual int leap_years_before(int year);
	virtual bool is_leap_year(int year);
	//int year();
public:
	Gregorian();// = default;
	~Gregorian();
	//int year();
};

#endif /* LAB2_SRC_GREGORIAN_HPP_ */
