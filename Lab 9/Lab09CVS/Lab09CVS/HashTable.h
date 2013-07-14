/*
 * HashTable.h
 *
 *  Created on: Apr 13, 2013
 *      Author: Ricky Mutschlechner
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

namespace lab9 {

class HashTable {
public:
	HashTable(int n);
	virtual ~HashTable();
	double get( int key );
	void add( int key, double v );
	//static double constexpr invalid_result = -999.999;
private:
	int size;                    // size of the hash table
	HashTableEntry** entryTable; // array of pointers
	int hashf( int key );  // hash function
};

} /* namespace lab9 */
#endif /* HASHTABLE_H_ */