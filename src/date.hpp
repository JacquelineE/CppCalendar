/*
 * Date.hpp
 *
 *  Created on: Aug 2, 2016
 *      Author: je
 */

#ifndef LAB2_SRC_DATE_HPP_
#define LAB2_SRC_DATE_HPP_
#include <string>

namespace lab2 {

	class Date {

	//friends
	private:



	//friends and inherits
	protected:
		static int monthsLengthNormalYear[12];
		static std::string monthsName[12];
		int kStartYear = 1858;
		int kUnixStart = 1970;
		int kJulOffsetDiff1858 = 13;
		int offset;

		virtual int leap_years_before(int year) const = 0;
		virtual bool is_leap_year(int year) const = 0;

		virtual void set_offset(long int currTime);
		int leap_years_between(int startYear, int endYear) const;
		int days_between(int startYear = 1858, int = 1970) const;

		int get_difference_in_days(const Date& ref, int startYear, int endYear);
		//int offset_protected();


	public:
		Date();
		virtual ~Date(); // = 0;
		unsigned int year() const;
		unsigned int month() const;
		unsigned int day() const;
		unsigned int days_per_week() const;
		unsigned int days_this_month() const;
		std::string month_name() const;
		void add_year (int n = 1);
		void add_month(int n = 1);
		void add_day(int n = 1);

	//	virtual unsigned int month() = 0;
	//	virtual unsigned int day() = 0;
	//	virtual unsigned int week_day() = 0;
	//	virtual unsigned int days_per_week() = 0;
	//	virtual int days_this_month() = 0;
	//	virtual std::string month_name() = 0;
	//	virtual void add_year() = 0; //int n =1
	//	virtual void add_month() = 0; //int n = 1
	//	virtual int mod_julian_day() = 0;

		int getOffset(); //TODO just for testing, remove later
		int operator-(const Date& ref);
		bool operator==(const Date& ref);
		bool operator!=(const Date& ref);
		bool operator<(const Date& ref);
		bool operator>(const Date& ref);
		bool operator<=(const Date& ref);
		bool operator>=(const Date& ref);
		virtual Date& operator++() = 0;
		virtual Date& operator--() = 0;
		//TODO kollaa om post increment kan va pure virtual
		virtual Date& operator+=(const int& n) = 0;
		virtual Date& operator-=(const int& n) = 0;
		Date& operator=(const Date& ref);
		//virtual Date& operator=(const Date& ref) = 0;

	};

	std::ostream& operator<<(std::ostream& out, const Date& ref);

}

#endif /* LAB2_SRC_DATE_HPP_ */
