/*
 * HashTable.h
 *  This is the interface for the class HashTable,
 *  which is a class for a hash table of strings.
 *  Created on: Mar 27, 2013
 *      Author: Savitch, modified by Ricky Mutschlechner
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

using SavitchListTools::Node;
using std::string;

namespace SavitchHashTable {

const int SIZE = 10;

class HashTable {
public:
   HashTable(); // Initialize empty hash table
      // Normally a copy constructor and overloaded assignment
      // operator would be included.  They have been omitted
      // to save space.
   virtual ~HashTable();  // Destructor destroys hash table

   bool containsString(string target) const;
      // Returns true if target is in the hash table,
      // false otherwise

   void put(int k, string s);
      // Adds a new string to the hash table at the specified key

   string get(string value);
	//lets you return a value from a certain key

 private:
      Node<string> *hashArray[SIZE];
      static int computeHash(string s);   // Compute hash value for string
}; // HashTable

} /* namespace SavitchHashTable */
#endif /* HASHTABLE_H_ */