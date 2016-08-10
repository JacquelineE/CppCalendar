/*
 * Julian.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_JULIAN_HPP_
#define LAB2_SRC_JULIAN_HPP_

namespace lab2 {

class Julian : public Date {
public:
	Julian();
	Julian(Julian const& ref);
	~Julian();

	Julian& operator++();
	Julian& operator--();
	const Julian operator++(int);
	const Julian operator--(int);
	Julian& operator+=(const int& n);
	Julian& operator-=(const int& n);

private:
	virtual int leap_years_before(int year) const;
	virtual bool is_leap_year(int year) const;
	virtual void set_offset(long int currTime);
};

}

#endif /* LAB2_SRC_JULIAN_HPP_ */
