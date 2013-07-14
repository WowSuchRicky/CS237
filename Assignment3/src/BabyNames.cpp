/*
 * BabyNames.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: Anthony Varghese
 */

#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::ostream;
using std::istream;
const char filename[] = "src/names.txt";
#include "LinkedList.h"
#include "BabyNames.h"
using std::endl;
using namespace std;

namespace assignment3 {

BabyNames::BabyNames() {
	datasize = getFileSize();
}

BabyNames::BabyNames(const BabyNames& source) {
	datasize=source.datasize;
}
BabyNames::BabyNames(const int size) {
	datasize = size;
}
BabyNames& BabyNames::operator =(const BabyNames& rhs) {
	return *this;
}

BabyNames::~BabyNames() {

}

/*void BabyNames::sortByName() {
	data.sortByName();
}

void BabyNames::sortByPopularity() {
	data.sortByPopularity();
}

void BabyNames::sortByYear() {
	data.sortByYear();
}*/



//overloads the << operator to correctly print the contents of the Data struct

/* std::ostream& operator<<(std::ostream& os, const BabyNames::Data& d) {
	os << d.name << " " << d.year << " " << d.percent << " " << d.sex;
	return os;
}*/

ostream& operator<<(ostream& os, const BabyNames& bn) {
	os << "  BabyNames object " << std::endl;
	bn.data->print();
	os << std::endl;
	return os;
}

istream& operator>>(istream& is, BabyNames& bn) {
	//LinkedList::Node a[];
	string line;
	int arrayIndex = 0; //initialize the array index to 0 before reading the file
	bn.data = new LinkedList();
while(!is.eof()){
	getline(is,line); //get the first header line
	short year;
	string name;
	double percent;
	string sex;


	is >> year;
	is >> name;
	is >> percent;
	is >> sex;

	LinkedList::Node::gender gender;

	if(sex.compare("girl")){
		gender = LinkedList::Node::girl;
	}else
		gender = LinkedList::Node::boy;


			bn.data->insert(year,name,percent,gender);

}

	return is;
}

/*
 * getFileSize()
 * returns the size of the file.
 */
int getFileSize() {
	ifstream myfile(filename);
	string line;
	int fileSize = 0;
	while (getline(myfile, line)) {
		fileSize++;
	}

	return fileSize;
}

}
