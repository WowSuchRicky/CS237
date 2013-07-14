/*
 * Lab9A.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: Ricky Mutschlechner
 */

#include "HashTableEntry.h"
#include "HashTable.h"
using lab9::HashTable;

#include <iostream>
#include <cstddef>
#include <time.h>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib> // for rand and RAND_MAX

int getTime();


int main(){
	cout << "Lab 9 C - Hash Tables" << endl;

	const int NUMBER_OF_PAIRS = 1000;
	HashTable ht(NUMBER_OF_PAIRS);

	vector<int> keys;

	cout << "1. Generating data: " << NUMBER_OF_PAIRS << " pairs." << endl;

	const double HALF_RAND_MAX = RAND_MAX / 2;
	const double SCALE_FACTOR = 1e-6;

	for (int i=0; i<NUMBER_OF_PAIRS; i++) {
		//int  x = rand() % 100000;
		int x = rand() % 100;
		double y = ( rand() - HALF_RAND_MAX ) * SCALE_FACTOR;
		ht.add( x, y );
		keys.push_back( x );
	}
	cout << "    ... done" << endl << endl;


	cout << "2. Check if existing keys are found" << endl;
	bool keysFound = true;
	for (int k : keys){
		double x = ht.get( k );
		//if (x == HashTable::invalid_result){
		if(x == -999.999){
			cout << "   No value found for existing key: " << k << endl;
			keysFound = false;
		}
	}
	if (keysFound)
		cout << "   All keys found.";
	cout << endl << endl;


	const int NUMBER_OF_ITERATIONS = 100000;
	cout << "3. Timing " << NUMBER_OF_ITERATIONS*NUMBER_OF_PAIRS << " key searches" << endl;
   /*
    * Start clock, search, and stop clock.
    */
    double startTime = getTime();
    for (int i=0; i<NUMBER_OF_ITERATIONS; i++)
    	for (int k : keys){
    		double x = ht.get( k );
    		//if (x == HashTable::invalid_result){
			if(x == -999.999){
    			cout << "   No value found for existing key: " << k << endl;
    			keysFound = false;
    		}
    	}
	cout << "It took: " << (getTime() - startTime) << " seconds to iterate.";
	_sleep(15000);
}



//I had to make something like this, because the start_clock and stop_clock do not work on Windows.
//This function was created using the Example from:
// http://www.cplusplus.com/reference/ctime/time/
//Authors: cplusplus.com, Ricky Mutschlechner
int getTime(){
	time_t timer;
	struct tm y2k;
	double seconds;

	y2k.tm_hour = 0; y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);

	seconds = difftime(timer, mktime(&y2k));

	return seconds;
}


 /* Timing for Linux 

#include <sys/time.h>
#include <sys/resource.h>
timeval start_timevalue_user;
timeval start_timevalue_system;
void start_clock(){
	rusage  resource_usage;
	getrusage( RUSAGE_SELF, &resource_usage );
	start_timevalue_user   = resource_usage.ru_utime;
	start_timevalue_system = resource_usage.ru_stime;
}

void stop_clock(){
	rusage  resource_usage;
	getrusage( RUSAGE_SELF, &resource_usage );
	timeval end_timevalue_user   = resource_usage.ru_utime;
	timeval end_timevalue_system = resource_usage.ru_stime;

	double end_tu = end_timevalue_user  .tv_sec + end_timevalue_user  .tv_usec / 1.0e6;
	double end_ts = end_timevalue_system.tv_sec + end_timevalue_system.tv_usec / 1.0e6;

	double start_tu = start_timevalue_user  .tv_sec + start_timevalue_user  .tv_usec / 1.0e6;
	double start_ts = start_timevalue_system.tv_sec + start_timevalue_system.tv_usec / 1.0e6;

	cout << "   User time: " << (end_tu - start_tu)  << "  \tSystem time: " << (end_ts - start_ts) << " seconds" << endl;
}

*/
