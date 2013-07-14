/*
 * Title: BinaryTree.h
 * Description: This header file contains headers for the BinaryTree class and the Node class it contains.  Node contains data members: data,
 * 				left, and right.  The BinaryTree class contains the private Node class for good encapsulation and has data member root of type Node.
 * 				The = and << operators are overloaded for the BinaryTree class.
 *  Created on: May 5th, 2013
 *      Author: Caitlin Finn
 *      Email: caitlin.finn@my.uwrf.edu
 *   Modified: May 6th, 2013
 *   Group Members: Erin McNeil, Ricky Mutschlechner
 *
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <cstddef>

namespace assignment4 {

class BinaryTree {
private:
	class Node {
	public:
		Node(int d) :
				data(d), left(NULL), right(NULL) {
		}
		~Node() {
			delete left;
			left = NULL;
			delete right;
			right = NULL;
		}
		int data;
		Node* left;
		Node* right;
	};
public:
	BinaryTree();
	virtual ~BinaryTree();
	//copy constructor
	BinaryTree(const BinaryTree& tree);
	void add(int d);
	friend std::ostream& operator <<(std::ostream& o, BinaryTree& t);
	BinaryTree& operator=(const BinaryTree& T);

private:
	Node* root;
	void add_inorder(Node* t, int d);
	void print_inorder(std::ostream& o, Node*t);
	void print_preorder(std::ostream& o, Node*t);
	void print_postorder(std::ostream& o, Node*t);
	void delete_postorder(Node* t);
	void copyBinaryTree(Node* treeCopy);

};

} /* namespace assignment4 */
#endif /* BINARYTREE_H_ */
