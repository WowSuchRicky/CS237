/*
 * MyData.h
 *
 *  Created on: Feb 23, 2013
 *      Author: uwrf
 */

#ifndef MYDATA_H_
#define MYDATA_H_

/*************************************************************
 * A simple class with two data members and three methods.
 *************************************************************/
class MyData{
public:
	static const int DATA_SIZE = 10;
	/*
	 * Constructor for MyData
	 */
	MyData(int id_in, double data_in[DATA_SIZE] );
	/*
	 * get methods
	 */
	int getID();

	/*
	 * The body of this set method is at the end of this file
	 */
	void setID(int i);
	double getSum();
private:
	int id;
	double data[ DATA_SIZE ];
};
/*************************************************************/



#endif /* MYDATA_H_ */
