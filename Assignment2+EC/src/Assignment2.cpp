/*************************************************
 * Title:       Assignment2.cpp
 * Description: CS 237 Assignment #2
 *              This C++ file contains the main function of the BabyNames program for Assignment 2.
 *				It imports the BabyNames.h interface to access BabyNames class, a Data struct, and methods.
 *				It then creates an array of babyNames objects, copies these objects 3 times, and calls 3 different sort methods
 *				to sort by Name, year, and sort by popularity of the name for each copy of the BabyNames object.
 * Author:      Caitlin Finn
 *              caitlin.finn@uwrf.edu
 * Created:     March 16 2013
 * Modified:    March 18 2013
 * Team:        Ricky Mutchlechner, Erin McNeil
 *************************************************/

#include "BabyNames.h"
using namespace std;

int main(void) {
	cout << "Baby names: " << endl;

	//create a BabyNames object

	//get the number of lines in the file
	int sizeOfFile = getFileSize();

	BabyNames* names = new BabyNames(sizeOfFile);
	cout << "number of lines in the file is: " << sizeOfFile << endl;
	cout << "number of lines to be read from the file is: "
			<< names->getDataSize() << endl;

	cout << *names;

	BabyNames* namesByPopularity = new BabyNames(*names);

	//make a copy of the original names file
	cout << "2. Sorted by popularity: " << endl;
	//Sort the babyNames by popularity
	namesByPopularity->sortByPopularity();
	cout << *namesByPopularity;

	//make a copy of the original names file
	BabyNames * namesByNames = new BabyNames(*names);
	cout << "3. Sorted by name: " << endl;
	//Sort the babyNames by Name
	namesByNames->sortByName();
	cout << *namesByNames;

	//make a copy of the original names file
	BabyNames* namesByYear = new BabyNames(*names);
	cout << "4. Sorted by Year: " << endl;
	//Sort the babyNames by year
	namesByYear->sortByYear();
	cout << *namesByYear;

	cout << "5. Original names: " << endl;
	cout << *names;

	delete names;
	delete namesByYear;
	delete namesByNames;
	delete namesByPopularity;
	cout << "... done!" << endl;

}
