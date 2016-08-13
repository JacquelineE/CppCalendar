//============================================================================
// Name        : lab2.cpp
// Author      : Jacqueline Eriksson, Mitra Strandberg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
#include <ctime>
 #include <typeinfo>
//#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "kattistime.h"
//using namespace std;
using namespace lab2;
using namespace std;
int main() {

	////////////////////////////////////////////////////////////
	// Sätt tiden. OBS skicka inte nedanstående kod till kattis
	time_t mytime;
	time(&mytime);
	set_k_time(mytime);
	////////////////////////////////////////////////////////////

//	Julian j = Julian(2140,1,31);
//	cout << j << "mod jul day" << j.mod_julian_day()<< endl;
//	j.add_month(2);
//	cout <<"1. "<< j << "mod jul day" << j.mod_julian_day() << endl;
//	j.add_month(-1);
//	cout <<"2. "<< j << "mod jul day" << j.mod_julian_day() << endl;

	Julian today;
	cerr << today.getOffset() << endl << today << endl << today.mod_julian_day() << " J:" << today.getJulian() <<endl << endl;
	Julian today2(2034, 7, 26);
	cerr << today2 << endl << today2.mod_julian_day() << endl << "OK"<< endl <<endl;

	Julian j1(2034, 7, 26);
	cerr << j1.mod_julian_day() << " j1:" << j1 << endl << endl;

	Julian jtoday;
	cerr << jtoday.mod_julian_day() << " jtoday:" << jtoday << endl;
	Gregorian gtoday;
	cerr << gtoday.mod_julian_day() << " gtoday:" << gtoday << endl << endl;

	Gregorian g2160(2160, 1, 5);
	cerr << g2160.mod_julian_day() << " g2160:" << g2160 << endl << endl;

	Gregorian g = Gregorian(2016, 1, 5);
	Julian j(g);
	cerr << j.mod_julian_day() << " j:" << j << endl;
	cerr << g.mod_julian_day() << " g:" << g << endl << endl;

	Gregorian g42(2042, 11, 23);
	Date& gDF = g42;
	Gregorian gF(gDF);
	cerr << gDF.mod_julian_day() << " gDF:" << gDF << " typeid:" << typeid(gDF).name() << endl;
	cerr << gF.mod_julian_day() << " gF:" << gF << " typeid:" << typeid(gDF).name() << endl << endl;

//	Julian jErr(2134, 20, 29);
//	cerr << jErr.mod_julian_day() << " jErr:" << jErr << endl;

	//TESTFILE

//	Julian tj;                  // ok: defaultkonstruktor ger dagens datum
//	    Gregorian gtoday;           // ok för gregorian också
//	    std::cout << "Idag är det " << gtoday << std::endl;
//	    assert(tj - gtoday == 0);
//	    Gregorian tg(2006, 10, 31); // ok: sätt datum explicit
//	                                // följande fungerar också:
//	                                // Gregorian(2000, Gregorian::October, 31)
//	    Date &j = tj;               // åtkomst av funktioner genom Dates interface
//	    Date &g = tg;
//	    Date &today = gtoday;
//
//	    {
//	      Julian j1;
//	      Date & d1 = j1;
//	      Julian j2(d1);
//	      Date * dp = &j2;
//	      Julian j3(dp);
//	    }

//	    time_t tp;
//	    time(&tp);
//	    struct tm *t = gmtime(&tp);
//	    int year  = t->tm_year + 1900;
//	    int month = t->tm_mon + 1;      // månaderna och dagarna
//	    int day   = t->tm_mday;         // indexerade från ETT
//
//	    std::cout << "Testing constructors..." << std::endl;
//	    assert(today.year() == year &&          // rätt initierad
//	           today.month() == month &&
//	           today.day() == day);
//	    assert(g.year() == 2006 &&              // rätt initierad
//	           g.month() == 10 &&
//	           g.day() == 31);                  // obs! ettindexerade
//
//	    std::cout << "Testing access..." << std::endl;
//	    assert(g.days_per_week() == 7);         // rätt antal dagar per vecka
//	    assert(j.days_per_week() == 7);         // rätt antal dagar per vecka
//	    assert(g.days_this_month() == 31);      // rätt antal dagar denna månad
//	    assert(g.week_day() == 2); // rätt veckodag
//
//	    std::cout << "Testing manipulation..." << std::endl;
//	    ++g;                                    // prefix ökning
//	    assert(g.week_day() == 3); // rätt veckodag
//	    --g;                                    // prefix minskning
//	    assert(g.week_day() == 2); // rätt veckodag
//	    g += 2;                                 // lägg till två dagar
//	    assert(g.week_day() == 4); // rätt veckodag
//	    g -= 3;                     // dra bort tre dagar
//	    g.add_month();              // lägg till en månad
//	    g.add_month(-1);            // dra bort en månad
//	    g.add_year(10);             // lägg till tio år.
//
//	    std::cout << "Testing miscellaneous functions..." << std::endl;
//	    Julian jj(tj);              // kopieringskonstruktor
//	    const Gregorian gg;
//	    gg.year();                  // gg konstant, läsa går bra
//	    g = gg;                     // tilldelning
//	    if(g == gg ||               // jämförelse
//	       g != gg ||               // jämförelse
//	       g < gg ||                // jämförelse
//	       g >= gg)                 // jämförelse
//	        {}
//
//	    std::cout << "Testing boundary violations";
//	    Gregorian temp(1900, 1, 1);
//	    Date &d = temp;
//
//	    // loopa över dagar och kolla att inga gränser över/underskrids
//	    for(int i = 0; i < 100000; ++i, ++d)
//	        {
//	            if(!(i % 5000))        // utskrift på framsteg
//	                {
//	                    std::cout << ".";
//	                    flush(std::cout);
//	                }
//	            int m[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//	            if(d.year() >= 1900 &&
//	               d.month() >= 1 && d.month() <= 12 &&
//	               d.day() >= 1 && d.day() <= m[d.month() - 1])
//	                {}
//	            else
//	                {
//	                    std::cout << std::endl;
//	                    std::cout << "boundary checks failed: " << std::endl;
//	                    std::cout << d.year() << ", "
//	                              << d.month() << ", "
//	                              << d.day() << std::endl;
//	                    return 1;
//	                }
//	        }
//	    std::cout << std::endl;
//
//	    std::cout << "Testing leap years..." << std::endl;
//	    // testa om skottåren för sekelskiften fungerar som de ska
//	    for(int y = 1958; y < 2500; y += 100)
//	        {
//	            Gregorian temp(y, 2, 28);
//	            Date &e = temp;
//	            ++e;                                   // lägg till en dag
//	            if((y % 400 == 0 && e.day() == 29) ||  // skottdag (obs! ETTindexerad)
//	               (y % 400 != 0 && e.day() == 1))     // ej skottdag
//	                {}
//	            else
//	                {
//	                    std::cout << std::endl << "leap day test failed: " << std::endl;
//	                    std::cout << e.year() << ", "
//	                              << e.month() << ", "
//	                              << e.day() << std::endl;
//	                    return 1;
//	                }
//	        }
//
//	    std::cout << std::endl << "All tests were successful." << std::endl;
//
//	    // följande ska inte gå att kompilera
//	#if 0
//	    gg.leap_year();             // fel: kan inte komma åt protected/private medlem
//	    gg = g;                     // fel: kan inte tilldela konstant
//	    ++gg;                       // fel: kan inte ändra på en konstant
//	#endif

	//TESTFILE



//	//set current time before testing
//	time_t tp;
//	time(&tp);
//	std::cerr << "time is " << tp << std::endl;
//	set_k_time(tp);
//
//
//	std::cerr << std::endl << "lets build gregorian!" << std::endl;
//	Date * g = new Gregorian();
//	std::cerr << *g << std::endl;
//	Gregorian g2;
//	std::cerr << std::endl << "lets copy construct gregorian!" << std::endl;
//	Gregorian g3(g2);
//	std::cerr << std::endl << "lets decrement gregorian!" << std::endl;
//	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
//	--g2; //pre-decrement
//	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
//	g2--;
//	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
//	g2-=10;
//	std::cerr << "g2 offset: " << g2.getOffset() << std::endl;
//	std::cerr << "diff g2-g3: " << g2-g3 << std::endl << std::endl;
//
//	int year = g -> year();
//	std::cerr << year << g->month() << "day" << g->day() << std::endl;
//
//	std::cerr << std::endl << "lets build julian!" << std::endl;
//	Date * j = new Julian();
//	std::cerr << *j << std::endl;
//	Julian j2;
//	std::cerr << std::endl << "lets copy construct Julian!" << std::endl;
//	Julian j3(j2);
//	std::cerr << std::endl << "lets decrement Julian!" << std::endl;
//	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
//	--j2; //pre-decrement
//	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
//	j2--;
//	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
//	j2 += 10;
//	std::cerr << "j2 offset: " << j2.getOffset() << std::endl;
//	std::cerr << "j2<=*j: " << (j2<=*j) << "  j2>=*j: " << (j2>=*j) << std::endl;
//	std::cerr << "*j: " << *j << ". j2: " << j2 << "." << std::endl << "*j = j2" << std::endl;
//	std::cerr << "offset *j=" << (*j).getOffset() << std::endl;
//	std::cerr << "offset j2=" << (j2).getOffset() << std::endl;
//	*j=j2;
//	std::cerr << "AFTER: offset *j=" << (*j).getOffset() << std::endl;
//	std::cerr << "offset *g=" << (*g).getOffset() << std::endl;
//	*g=j2;
//	std::cerr << "AFTER: offset j2=" << (j2).getOffset() << std::endl;
//	std::cerr << "offset *g=" << (*g).getOffset() << std::endl;
//	std::cerr << "j2 " << j2 << "  *g " << *g << std::endl;
//	std::cerr << std::endl << "lets build Julian again!" << std::endl;
//	Julian gToday;
//	std::cerr << "MJD today:" << gToday.getJulian() << " offset:" << gToday.getOffset() << " date:" << gToday << std::endl << std::endl;
//	Julian gToday2(2016, 8, 11);
//	std::cerr << "MJD today2:" << gToday2.getJulian() << " offset today2:" << gToday2.getOffset() << " date:" << gToday2 << std::endl << std::endl;
//	Julian g1858(1858, 1, 1);
//	std::cerr << "MJD 1858:" << g1858.getJulian() << " offset:" << g1858.getOffset() << " date:" << g1858 <<std::endl << std::endl;
//	Julian g1857(1857, 12, 31);
//	std::cerr << "MJD 1857:" << g1857.getJulian() << " offset:" << g1857.getOffset() << " date:" << g1857 << std::endl << std::endl;
//
//	std::cerr << "week_day_name:" << gToday.week_day_name() << " week_day:" << gToday.week_day() << " month_name:" << gToday.month_name() << std::endl;
//	gToday -= 3;
//	std::cerr << "week_day_name:" << gToday.week_day_name() << " week_day:" << gToday.week_day() << " month_name:" << gToday.month_name() << std::endl;
//	gToday--;
//	std::cerr << "week_day_name:" << gToday.week_day_name() << " week_day:" << gToday.week_day() << " month_name:" << gToday.month_name() << std::endl;
//	gToday -= 20;
//	std::cerr << gToday << " week_day_name:" << gToday.week_day_name() << " week_day:" << gToday.week_day() << " month_name:" << gToday.month_name() << std::endl << std::endl;
//
//	//	//hitta när offset = 0 för julian:
//	//	int off = gToday.getOffset();
//	//	while(off > 0) {
//	//		--gToday;
//	//		--off;
//	//		if(gToday.getOffset() == 0) {
//	//			std::cerr << "offset is 0 on: " << gToday << "| julian_day_number:" << gToday.getJulian() << std::endl;
//	//		}
//	//	}
//
//
//	//	std::cerr << j -> year() << j->month() << "day" << j->day() << std::endl;
//	//	std::cerr << "days in month g: " << g-> days_this_month()  << "jul: " << j->days_this_month() << std::endl;
//	//	std::cerr << "monthname g: " << g-> month_name()  << "jul: " << j->month_name() << std::endl;
//	//	g->add_year(200);
//	//	std::cerr << "addYear"  << "new year" << g->year() << std::endl;
//
//	Date * gr2 = new Gregorian();
//	cout << *gr2 << endl;
//	Gregorian gr;
//	Gregorian gr3(gr);
//	gr.add_year(2);
//	gr.add_month(7);
//	gr.add_day(20);
//	/////////////////
//	cout << "5y " << gr << endl;
//	for(int i = 0; i < 100; i++) {
//		gr.add_month(15);
//		cout << gr << endl;
//	}



	return 0;
}
