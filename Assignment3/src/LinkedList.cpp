/*
 * LinkedList.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: Anthony Varghese, Ricky Mutschlechner
 */

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

#include "LinkedList.h"

namespace assignment3 {
LinkedList::Node::Node(): year(0), name(NULL), percent(0), sex(boy), next(NULL), prev(NULL) {
}

LinkedList::Node::Node(short y, string n, double p, Node::gender s): year(y), name(n), percent(p), sex(s), next(NULL), prev(NULL) {
}

LinkedList::Node::Node(short y, string name, double percent, Node::gender s, Node* n, Node* p) : year(y), name(name), percent(percent), sex(s), next(n), prev(p){
}

LinkedList::Node::~Node() {
	delete next;
}
LinkedList::LinkedList() {
	first = NULL;
}

LinkedList::~LinkedList() {
	delete first;
}

LinkedList::LinkedList(const LinkedList& source){
	first = NULL;

}

LinkedList& LinkedList::operator =(const LinkedList& rhs){

	return *this;
}

void LinkedList::sortByName(){

}

void LinkedList::sortByPopularity(){

}

void LinkedList::sortByYear(){

}

void LinkedList::insert(short y, string n, double p, Node::gender g){
	LinkedList::Node* temp = first;
	first = new Node(y,n,p,g,first,NULL);
	if(temp==NULL)
		return;
	temp->setPrev(first);
}


void LinkedList::print(){
	Node* temp = first;
	while(temp != NULL){
		std::cout<<std::endl;
		std::cout << temp->getName() << " " << temp->getYear() << " "<< temp->getPercent() << " " << temp->getGender();
		temp=temp->getNext();
	}
	std::cout<<std::endl;
}

ostream& operator<<(ostream& os, const LinkedList::Node& d){
	os << d.name << " " << d.year << " " << d.percent << " ";
	if (d.sex == assignment3::LinkedList::Node::boy)
		os << "boy";
	else
		os << "girl";
	return os;
}

istream& operator>>(istream& is, LinkedList::Node& d){
	string s; 	getline( is, s);

	is >> d.year >> d.name >> d.percent;

	string sex;  is >> sex;
	if (sex.compare("boy") == 0)
		d.sex = assignment3::LinkedList::Node::boy;
	else
		d.sex = assignment3::LinkedList::Node::girl;
	return is;
}


istream& operator>>(istream& is, LinkedList& bn){

	return is;
}
ostream& operator<<(ostream& os, const LinkedList& bn){

	return os;
}
} /* namespace assignment3 */
