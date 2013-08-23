// Lab9VS.cpp : Defines the entry point for the console application.
//

/*
 * Lab9A.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: Riccardo Mutschlechner, Tony Varghese
 *
 */

#include <iostream>
#include <thread>
#include "MyThread.h"
using lab9::MyThread;

using std::cout;
using std::endl;

using std::thread;

int x;

void threadfunction1(){
	cout << "    Thread start: x is " << x << endl;
	x ++;
	cout << "    Thread done:  x is " << x << endl;
}

int main(){
	cout << "CSIS 237 Lab 9 A - threads" << endl << endl;
	cout.sync_with_stdio( true );

	const int START = 10;
	const int END   = 20;

	x = START;

	/*
	 * create a thread  that will execute threadfunction
	 *  at the same time as the following statements of
	 *  the main function.
	 */
	thread t1( threadfunction1 );

	cout << "   Main start:   x is " << x << endl;
	for ( ; x < END; x ++ )
		cout << "   Main:         x is " << x << endl;

	/*
	 * wait for t1 to be done.
	 */
	t1.join();

	cout << "   Main t1 done: x is " << x << endl;


//* Creating threads using objects - similar to Java
	cout << "  Creating a thread using an object" << endl;
	MyThread to;
	cout << "  Thread object has: " << to.getData() << endl;
	thread t2( &MyThread::run, &to );
	t2.join(); // wait for t1 to be done.
	cout << "  Thread object has: " << to.getData() << endl;
 

	cout << "Main done." << endl;
	_sleep(5000);
}

/* int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
*/

