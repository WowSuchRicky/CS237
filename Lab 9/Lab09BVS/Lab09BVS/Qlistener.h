/*
 * Qlistener.h
 *
 *  Created on: Apr 19, 2013
 *      Author: Riccardo Mutschlechner, Tony Varghese
 */

#ifndef QLISTENER_H_
#define QLISTENER_H_

namespace lab9 {

class Qlistener {
public:
	Qlistener(int n);
	Qlistener(int n, Queue<int>* q);
	virtual ~Qlistener();
	void run();
	long total();
private:
	int myNumber; 			// Listener number
	Queue<int>* myQueue; 	// Queue containing input
	static atomic<int> num_listeners; // Total number of live listeners
	std::promise<long> mySum;	// My result
};

} /* namespace lab9 */
#endif /* QLISTENER_H_ */