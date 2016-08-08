/*
 * Julian.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_JULIAN_HPP_
#define LAB2_SRC_JULIAN_HPP_

class Julian : public Date {
public:
	Julian();
	~Julian();

private:
	static int const offsetShift = 12;
	virtual int leap_years_before(int year);
};

#endif /* LAB2_SRC_JULIAN_HPP_ */
