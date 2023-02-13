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

// SRP Single Responsibility Principle
// Model (Data - in memory representation of a database), View (View application window etc), Controller (dispatch commands etc)

class Model {
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
    std::vector<int> getData() {
        return list;
    }
    void reverseData() {

    }
private:
    std::vector<int> list;
};

// Controller always singleton
class Controller { // API - interface for users
public:
    void addItem(int aNum) {
        model.addItem(aNum);
    }
    void removeItem(size_t anIndex) {
        model.removeItem(anIndex);
    }
    std::vector<int> getData() {
        return model.getData();
    }
    void reverseData() {
        model.reverseData();
    }
private:
    Model model;
};

class View {
public:
    void displayList() {
        modelData = controller.getData();
        std::cout << "------------------------\n";
        for (const auto& element : modelData) {
            std::cout << element << " ";
        }
        std::cout << "------------------------\n";
    }
private:
    Controller controller;
    std::vector<int> modelData;
};

class SmartPointer {
public:
    SmartPointer(Object* aObject) : theObject(aObject) {}
    ~SmartPointer() {
        delete theObject;
    }
    Object* theObject;
};

class DataDecoder {
public:
    DataDecoder(std::string aCode) {
        data = aCode.substr(aCode.find(':') + 1);
    }
    std::string data;
};

int main() {
//    SmartPointer theSmartPtr{new Object()};
    /*Smart Ptrs
     *  unique_ptr -only 1 variable can point to this pointer
     *  shared_ptr - as many can
     *  weak_ptr - cppreference
     */

//    Object* thePtr = new Object();
//    Object* anotherPtr = thePtr;
//
//    std::cout << thePtr << " " << anotherPtr;

//	std::string theData = "Secret Message";
//	CodedData theCode(theData);
//	sendOverInternet(theData);
//	std::string theReceivedData = receiveOverInternet(theData);
//	DataDecoder theDecoder(theReceivedData);
//	theReceivedData = theDecoder.data;
//
//	std::cout << (theData == theReceivedData ? "Correctly Sent/Received" : "Error: cannot receive message!");

//	std::map<int, CallableFun> theDispatch = {
//			{1, callableOne},
//			{2, callableTwo}
//	};
//
//    int arg = 2;
//    if (theDispatch.find(arg) == theDispatch.end()) {
//        return 0;
//    }
//	theDispatch[arg]();
	// Hash-map
	// 010010011 => 0x0FF2A
	// O(1) - constant
	// Memory - O(n)

	List theList;
    theList.addItem(1);
    theList.addItem(2);
    theList.addItem(3);
    theList.addItem(4);
    theList.addItem(5);
    theList.addItem(6);
    theList.addItem(7);
    theList.displayList();

	return 0;
}

/* Agenda
 * Smart Pointers
 * Adapter Pattern
 * Dispatch
 * Model View Controller
 * Design Exercise (Assignment 3)
 */


/* Design Exercise 1
 * Object that can be a list, value, or Object
 * 		List can also hold Objects, lists, or values
 */
class JSONModel {
public:
    virtual void print()=0;
};

class JSONList : public JSONModel {
public:
};

class JSONValue : public JSONModel {

};

class JSONObject : public JSONModel {

};

class ModelCollection {
public:
    void method() {
        model->print();
    }
private:
    JSONModel* model;
};

// Why does this have to be a pointer instead of a reference besides memory concerns?


// MVP - model view presenter
// Controller - View => Controller = Presenter + Contract (interface)

