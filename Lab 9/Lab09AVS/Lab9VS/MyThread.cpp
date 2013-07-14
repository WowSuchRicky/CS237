#include "MyThread.h"
namespace lab9 {
	MyThread::MyThread(): data( DATA_START ) { }
	MyThread::~MyThread() { }
	void MyThread::run(){
		if (data < DATA_START)
			data = DATA_START;
		data++;
		if (data > DATA_END )
			data = DATA_END;
	}
} /* namespace lab9 */