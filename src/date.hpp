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
		void decrement_year(int n);
		void increment_year(int n);
		void decrement_month(int n);
		void increment_month(int n);

	//friends and inherits
	protected:
		static int monthsLengthNormalYear[12];
		static std::string monthsName[12];
		static std::string daysName[7];
		int kStartYear = 1858;
		int kUnixStart = 1970;
		int kJulOffsetDiff1858 = 12;
		int julian_day_number;


		virtual int leap_years_before(int year) const = 0;
		virtual bool is_leap_year(int year) const = 0;
		int correct_day_number(int year, int month) const;

		int leap_years_between(int startYear, int endYear) const;
		int days_between(int startYear = 1858, int = 1970) const;

		int get_difference_in_days(const Date& ref, int startYear, int endYear);

		virtual int calc_julian_day_number(int year, int month, int day) const = 0;
		virtual int get_offset_from_julian_day(int julian_day) const = 0;
		virtual int julian_day_on_start_offset() const = 0;
		int get_julian_number_from_time(long int currTime) const;


	public:
		Date();
		Date(const Date & ref);
		virtual ~Date(); // = 0;
		unsigned int year() const;
		unsigned int month() const;
		unsigned int day() const;
		unsigned int week_day() const;
		unsigned int days_per_week() const;
		unsigned int days_this_month() const;
		std::string week_day_name() const;
		std::string month_name() const;
		void add_year (int n = 1);
		void add_month(int n = 1);
		void add_day(int n = 1);
		int mod_julian_day() const;
		std::string to_string() const;

		int getOffset(); //TODO just for testing, remove later
		int getJulian(); //TODO just for testing, remove later

		int operator-(const Date& ref) const;
		bool operator==(const Date& ref) const;
		bool operator!=(const Date& ref) const;
		bool operator<(const Date& ref) const;
		bool operator>(const Date& ref) const;
		bool operator<=(const Date& ref) const;
		bool operator>=(const Date& ref) const;
		virtual Date& operator++() = 0;
		virtual Date& operator--() = 0;
		//TODO kolla om post increment kan va pure virtual
		virtual Date& operator+=(const int& n) = 0;
		virtual Date& operator-=(const int& n) = 0;
		Date& operator=(const Date& ref);

	};

	std::ostream& operator<<(std::ostream& out, const Date& ref);

}

#endif /* LAB2_SRC_DATE_HPP_ */
