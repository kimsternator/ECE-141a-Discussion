#include <iostream>
#include <thread>
#include <mutex>

// Function Pointer
void function(size_t threadId, int N) {
	for (size_t i = 0; i < N; i++) {
		std::cout << "Thread: " << threadId << " : " << i << std::endl;
	}
}

// Functor
class Thread_Functor {
public:
	void operator()(size_t threadId, int N) {
		for (size_t i = 0; i < N; i++) {
			std::cout << "Thread: " << threadId << " : " << i << std::endl;
		}
	}
};

//int main() {
//	std::thread thread0(function, 0, 5);
//	std::thread thread1(Thread_Functor(), 1, 5);
//	std::thread thread2([](size_t threadId, int N) {
//		for (size_t i = 0; i < N; i++) {
//			std::cout << "Thread: " << threadId << " : " << i << std::endl;
//		}
//	}, 2, 5);
//
//	thread0.join();
//	thread1.join();
//	thread2.join();
//
//	return 0;
//}

void changeA(int aNum, int& A) {
	A = aNum;
}

//int main() {
//	int a = 0;
//	std::cout << a << std::endl;
//	std::thread thread1(changeA, 10, std::ref(a));
//    if (thread1.joinable()) {
//        thread1.join();
//    }
//    std::cout << a << std::endl;
//    std::thread thread2(changeA, 5, std::ref(a));
//	std::cout << a << std::endl;
//
//	std::cout << a << std::endl;
//	if (thread2.joinable()) {
//		thread2.join();
//	}
//	std::cout << a << std::endl;
//
//	return 0;
//}

std::mutex mtx;

void printSomething(char aChar) {
	mtx.lock();
	for (size_t i = 0; i < 10; i++) {
		std::cout << aChar << i << "\n";
	}
	std::cout << std::endl;
	mtx.unlock();
}

/*
 * Main Thread (UI Thread)
 * Database Thread
 * Controller Thread
 *  Populate a website with a list
 *
 *  UI -> Asynchronous Layer (ExecutorService) -> Storage Layer -> Physical Memory
 */

int main() {
	std::thread thread0(printSomething, '#');
	std::thread thread1(printSomething, '@');

	if (thread0.joinable()) {
		thread0.join();
	}
	if (thread1.joinable()) {
		thread1.join();
	}

	return 0;
}

/* Agenda:
 * PA Questions x
 * Final Questions x
 *  Written Section + Coding Section
 *  Checkers PA (Not a topic)
 *  Based on one of the PAs (mixture of a couple topics from PAS0
 *      Command Parsing
 *      MVC
 *      Tokenization
 *      File Structure (generates models Query)
 *      Binary Files (compression, BlockIO, ...)
 *      Caching (LRU)
 *  Midterm Interview (rubric)
 *      coding conventions (function naming, convention (aArg, theArg), use of design {separation of logic,
 *          use of prebuilt functions STL})
 *
 * Multithreading/Asynchronous Programming
 */