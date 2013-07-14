/*
 * Queue.cpp - implementation of the template class Queue.
 *             The interface for the template class Queue is in the header file Queue.h.
 *
 *
 *  Created on: Mar 27, 2013
 *      Author: Savitch
 */
#include <iostream>
#include <cstdlib>
#include <cstddef>

#include "Queue.h"

using std::cout;

namespace SavitchQueue {

template<class T>
Queue<T>::Queue( ) : front(NULL), back(NULL) {
    //Intentionally empty.
}

template<class T>
bool Queue<T>::isEmpty( ) const {
	bool e = (back == NULL);//front == NULL would also work
    return e;
}

template<class T>
void Queue<T>::add(T item) {
    if (isEmpty( ))
       front = back = new Node<T>(item, NULL);//sets both
                  //front and back to point to the only node
   else {
       back->setLink(new Node<T>(item, NULL));
       back = back->getLink( );
   }
}

template<class T>
T Queue<T>::remove( ) {
    if (isEmpty( )) {
        cout << "Error:Removing an item from an empty queue.\n";
        exit(1);
    }

	qlock.lock();

	T result = front->getData( );

    Node<T> *discard;
    discard = front;
    front = front->getLink( );
    if (front == NULL) //if you removed the last node
        back = NULL;

    delete discard;

	qlock.unlock();
    return result;
}

template<class T>
Queue<T>::~Queue( ) {
    while (! isEmpty( ))
       remove( );//remove calls delete.
}

template<class T>
Queue<T>::Queue(const Queue<T>& aQueue) {
    if (aQueue.isEmpty( ))
        front = back = NULL;
    else {
        Node<T> *temp = aQueue.front;//temp moves
        //through the nodes from front to back of aQueue.

        back = new Node<T>(temp->getData( ), NULL);
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.

        temp = temp->getLink( );//temp now points to second
                //node or NULL if there is no second node.

        while (temp != NULL) {
            back->setLink(new Node<T>(temp->getData( ), NULL));
            back = back->getLink( );
            temp = temp->getLink( );
        }
        //back->link == NULL
    }
}

template<class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& rightSide) {
    if (front == rightSide.front)//if the queues are the same
        return *this;
    else { //send left side back to freestore
        T next;
        while (! isEmpty( ))
            next = remove( );//remove calls delete.
    }

    if (rightSide.isEmpty( )) {
        front = back = NULL;
        return *this;
    } else {
        Node<T> *temp = rightSide.front;//temp moves
                //through the nodes from front to back of rightSide.

        back = new Node<T>(temp->getData( ), NULL);
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.

        temp = temp->getLink( );//temp now points to second
                   //node or NULL if there is no second node.

        while (temp != NULL) {
            back->setLink( new Node<T>(temp->getData( ), NULL));
            back = back->getLink( );
            temp = temp->getLink( );
        }
        //back->link == NULL;

        return *this;
    }
}

} /* namespace SavitchQueue */