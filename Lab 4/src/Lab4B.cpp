/*
 * Lab4B.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: uwrf
 */

#include "MyData.h"
#include <iostream>
using namespace std;

int main(){
	double array1[ MyData::DATA_SIZE ] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
	double array2[ MyData::DATA_SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	MyData data1( 10, array1);
	MyData data2( -10, array2 );
	cout << " The data1 object has " << data1.getID() << " and sum "
		 << data1.getSum() << endl;
	cout << " The data2 object has " << data2.getID() << " and sum "
		 << data2.getSum() << endl << endl;

	/*
	 * Now, let's change array1 and see what happens to our object.
	 */
	array1[3] = 20;

	/*
	 * Now that we have changed the array1 variable,
	 * does this change data1? Let's find out:
	 */
	cout << " The data1 object has " << data1.getID() << " and sum "
		 << data1.getSum() << endl;

}


