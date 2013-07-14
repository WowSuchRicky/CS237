/*
 * Lab9D.cpp - has the main function to try out a Hash table
 *
 *  Created on: Mar 7, 2013
 *      Author: Ricky Mutschlechner
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#include "ListTools.h"
#include "HashTable.h"

using SavitchHashTable::HashTable;

int main(){
	cout << "CSIS 237 Lab 9 D - Hash Tables" << endl;

	HashTable h;

	cout << "Adding dog, cat, turtle, bird" << endl;
	/* h.put("dog");
	h.put("cat");
	h.put("turtle");
	h.put("bird");

	cout << "Contains dog? " << h.containsString("dog") << endl;
	cout << "Contains cat? " << h.containsString("cat") << endl;
	cout << "Contains turtle? " << h.containsString("turtle") << endl;
	cout << "Contains bird? "   << h.containsString("bird")   << endl;

	cout << "Contains fish? " << h.containsString("fish") << endl;
	cout << "Contains cow? "  << h.containsString("cow")  << endl;
	*/


	//h.put("dog",    23);
	//h.put("cat",    52);
	//h.put("turtle", 234);
	//h.put("bird"  , 162);
	h.put(23, "dog");
	h.put(52, "cat");
	h.put(234, "turtle");
	h.put(162, "bird");

	cout << "dog     corresponds to the value " << h.get("dog") << endl;
	cout << "cat     corresponds to the value " << h.get("cat") << endl;
	cout << "turtle  corresponds to the value " << h.get("turtle") << endl;
	cout << "bird    corresponds to the value " << h.get("bird")   << endl;

	cout << "Contains fish? " << h.containsString("fish") << endl;
	cout << "Contains cow? "  << h.containsString("cow")  << endl;


	_sleep(10000);
}