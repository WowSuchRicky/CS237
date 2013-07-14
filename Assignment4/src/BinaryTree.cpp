/*
 * Title: BinaryTree.cpp
 * Description: This cpp file contains the method bodies for the BinaryTree class.  The BinaryTree class contains a copy constructor and an
 * 				overloaded = and << operators.  The BinaryTree can be sorted using the inorder, preorder, and postorder methods.  There are
 * 				also methods to add to the tree and add_inorder to the tree.  The tree memory is dealocated using a postorder method.
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

namespace assignment4 {
/*
 * Default Constructor for BinaryTree
 */
BinaryTree::BinaryTree() :
		root(NULL) {

}
/*
 * copy constructor for Binary Tree
 * Parameter: const BinaryTree& tree
 */
BinaryTree::BinaryTree(const BinaryTree& tree) {
	if (tree.root == NULL) {
		this->root = NULL;
	} else {
		this->root = NULL;
		copyBinaryTree(tree.root);
	}
}
/*
 * BinaryTree Destructor
 * Deallocate the memory for the BinaryTree using a postorder delete to
 * delete the tree from the leaves up to the root.
 */
BinaryTree::~BinaryTree() {
	delete_postorder(root);
	root = NULL;
}
/*
 * Add integer data to the tree in order.
 * Parameters: int d
 * Return: void
 */
void BinaryTree::add(int d) {
	if (root == NULL)
		root = new Node(d);
	else
		add_inorder(root, d);
}
/*
 * Adds to the BinaryTree in order.
 * This method is called recursively.
 * Parameters: Node* t, ind d
 * Return: Void
 */
void BinaryTree::add_inorder(Node* t, int d) {
	if (d <= t->data)
		if (t->left == NULL)
			t->left = new Node(d);
		else
			add_inorder(t->left, d);
	else if (t->right == NULL)
		t->right = new Node(d);
	else
		add_inorder(t->right, d);
}

/*
 * Prints the tree in order
 * uses recursion
 * Parameters: std::ostream& o, Node*t
 * Return: Void
 */
void BinaryTree::print_inorder(std::ostream& o, Node*t) {
	if (t == NULL)
		return;
	print_inorder(o, t->left);
	o << t->data << " ";
	print_inorder(o, t->right);
}
/*
 * Prints the tree in the pre-order
 * uses recursion
 * Parameters: std::ostream& o, Node*t
 * Return: Void
 */
void BinaryTree::print_preorder(std::ostream& o, Node*t) {
	if (t == NULL)
		return;
	o << t->data << " ";
	print_preorder(o, t->left);
	print_preorder(o, t->right);
}
/*
 * Prints the tree in the post-order
 * uses recursion
 * Parameters: std::ostream& o, Node*t
 * Return: Void
 */
void BinaryTree::print_postorder(std::ostream& o, Node*t) {
	if (t == NULL)
		return;
	print_postorder(o, t->left);
	print_postorder(o, t->right);
	o << t->data << " ";
}
/*
 * Deallocates the tree using a post-order delete method
 * this will delete the tree from the leaves to the root
 * so that no dangling pointers result or memory leaks.
 * Parameter: Node* t
 * Return: void
 */
void BinaryTree::delete_postorder(Node* t) {
	if (t == NULL)
		return;
	delete_postorder(t->left);
	t->left = NULL;
	delete_postorder(t->right);
	t->right = NULL;
	delete t;
	t = NULL;
}

std::ostream& operator <<(std::ostream& o, BinaryTree& t) {
	o << "Inorder traversal:   ";
	t.print_inorder(o, t.root);

	o << std::endl << "Preorder traversal:  ";
	t.print_preorder(o, t.root);

	o << std::endl << "Postorder traversal: ";
	t.print_postorder(o, t.root);
	o << std::endl;
	return o;
}

void BinaryTree::copyBinaryTree(Node* treeCopy) {
	{
		if (treeCopy) {
			add(treeCopy->data);
			copyBinaryTree(treeCopy->left);
			copyBinaryTree(treeCopy->right);
		}
	}
}

BinaryTree& BinaryTree::operator=(const BinaryTree& T) {
	if (this != &T) {
		delete_postorder(root);
		root = NULL;
		copyBinaryTree(T.root);
	}
	return *this;
}

} /* namespace assignment4 */
