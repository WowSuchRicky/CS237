/*
 * HashTable.cpp
 *
 *  Created on: Mar 27, 2013
 *      Author: Savitch, modified by Ricky Mutschlechner
 */

#include <string>
#include "ListTools.cpp"
#include "HashTable.h"

using SavitchListTools::Node;
using SavitchListTools::search;
using SavitchListTools::headInsert;

namespace SavitchHashTable {

HashTable::HashTable() {
 for (int i = 0; i < SIZE; i++)
  hashArray[i] = NULL;
}

HashTable::~HashTable() {
  for (int i=0; i<SIZE; i++) {
    Node<string> *next = hashArray[i];
    while (next != NULL) {
      Node<string> *discard = next;
	 next = next->getLink( );
	 delete discard;
    }
  }
}

int HashTable::computeHash(string s) {
 int hash = 0;
 for (unsigned int i = 0; i < s.length( ); i++)  {
  hash += s[i];
 }
 return hash % SIZE;
}

bool HashTable::containsString(string target) const {
 int hash = this->computeHash(target);
 Node<string>* result = search(hashArray[hash], target);
 if (result == NULL)
    return false;
 else
    return true;
}

int intHash(int key){
	int hash = (key % SIZE);
    return hash;
}

void HashTable::put(int k, string s) {
 int hash = computeHash(s);
 int key = intHash( k );
 if (search(hashArray[k], s)==NULL) {
   // Only add the target if it's not in the list
   headInsert(hashArray[k], s);
 }
}

string HashTable::get(string value){
	return search(hashArray[hash], value);
}


} /* namespace SavitchHashTable */