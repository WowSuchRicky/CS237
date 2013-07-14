/*
 * Title: BinaryTree.cpp
 * Description: Creates a Tree using an array of integers.  The tree is copied and printed in preorder, postorder, and inorder.
 *  Created on: May 5th, 2013
 *      Author: Caitlin Finn
 *      Email: caitlin.finn@my.uwrf.edu
 *   Modified: May 6th, 2013
 *   Group Members: Erin McNeil, Ricky Mutschlechner
 *
 */

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include "BinaryTree.h"
using assignment4::BinaryTree;

void make_copies(BinaryTree* source);

int main() {
	cout << "Assignment #4" << endl;

	BinaryTree* startTree = new BinaryTree();

	const int ARRAY_SIZE = 10;
	int data[ARRAY_SIZE] = { 87, 1, -10, 11, 52, -3, 95, 2, 10, -42 };
	cout << "List: ";
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << " " << data[i];
	cout << endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
		startTree->add(data[i]);

	cout << "Starting tree:" << endl << *startTree << endl;

	make_copies(startTree);

	// Clean up
	delete startTree;
	cout << "Assignment #4 done!" << endl;
}

void make_copies(BinaryTree* source) {
	BinaryTree copy1;
	copy1 = *source;
	copy1.add(43);
	cout << "Copy 1:" << endl << copy1 << endl;

	BinaryTree copy2(*source);
	copy2 = copy1;
	copy2.add(-12);
	cout << "Copy 2:" << endl << copy2 << endl;
}
