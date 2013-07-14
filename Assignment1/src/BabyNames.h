/*************************************************
 * Title:       BabyNames.h
 * Description: CS 237 Assignment #1
 *              This header file is an interface that contains the Data Struct and its data members
 *              along with the BabyNames class and it's data members and method heads.
 * Author:      Caitlin Finn
 *              caitlin.finn@uwrf.edu
 * Created:     February 21st 2012
 * Modified:    February 28rd 2012
 * Team:        Ricky Mutchlechner, Erin McNeil
 *************************************************/

#ifndef BABYNAMES_H_
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std;
/*
 * Data Struct
 * Contains data members for the year, name, percent of babies born with the name, and an enum
 * for the gender of the babyName.
 */
enum Gender {
	boy, girl
};
struct Data {
	short year;
	string name;
	double percent;

	Gender sex;
};

/*
 * BabyNames class
 * contains a max value for the Data array of objects, the variable to keep track of the size of the array
 * and method heads for sorting and getting and setting data members.
 */
class BabyNames {
	static const int MAX_DATA_SIZE = 258001; //sets max data to the number of entries in the names.txt file
	Data data[MAX_DATA_SIZE]; //creates an array of Data objects
	int datasize;
	static const int OUT_OF_BOUNDS = -1; //used to check bounds of array
	int arrayIndex; //used to keep track of where we are when filling the array with data objects
public:
	BabyNames();
	void sortByName();
	void sortByPopularity();
	int getDataSize() const;
	Data getData(int index);
	const Data& get(int i) const;

private:
	void swapValues(const int v1, const int v2);
	int indexOfSmallest(const Data a[], int startIndex, int size);

};
//method headers for operator overloading
std::ostream& operator<<(std::ostream& os, const Data& d);

std::ostream& operator<<(std::ostream& os, const BabyNames& bn);

#define BABYNAMES_H_
#endif
