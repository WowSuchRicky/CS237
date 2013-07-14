/*
* MyThread.h
*/
#ifndef MYTHREAD_H_
#define MYTHREAD_H_
namespace lab9 {
	class MyThread {
	public:
		MyThread();
		virtual ~MyThread();
		void run();

		int getData(){ return data; }
	private:
		int data;
		static const int DATA_START=-10;
		static const int DATA_END = 10;
	};
} /* namespace lab9 */
#endif /* MYTHREAD_H_ */