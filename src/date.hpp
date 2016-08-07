/*
 * Date.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_DATE_HPP_
#define LAB2_SRC_DATE_HPP_

class Date {

//friends
private:



//friends and inherits
protected:
	static int monthsLengthNormalYear[12];
	int kStartYear = 1858;
	int kUnixStart = 1970;
	int offset;

	virtual int leap_years_before(int year) = 0;
	virtual bool is_leap_year(int year) = 0;

	void set_offset(long int currTime);
	int leap_years_between(int startYear, int endYear);
	int days_between(int startYear = 1858, int = 1970);



public:
	Date();
	virtual ~Date(); // = 0;
	unsigned int year();
	unsigned int month();
	unsigned int day();


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
