/*
 * Date.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_DATE_HPP_
#define LAB2_SRC_DATE_HPP_

class Date {


private:
	void set_offset(long int currTime);
	static int leap_years_between(int startYear, int endYear);
	static int leap_years_before(int year);
	static int days_between(int startYear = 1858, int= 1970);

protected:
	int offset;

public:
	Date();
	~Date();
//
//	virtual int year() = 0;
//	virtual unsigned int month() = 0;
//	virtual unsigned int day() = 0;
//	virtual unsigned int week_day() = 0;
//	virtual unsigned int days_per_week() = 0;
//	virtual int days_this_month() = 0;
//	virtual std::string month_name() = 0;
//	virtual void add_year() = 0; //int n =1
//	virtual void add_month() = 0; //int n = 1
//	virtual int mod_julian_day() = 0;
};

#endif /* LAB2_SRC_DATE_HPP_ */
