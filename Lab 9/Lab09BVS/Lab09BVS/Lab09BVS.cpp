/*
 * Lab9A.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: Riccardo Mutschlechner, Anthony Varghese
 *
 */

#include <iostream>
#include <vector>
#include <thread>

#include "Queue.cpp"
using SavitchQueue::Queue;

#include <atomic>
#include <future>
using std::atomic;
#include "Qlistener.h"
using lab9::Qlistener;

using std::cout;
using std::endl;
using std::vector;
using std::thread;

int main(){
	cout << "CSIS 237 Lab 9 B - Multithreaded queueing" << endl << endl;
	cout.sync_with_stdio( true );

	cout << "  Creating a queue: ... " << endl;
	Queue<int> q;
	const int START_COUNT = 0;
	const int END_COUNT   = 1000;
	for (int i=START_COUNT; i<=END_COUNT; i++)
		q.add( i );
	cout << "  ... done creating queue" << endl;


	cout << "  Creating threads for queue listeners" << endl;
	const int NUMBER_OF_LISTENERS = 2;
	vector<Qlistener*> listeners;
	vector<thread*> threads;

	/*
	 * create threads that will execute the run methods at the same time.
	 * The various threads share the one queue and so there may
	 *   be problems removing things from the queue.
	 */
	for (int i=0; i<NUMBER_OF_LISTENERS; i++ ){
		Qlistener* qListen = new Qlistener( i+1, &q );
		if (qListen != NULL)
			listeners.push_back( qListen );

		thread* t = new thread(&Qlistener::run, qListen );
		if ( t != NULL )
			threads.push_back( t );
	}
	cout << "  Number of threads: " << threads.size() << endl << endl;

	long grand_total = 0;
	for (Qlistener* ql : listeners )
		if (ql != NULL )
			grand_total += ql->total();
	cout << "Final result is: " << grand_total << endl;


	/*
	 *  wait for all the threads to finish
	 */
	for (thread* t : threads )
	   if (t != NULL){
		   t->join();
	   }
	cout << "Main done." << endl;

	_sleep(10000);
}


/*
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/

