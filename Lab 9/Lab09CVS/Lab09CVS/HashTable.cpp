/*
 * HashTable.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: Ricky Mutschlechner
 */

#include <cstddef>
#include "HashTableEntry.h"
#include "HashTable.h"

namespace lab9 {

HashTable::HashTable(int n): size(n) {
	if (n < 0)
		return;
	entryTable = new HashTableEntry*[ size ];
	for (int i=0; i<size; i++)
		entryTable[i] = NULL;
}

HashTable::~HashTable() {
	for (int i=0; i<size; i++)
		delete entryTable[i];
	delete[] entryTable;
}

int HashTable::hashf( int key ){
    int hash = (key % size);
    while ( entryTable[hash] != NULL && entryTable[hash]->getKey() != key)
          hash = (hash+1) % size;

    return hash;
}

double HashTable::get( int key){
    int hash = hashf( key );

    if ( entryTable[hash] == NULL )
          return -1;
    else
          return entryTable[hash]->getValue();
}

void HashTable::add( int key, double v ){
    int hash = hashf( key );

    if ( entryTable[hash] != NULL ) // key is already in use: do not add a new value.
          return;
    else
          entryTable[hash] = new HashTableEntry( key, v );

}

}