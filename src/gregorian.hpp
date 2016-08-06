/*
 * Gregorian.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_GREGORIAN_HPP_
#define LAB2_SRC_GREGORIAN_HPP_


class Gregorian : public Date {

private:
	virtual int leap_years_before(int year);
public:
	Gregorian();
	~Gregorian();
	//int year();
};

#endif /* LAB2_SRC_GREGORIAN_HPP_ */
