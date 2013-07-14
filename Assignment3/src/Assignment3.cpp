/*
 * Assignment3.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: Anthony Varghese
 */

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;
#include "LinkedList.h"
#include "BabyNames.h"
using assignment3::BabyNames;

using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ios;

int main(void){
	const char filename[] = "src/names.txt";
	BabyNames* names = new BabyNames( );

	cout << "  1. Reading file: \"" << filename << "\" ... ";
	// read the contents of a file into names and print them
	ifstream file( filename, ios::in );
    file >> *names;
    cout << *names;
	cout << " file has been read!" << endl;

	// Sort and print
	cout << "  2. Sorted by popularity:" << endl;
	BabyNames* namesByPop = new BabyNames( *names );
//	namesByPop->sortByPopularity();
	cout << *namesByPop;

	// Sort and print
	cout << "  3. Sorted by name:" << endl;
	BabyNames* namesByName = new BabyNames( *names );
//	namesByName->sortByName();
	cout << *namesByName;

	// Sort and print
	cout << "  4. Sorted by year:" << endl;
	BabyNames* namesByYear = new BabyNames( *names );
//	namesByYear->sortByYear();
	cout << *namesByYear;

	cout << "  5. Original names:" << endl;
	cout << *names;

	delete names;
	delete namesByYear;
	delete namesByName;
	delete namesByPop;
	cout << "... all done!" << endl;
}
