/*
 * Qlistener.cpp
 *
 *  Created on: Apr 19, 2013
 *      Author: Riccardo Mutschlechner, Tony Varghese
 */

#include "Queue.h"
using SavitchQueue::Queue;

#include <atomic>
#include <future>
using std::atomic;
using std::promise;
#include "Qlistener.h"

#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

namespace lab9 {

atomic<int> Qlistener::num_listeners( 0 );

Qlistener::Qlistener(int n): myNumber(n), myQueue(NULL) {
	num_listeners++;
}

Qlistener::Qlistener(int n, Queue<int>* q): myNumber(n), myQueue(q) {
	num_listeners++;
}

Qlistener::~Qlistener() {
   cout << "     Qlistener destructor" <<endl;
   num_listeners--;
}

void Qlistener::run(){
	cout << "     Queue listener " << myNumber << " of " << num_listeners << endl;

	long localSum = 0;
	while( ! myQueue->isEmpty() )
		localSum = localSum + myQueue->remove();
	mySum.set_value( localSum );

	cout << "     " << myNumber << " done." << endl;
}

long Qlistener::total(){
	return mySum.get_future().get();
}
} /* namespace lab9 */