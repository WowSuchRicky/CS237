/*************************************************
 * Title:       Assignment1.cpp
 * Description: CS 237 Assignment #1
 *              This C++ file contains all methods needed to run Assignment 1.  It contains a constructor
 *              that reads in the names.txt file line by line to instantiate an array of Data objects using the
 *              default constructor of BabyNames.
 *              It also contains sort methods that sort the object based on it's data members. One
 *              sorts by the percentage of babies with a certain name, and the other sorts based on the
 *              string name.
 *              We use operator overloads to print the data object appropriately.
 * Author:      Caitlin Finn
 *              caitlin.finn@uwrf.edu
 * Created:     February 21st 2012
 * Modified:    February 28rd 2012
 * Team:        Ricky Mutchlechner, Erin McNeil
 *************************************************/

#include <fstream>
#include "BabyNames.h"

BabyNames::BabyNames() {
	string line;

//the variable of type ifstream:
	ifstream myfile("names.txt");

	getline(myfile, line); //get the first header line

//check to see if the file is opened:
	if (myfile.is_open()) {

		BabyNames::arrayIndex = 0; //initialize the array index to 0 before reading the file

		//continue to read the file until the end of the file is reached
		while (!myfile.eof()) {
			//every new line is a new object in the next open spot in the array
			//place each data member from myfile into the appropriate variable:

			short year;
			std::string name;
			double percent;
			string genderStr;
			//read in the file by checking for white space
			myfile >> year;
			myfile >> name;
			myfile >> percent;
			myfile >> genderStr;
			//check the gender string and pass the enum value when instantiating the object
			if (genderStr == "girl") {
				data[arrayIndex] = (Data ) { year, name, percent, girl };
			} else
				data[arrayIndex] = {year, name, percent, boy};

			datasize = 20; //tells the size of the input -- change to 258001 to read entire names.txt file
							   //change to a smaller number for testing purposes (i.e 20)

			arrayIndex++; //move to the next open index in the array to fill with data
		}
//close the stream:
		myfile.close();

	}

	else
		//if the file never opened, print the following error
		cout << "Unable to open file";

}

/*
 * getDataSize() - Returns the size of the Data array
 * arguments: None
 * returns: The size (int) of the array - datasize.
 */
int BabyNames::getDataSize() const {
	return datasize;
}
/*
 * get(int i) - returns the Data array at a given index
 * arguments: and integer index value
 * returns: the array at the given index
 * If the index is out of the bounds of the array, it will throw OUT_OF_BOUNDS
 * pre-conditions: i >= 0 && i < datasize
 * post-conditions: if (i >= 0 && i < datasize)	return data[i];
	throw OUT_OF_BOUNDS;
 */
const Data& BabyNames::get(int i) const {
	if (i >= 0 && i < datasize)
		return data[i];
	throw OUT_OF_BOUNDS;
}
/*
 * Sort by Name function
 * Description: Sorts the array by the strings for names using string::compare
 * and iterating through the array comparing onen value to the rest of the values
 * in the array
 *
 * Arguments: none
 * Return value: none
 * pre-conditions:
 * post-conditions:
 */
void BabyNames::sortByName() {
	for (int i = 0; i < datasize; i++) {
		for (int j = 0; j < datasize; j++) {
			if (data[j].name.compare(data[i].name) > 0)
				swapValues(i, j);

		} //end of j for loop
	} //end of i for loop
} //end of sortByName

/*******************************************************************/
/*
 * Sort by Popularity function
 * Description: Sorts the array by the double value for the percentage
 * of babies with the same name
 *
 * Parameters: double Array, and array size
 * Preconditions: size <= size of array a
 * Postcondition: values of a[0] through a[size - 1]
 *  are rearranged so that a[0] <= a[1] <= ... <= a[numberUsed - 1].
 * Return value: void
 */
void BabyNames::sortByPopularity() {
	int indexOfNextSmallest;
	for (int index = 0; index < datasize; index++) { //Place the correct value in a[index]:
		indexOfNextSmallest = indexOfSmallest(data, index, datasize);
		swapValues(index, indexOfNextSmallest);
//a[0] <= a[1] <=...<= a[index] are the smallest of the original array
//elements. The rest of the elements are in the remaining positions.
	}
}
/*******************************************************************/

/*******************************************************************
 * swap - swap the values in the two inputs
 * arguments: int v1, int v2
 * these arguments are indecies of the array to be swapped
 * return: none
 */
void BabyNames::swapValues(const int v1, const int v2) {
	Data temp = data[v1];
	data[v1] = data[v2];
	data[v2] = temp;
}

/*******************************************************************/

/*******************************************************************
 * indexOfSmallest - find the index of the smallest element in an array
 * Preconditions: size > 0 and a has at least size elements,
 *                0 <= startIndex < size
 * Postcondition: old_value_of_startIndex <= startIndex < size;
 *                The element at a[ startIndex ] will be the smallest
 *                element in the range a[ old_start .. size-1 ]
 * Arguments: Data array, int startIndex, int size
 * Returns: the index of the smaller number
 */

int BabyNames::indexOfSmallest(const Data a[], int startIndex, int size) {
	double min = a[startIndex].percent;
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index < size; index++)
		if (a[index].percent < min) {
			min = a[index].percent;
			indexOfMin = index;
//min is the smallest of a[startIndex] through a[index]
		}

	return indexOfMin;
}
//overloads the << operator to correctly print the contents of the Data struct
std::ostream& operator<<(std::ostream& os, const Data& d) {
	os << d.name << " " << d.year << " " << d.percent << " " << d.sex;
	return os;
}
//overloads the << operator in terms of BabyNames and returns a formatted BabyNames Object return
std::ostream& operator<<(std::ostream& os, const BabyNames& bn) {
	os << "  BabyNames object " << std::endl;
	for (int i = 0; i < bn.getDataSize(); i++)
		os << "    " << (i + 1) << ":  " << bn.get(i) << std::endl;
	return os;
}

