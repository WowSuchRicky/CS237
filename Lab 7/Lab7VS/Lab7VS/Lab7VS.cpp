// Lab7VS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class LinkedList{
	private:
		struct Node{
			int data;
			Node* next;

			~Node(){ delete next; }
		};

	public:
		LinkedList() { first = NULL; }
		~LinkedList(){ delete first; }
	void print(){ 
		Node* temp = first;
		while( temp != NULL ){
		cout << temp->data << " ";
		temp = temp->next;
		}
	}
		void insert(const int d){
			cout << "Inserting " << d << " into the LinkedList " << endl;
		Node* temp = new Node;
		temp->data = d;
		temp->next = first;
		first = temp;
	 }

		void swap(){
			Node* temp = first;
			Node* last = first;
			Node* secondLast = first;
			Node* second = first->next;
			

			//cout << "Temp is " << temp->data << endl;
			//cout << "Last is  " << last->data << " for now, but will be the last element after hopefully." << endl;
			//cout << "secondLast is " << secondLast -> data << endl;
			//cout << "second is " << second->data << endl;

			//_sleep(1000);





			//Obtaining the last Node
			while(last->next != NULL){
				last = last -> next;
			}

			//cout << "Last has been assigned: " << last->data << endl;
			//_sleep(1000);


			//Obtaining the 2nd to last Node
			while(secondLast->next->next != NULL){
				secondLast = secondLast -> next;
			}

			//cout << "secondLast has been assigned: " << secondLast->data << endl;
			//_sleep(1000);



			//Swapping the First and Last node
			first = last;
			last = temp;


			//Setting the pointers of the nodes to the correct places to "re-connect" the list
			first->next = second;
			secondLast -> next = last;
			last->next = NULL;

			
		}

private:
	Node* first;
};

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int a[] = { 1, 2, 3, 7, 6, 5, 4};
	LinkedList list;
	for(int i=0; i<7; i++){
		list.insert( a[i] );
	}

	cout << "Original List: " << endl;
	list.print();

	cout << "\n\nSwapping 1st and Last Nodes... " << endl;
	list.swap();
	list.print();

	_sleep(5000);
	return 0;
}

