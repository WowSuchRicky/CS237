/*
 * Lab4C.cpp
 *
 *  Created on: 2013-02-12
 *      Author: tony
 *              Contains code from "Absolute C++" by Savitch
 *
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void fillArray(double a[], const int size);
void sort(double a[], const int size);

void start_clock();
void stop_clock();

int main(){
	const int MIN_PROBLEM_SIZE = 1000;
	const int MAX_PROBLEM_SIZE = 1024000;

	for (int size=MIN_PROBLEM_SIZE; size<=MAX_PROBLEM_SIZE; size=size*2){
	   /*
	    * set up random data for sorting
	    */
	   double data[ size ];
	   fillArray( data, size );

	   /*
	    * Start clock, sort, and stop clock.
	    */
	   cout << "Sorting (size=" << size << ") ... " << flush;
	   start_clock();

	   sort( data, size );

	   stop_clock();
	   cout << "... done sorting!" << endl;
	}
}

/*******************************************************************
 * fillArray - fill an array with random values
 * Preconditions: The number of elements in array a is at least size.
 * Postcondition: The elements of a will be set to random numbers
 */
void fillArray(double a[], const int size) {
    const double RAND_SHIFT = (RAND_MAX / 2.0);
	for ( int i=0; i<size; i++ )
		a[i] = rand() - RAND_SHIFT;
	return;
}
/*******************************************************************/

/*******************************************************************
 * swap - swap the values in the two inputs
 * Preconditions:
 * Postcondition:
 */
void swapValues(double& v1, double& v2) {
    double temp = v1;
    v1 = v2;
    v2 = temp;
}
/*******************************************************************/


/*******************************************************************
 * indexOfSmallest - find the index of the smallest element in an array
 * Preconditions: size > 0 and a has at least size elements,
 *                0 <= startIndex < size
 * Postcondition: old_value_of_startIndex <= startIndex < size;
 *                The element at a[ startIndex ] will be the smallest
 *                element in the range a[ old_start .. size-1 ]
 */
int indexOfSmallest(const double a[], int startIndex, int size)
{
    double min = a[startIndex];
    int    indexOfMin = startIndex;
    for (int index = startIndex + 1; index < size; index++)
        if (a[index] < min) {
            min = a[index];
            indexOfMin = index;
            //min is the smallest of a[startIndex] through a[index]
        }

    return indexOfMin;
}
/*******************************************************************/



/*******************************************************************
 * search
 * Precondition: size is <= the declared size of array a.
 * Postcondition:
 * Returns the first index such that a[index] == target,
 * provided there is such an index, otherwise returns -1.
 *
 */
int search(const double a[], int size, double target){
    int index = 0;
    bool found = false;
    while ((!found) && (index < size))
    if (target == a[index])
        found = true;
    else
        index++;

    if (found)
        return index;
    else
        return -1;
}
/*******************************************************************/

/*******************************************************************
 * sort
 * Preconditions: size <= size of array a
 * Postcondition: values of a[0] through a[size - 1]
 *  are rearranged so that a[0] <= a[1] <= ... <= a[numberUsed - 1].
 */
void sort(double a[], const int size)
{
    int indexOfNextSmallest;
    for (int index = 0; index < size - 1; index++)
    {//Place the correct value in a[index]:
        indexOfNextSmallest =
                     indexOfSmallest(a, index, size);
        swapValues(a[index], a[indexOfNextSmallest]);
        //a[0] <= a[1] <=...<= a[index] are the smallest of the original array
        //elements. The rest of the elements are in the remaining positions.
    }
}
/*******************************************************************/

/*
 * Timing for Windows
 */
#include <sys/time.h>
#include "resource.h"
extern "C" {
int getrusage(int who, struct rusage *r_usage);
}
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

	cout << "   User time:   " << (end_tu - start_tu)  << "\t\tSystem time: " << (end_ts - start_ts);
}
