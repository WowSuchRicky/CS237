/*
 * HashTableEntry.h
 *
 *  Created on: Apr 13, 2013
 *      Author: Ricky Mutschlechner
 */

#ifndef HASHTABLEENTRY_H_
#define HASHTABLEENTRY_H_

namespace lab9 {

class HashTableEntry {
public:
	HashTableEntry(int k, double v);
	virtual ~HashTableEntry();
	int getKey(){ return key; }
	double getValue(){ return value; }
private:
	int key;
	double value;
};

} /* namespace lab9 */
#endif /* HASHTABLEENTRY_H_ */