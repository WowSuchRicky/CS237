/*
 * LinkedList.h
 *
 *  Created on: Apr 6, 2013
 *      Author: Anthony Varghese, Ricky Mutschlechner
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

namespace assignment3 {

class LinkedList {
public:
	struct Node{
	public:
			enum gender { boy, girl };
			Node();
			Node(short y, string n, double p, gender g);
			Node(short y, string name, double per, gender g,Node* n, Node* p);
			virtual ~Node();
			void setNext(Node* n){next=n;}
			void setPrev(Node* p){prev = p;}
			Node* getNext(){ return next;}
			Node* getPrev(){ return prev;}
			short getYear(){return year;}
			string getName(){return name;}
			double getPercent(){return percent;}
			gender getGender(){return sex;}
			void setYear(short y){year=y;}
			void setName(string n){name=n;}
			void setPercent(double d){percent=d;}
			void setGender(string g){ if(g.compare("girl")) sex = girl; else sex=boy;}

	private:
		Node*  next;
		Node*  prev;
		short  year;
		string name;
		double percent;
		gender sex;
		friend ostream& operator<<(ostream& os, const Node& n);
		friend istream& operator>>(istream& is, Node& n);
		friend istream& operator>>(istream& is, LinkedList& bn);
		friend ostream& operator<<(ostream& os, const LinkedList& bn);
	};

public:
	LinkedList();
	LinkedList(const LinkedList& source);
	virtual ~LinkedList();
	LinkedList& operator =(const LinkedList& rhs);
	void sortByName();
	void sortByPopularity();
	void sortByYear();
	void insert(short y, string n, double p, Node::gender g);
	void print();
private:
	Node* first;
	friend ostream& operator<<(ostream& os, const Node& n);
	friend istream& operator>>(istream& is, Node& n);
	friend istream& operator>>(istream& is, LinkedList& bn);
	friend ostream& operator<<(ostream& os, const LinkedList& bn);
};
istream& operator>>(istream& is, LinkedList& bn);
ostream& operator<<(ostream& os, const LinkedList& bn);

} /* namespace assignment3 */
#endif /* LINKEDLIST_H_ */
