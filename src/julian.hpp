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

private:
	virtual int leap_years_before(int year) const;
	virtual bool is_leap_year(int year) const;
	virtual void set_offset(long int currTime);

protected:
	virtual int calc_julian_day_number(int year, int month, int day) const;
	virtual int get_offset_from_julian_day(int julian_day) const;
	virtual int julian_day_on_start_offset() const;

public:
	Julian();
	Julian(Julian const& ref);
	Julian(int year, int month, int day);
	~Julian();

	virtual Julian& operator++(); //kan returna subklass av Date
	virtual Julian& operator--();
	const Julian operator++(int);
	const Julian operator--(int);
	virtual Julian& operator+=(const int& n);
	virtual Julian& operator-=(const int& n);

	friend Date& Date::operator=(const Date& ref);

};

}

#endif /* LAB2_SRC_JULIAN_HPP_ */
