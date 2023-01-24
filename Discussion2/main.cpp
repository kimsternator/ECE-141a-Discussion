#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <string>

using std::cout, std::endl,
	std::ostream, std::vector;

class Value { // class vs instance
public:
    // Class methods vs methods
    // OCF (Orthodox Canonical Form)
	Value() {} // Constructor (default, parametrized)
	Value(int aNum): num(aNum) {}
	~Value() {
    }
	Value(const Value& aValue) {
		*this = aValue;
	}

	Value& operator=(const Value& aValue) {
		num = aValue.num;
		return *this;
	}

	int getNum() const {
		return num;
	}

	void setNum(int aNum) {
		this->num = aNum;
	}

	void printNum(ostream& anOutput) {
		anOutput << num;
	}

	int operator()(ostream& anOutput, int aNum) {
		setNum(aNum);
		printNum(anOutput);
		return getNum();
	}

private:
    // data members
	int num;
};

struct One {
    void operator=(const One& aCopy) {
    }
};

struct Two {
    ~Two() {
        delete onePtr;
    }
    Two(const Two& aCopy) {
        onePtr = aCopy.onePtr;
    }
    One* onePtr;
};

class AccessExample {
public:
    // Virtual - can be overriden
    // Pure virtual - must be overriden
    virtual void function() {
        cout << "base" << endl;

    }

    void BaseFunction() {}

    int numPublic;
protected: // Only accessible to current class AND it's children (inheritance)
    int numProtected;
private: // Only accessible to current class
    int numPrivate;
};

class Derived: public AccessExample {
public:
    void function() override {
        cout << "derived" << endl;
    }
};

void AccessFunction() {
    AccessExample one;
}

// function
void function() {

}

// not going to implement parameterized constructor
struct Example {
    int operator()() {
        return num2 + num1;
    }

    int num2;
    int num1;
};

int main() {
	cout << "Hello, World!" << endl;
    {
        //another scope
        int aNum = 2;
        aNum++;
        int aNUM = aNum;
        int* numPtr = new int(34); // numPtr -> 0x1
    }
    function();

    // How to call default constructor
    Value ref;
    Value* refPtr = new Value();

    Value one{1};
    Value two{2};

    Value three(one); // call copy constructor
    Value four = one; // calls assignment operator

    Example obj1{1, 2};
    // Callable operator (FUNCTOR)
    int result = obj1();

    // Polymorphism
    vector<int> vec = {1, 2, (int) 3.14};
    vector<AccessExample*> list = {new AccessExample(),
                                   new AccessExample(),
                                   new Derived()};
    // Runtime polymorphism
    for (auto item : list) {
        item->function();
    }
    // Casting
    /*
     * static_cast<> - safer cast (gives compile errors)
     * c-style {int -> double ((double) 3.2) -> 3
     * const_cast<> - remove constness from a variable
     */

    // function pointer
    std::function<bool(int par1, int par2)> possibleFun;
    // Associative Dispatch (map -> keys, function)
    // ADMap["key"]()
    // Callback FUnction - listeners
    /*
     * void callback(std::function<bool(int par1, int par2)> callbackResponse);
     */
    std::stringstream theStream("Some sample text. Another sentence!");
    // g (get) point`   er, p (put) pointer
    std::string temp;
    while (theStream >> temp) {
        cout << temp << "\n";
    }
    cout << theStream.str() << endl;
	return 0;
}

/* Agenda:
 * Pointers & Memory x
 * Object Lifestyle x
 * Classes (OCF, Access Specifiers, This pointer, Inheritance) x
 * Slight discussion on Polymorphism x
 * Function Pointers & Functors x
 * String Streams x
 * is-a & has-a relationships x
 * Warnings x
 * templates & STL
 */

/*
 * int - number -2,000,000 - 2,000,000
 * pointer indicdated by * (int* name = ...) => 0xFFF24 {HEAP}
 * pointer created with keyword new
 * int* numPtr = new int(...);
 * delete numPtr
 * Smart Pointer: (unique_ptr, shared_ptr, weak_ptr)
 *
 * Beginning - instance of an object is created
 * Middle - every else
 * End - object is deleted
 */

template <typename T>
class SmartPointer {
public:
    ~SmartPointer() {
        delete value;
    }
    T* value;
};


// Some sample text. Another sentence!