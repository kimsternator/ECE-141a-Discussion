#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>

using CallableFun = std::function<void()>;

void callableOne() {
	std::cout << "Called Function 1\n";
}

void callableTwo() {
	std::cout << "Called Function 2\n";
}

void callableDefault() {
	std::cout << "Called Default Function\n";
}

struct Object {};


class CodedData {
public:
	CodedData(std::string aCode) {
		data = "Code:" + aCode;
	}
	std::string data;
};

void sendOverInternet(CodedData aCode) {}

std::string receiveOverInternet(CodedData aCode) {
	return aCode.data;
}

int main() {


//	std::string theData = "Secret Message";
//	CodedData theCode(theData);
//	sendOverInternet(theData);
//	std::string theReceivedData = receiveOverInternet(theData);
//
//	std::cout << (theData == theReceivedData ? "Correctly Sent/Received" : "Error: cannot receive message!");

//	std::map<int, CallableFun> theDispatch = {
//			{1, callableOne},
//			{2, callableTwo}
//	};

	return 0;
}


/* Agenda
 * Smart Pointers
 * Adapter Pattern
 * Dispatch
 * Model View Controller
 */


/* Design Exercise 1
 * Object that can be a list, value, or Object
 * 		List can also hold Objects, lists, or values
 */

class DataDecoder {
public:
	DataDecoder(std::string aCode) {
		data = aCode.substr(aCode.find(':') + 1);
	}
	std::string data;
};

class List {
public:
	void addItem(int aNum) {
		list.push_back(aNum);
	}
	void removeItem(size_t anIndex) {
		if (anIndex >= list.size()) {
			return;
		}
		list.erase(list.begin() + anIndex);
	}
	void displayList() {
		std::cout << "------------------------\n";
		for (const auto& element : list) {
			std::cout << element << " ";
		}
		std::cout << "------------------------\n";
	}
private:
	std::vector<int> list;
};
