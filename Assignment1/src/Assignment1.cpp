/*************************************************
 * Title:       Assignment1.cpp
 * Description: CS 237 Assignment #1
 *              This C++ file contains the main function of the BabyNames program for Assignment 1.
 *				It imports the BabyNames.h interface to access BabyNames class, a Data struct, and methods.
 *				It then creates an array of babyNames objects and calls two different sort methods
 *				to sort by Name and sort by popularity of the name.
 * Author:      Caitlin Finn
 *              caitlin.finn@uwrf.edu
 * Created:     February 21st 2012
 * Modified:    February 28rd 2012
 * Team:        Ricky Mutchlechner, Erin McNeil
 *************************************************/

#include "BabyNames.h"
using namespace std;

int main(void) {
	cout << "Baby names: " << endl;
	//create a BabyNames object
	BabyNames names;
	cout << names;
	cout << "Sorted by popularity" << endl;
	//Sort the babyNames by popularity
	names.sortByPopularity();
	cout << names;
	cout << "Sorted by name" << endl;
	//Sort the babyNames by Name
	names.sortByName();
	cout << names;
	cout << "... done!" << endl;
}
