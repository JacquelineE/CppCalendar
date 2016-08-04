//============================================================================
// Name        : lab2.cpp
// Author      : Jacqueline Eriksson, Mitra Strandberg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include "date.hpp"
#include "kattistime.hpp"
using namespace std;

int main() {
	//set current time before testing
	time_t tp;
	time(&tp);
	std::cout << "time is " << tp << std::endl;
	set_k_time(tp);

	Date * d = new Date();
	return 0;
}
