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
#include "Calendar.h"
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

//	Julian today;
//	cerr << today.getOffset() << endl << today << endl << today.mod_julian_day() << " J:" << today.getJulian() <<endl << endl;
//	Julian today2(2034, 7, 26);
//	cerr << today2 << endl << today2.mod_julian_day() << endl << "OK"<< endl <<endl;
//
//	Julian j1(2034, 7, 26);
//	cerr << j1.mod_julian_day() << " j1:" << j1 << endl << endl;
//

	//TESTFILE

	Julian tj;                  // ok: defaultkonstruktor ger dagens datum
	    Gregorian gtoday;           // ok för gregorian också
	    std::cout << "Idag är det " << gtoday << std::endl;
	    assert(tj - gtoday == 0);
	    Gregorian tg(2006, 10, 31); // ok: sätt datum explicit
	                                // följande fungerar också:
	                                // Gregorian(2000, Gregorian::October, 31)
	    Date &j = tj;               // åtkomst av funktioner genom Dates interface
	    Date &g = tg;
	    Date &today = gtoday;

	    {
	      Julian j1;
	      Date & d1 = j1;
	      Julian j2(d1);
	      Date * dp = &j2;
	      Julian j3(dp);
	    }

	    time_t tp;
	    time(&tp);
	    struct tm *t = gmtime(&tp);
	    int year  = t->tm_year + 1900;
	    int month = t->tm_mon + 1;      // månaderna och dagarna
	    int day   = t->tm_mday;         // indexerade från ETT

	    std::cout << "Testing constructors..." << std::endl;
	    assert(today.year() == year &&          // rätt initierad
	           today.month() == month &&
	           today.day() == day);
	    assert(g.year() == 2006 &&              // rätt initierad
	           g.month() == 10 &&
	           g.day() == 31);                  // obs! ettindexerade

	    std::cout << "Testing access..." << std::endl;
	    assert(g.days_per_week() == 7);         // rätt antal dagar per vecka
	    assert(j.days_per_week() == 7);         // rätt antal dagar per vecka
	    assert(g.days_this_month() == 31);      // rätt antal dagar denna månad
	    assert(g.week_day() == 2); // rätt veckodag

	    std::cout << "Testing manipulation..." << std::endl;
	    ++g;                                    // prefix ökning
	    assert(g.week_day() == 3); // rätt veckodag
	    --g;                                    // prefix minskning
	    assert(g.week_day() == 2); // rätt veckodag
	    g += 2;                                 // lägg till två dagar
	    assert(g.week_day() == 4); // rätt veckodag
	    g -= 3;                     // dra bort tre dagar
	    g.add_month();              // lägg till en månad
	    g.add_month(-1);            // dra bort en månad
	    g.add_year(10);             // lägg till tio år.

	    std::cout << "Testing miscellaneous functions..." << std::endl;
	    Julian jj(tj);              // kopieringskonstruktor
	    const Gregorian gg;
	    gg.year();                  // gg konstant, läsa går bra
	    g = gg;                     // tilldelning
	    if(g == gg ||               // jämförelse
	       g != gg ||               // jämförelse
	       g < gg ||                // jämförelse
	       g >= gg)                 // jämförelse
	        {}

	    std::cout << "Testing boundary violations";
	    Gregorian temp(1900, 1, 1);
	    Date &d = temp;

	    // loopa över dagar och kolla att inga gränser över/underskrids
	    for(int i = 0; i < 100000; ++i, ++d)
	        {
	            if(!(i % 5000))        // utskrift på framsteg
	                {
	                    std::cout << ".";
	                    flush(std::cout);
	                }
	            int m[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	            if(d.year() >= 1900 &&
	               d.month() >= 1 && d.month() <= 12 &&
	               d.day() >= 1 && d.day() <= m[d.month() - 1])
	                {}
	            else
	                {
	                    std::cout << std::endl;
	                    std::cout << "boundary checks failed: " << std::endl;
	                    std::cout << d.year() << ", "
	                              << d.month() << ", "
	                              << d.day() << std::endl;
	                    return 1;
	                }
	        }
	    std::cout << std::endl;

	    std::cout << "Testing leap years..." << std::endl;
	    // testa om skottåren för sekelskiften fungerar som de ska
	    for(int y = 1958; y < 2500; y += 100)
	        {
	            Gregorian temp(y, 2, 28);
	            Date &e = temp;
	            ++e;                                   // lägg till en dag
	            if((y % 400 == 0 && e.day() == 29) ||  // skottdag (obs! ETTindexerad)
	               (y % 400 != 0 && e.day() == 1))     // ej skottdag
	                {}
	            else
	                {
	                    std::cout << std::endl << "leap day test failed: " << std::endl;
	                    std::cout << e.year() << ", "
	                              << e.month() << ", "
	                              << e.day() << std::endl;
	                    return 1;
	                }
	        }

	    std::cout << std::endl << "All tests were successful." << std::endl;

	    // följande ska inte gå att kompilera
	#if 0
	    gg.leap_year();             // fel: kan inte komma åt protected/private medlem
	    gg = g;                     // fel: kan inte tilldela konstant
	    ++gg;                       // fel: kan inte ändra på en konstant
	#endif

	//TESTFILE
	    cerr << endl << "===========================" << endl << endl;

//	    Calendar<Gregorian> calG;
//	    Calendar<Julian> calJ(calG);
//	    //cerr << "2011-3-3:" << calG.set_date(2011, 3, 3) << endl;
//	    cerr << "2011-30-30:" << calG.set_date(2011, 30, 30) << endl;
//	    cerr << endl << "add_event:" << endl;
//	    calJ.add_event("kalas");
//	    cerr << "försöker adda likadan:" << calJ.add_event("kalas") << endl;
//	    cerr << "correct:" << calJ.add_event("correct", 17, 7, 2007) << " incorrect:" << calJ.add_event("incorrect", 17, 21, 2007) << endl << endl;
//	    cerr << "delete kalas:" << calJ.delete_event("kalas") << " delete finns ej:" << calG.delete_event("wtf") << " delete incorrect:" << calJ.delete_event("wtf", 1000)<< endl;;

	    Calendar<Gregorian> cal;
	    cal.set_date(2000, 12, 2);
	    cal.add_event("Basketträning", 4, 12, 2000);
	    cal.add_event("Basketträning", 11, 12, 2000);
	    cal.add_event("Nyårsfrukost", 1, 1, 2001);
	    cal.add_event("Första advent", 1); // år = 2000, månad = 12
	    cal.add_event("Vårdagjämning", 20, 3); // år = 2000
	    cal.add_event("Julafton", 24, 12);
	    cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
	    cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
	    // ignoreras och inte sättas in i kalendern
	    cal.add_event("Min första cykel", 20, 12, 2000);
	    cal.delete_event("Basketträning", 4);
	    std::cout << cal; // OBS! Vårdagjämning och första advent är
	    // före nuvarande datum och skrivs inte ut
	    std::cout << "----------------------------------------" << std::endl;
	    cal.delete_event("Vårdagjämning", 20, 3, 2000);
	    cal.delete_event("Kalle Anka hälsar god jul", 24, 12, 2000);
	    cal.set_date(2000, 11, 2);
	    if (! cal.delete_event("Julafton", 24)) {
	    std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
	    << " bort något eftersom aktuell månad är november" << std::endl;
	    }
	    std::cout << "----------------------------------------" << std::endl;
	    std::cout << cal;


	return 0;
}
