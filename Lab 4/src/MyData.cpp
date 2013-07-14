/*
 * MyData.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: uwrf
 */

#include "MyData.h"

/*
	 * Constructor for MyData
	 */
	MyData :: MyData(int id_in, double data_in[DATA_SIZE] ){
		if (id_in > 0)
			id = id_in;
		else
			id = 0;

		for (int i = 0; i < DATA_SIZE; i++)
			data[i] = data_in[i];
//		data = data_in;
	};
	/*
	 * get methods
	 */
	int MyData :: getID(){
		return id;
	};

	/*
	 * Implementation of the setID method of the MyData class
	 */
	void MyData::setID(int i){
		if (i>0)
			id = i;
	}
	/*
	 * Implementation of the getSum method of the MyData class
	 */
	double MyData::getSum(){
		double sum = 0;
		for (int i = 0; i < DATA_SIZE; i++)
			sum = sum + data[i];
		return sum;
	}


