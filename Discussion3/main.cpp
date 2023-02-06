#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <map>

using std::cout, std::endl, std::ostream,
	std::vector, std::function, std::string, std::map;

using CallableFun = bool (*)(int, bool);
using IntVector = vector<int>;

struct Tag1{};
struct Tag2{};

struct PtrObject {
    PtrObject(int aNum) : value(aNum) {}

    PtrObject(const PtrObject& aCopy) {
        value = aCopy.value;
    }

	int value;
};

struct Coordinate {
	int x;
	int y;

	friend ostream& operator<<(ostream& anOutput, const Coordinate& aCoordinate) {
		anOutput << "(" << aCoordinate.x << ", " << aCoordinate.y << ")";
		return anOutput;
	}
};

struct Functor {
	void operator()(Tag1) {
		cout << "Tag1" << endl;
	}

	void operator()(Tag2) {
		cout << "Tag1" << endl;
	}
};

bool fun(int aNum, bool aBool) {
	cout << "Within Fun " << aNum << " " << aBool << endl;
	return true;
}

void callCallable(CallableFun& theFun) {
	theFun(1, true);
}

template<typename T>
void printVector(vector<T> aVec, string aSep=" ", string anEnd="\n") {
	for (auto& element: aVec) {
		cout << element << aSep;
	}
	cout << anEnd;
}

bool compare(const int& aLeft, const int& aRight) {
    return aLeft > aRight;
}

int main() {
//	PtrObject* ptr = new PtrObject{2};
//	cout << ptr << endl;
//	delete ptr;

//	// Function Pointers
//	bool (*fPtr)(int, bool) = &fun;
//	CallableFun funPtr = &fun;
//	// Function Reference
//	function<bool(int, bool)> theFunction = fun;
//
//	// Listeners (event listeners) MouseListener KeyboardListener
//
//	callCallable(funPtr);

	// &, =
	// [] - capture clause (pass-by-reference, pass-by-value)
//	auto lambda = [](const int& aLeft, const int& aRight) {};
//	IntVector numVector = {2, 4, 1, 12, 12, 34, 1, 2};
//	printVector(numVector);
//	int aThreshold = 4;
//
//	std::sort(numVector.begin(), numVector.end(), [](const int& aLeft, const int& aRight) {
//	    return aLeft < aRight;
//    });
//	printVector(numVector);
	// O(nlog(N)) - worst scenario
	// Container is size n

//	vector<Coordinate> coordinates = {Coordinate{1, 1}, Coordinate{5, 2}, Coordinate{2, 0}};
//	printVector(coordinates);
//	std::sort(coordinates.begin(), coordinates.end(), [](const Coordinate& aLeft, const Coordinate& aRight) {
//	    if (aLeft.x > aRight.x) {
//	        return aLeft.x < aRight.x;
//	    }
//	    return aLeft.y < aRight.y;
//    });
//    printVector(coordinates);

    return 0;
}

/*
 * pointers
 * callables
 * closures vs functor
 * STL basic containers/iterations/calling a function
 * STL algorithms
 *
 * Creational
 * singleton, factory, prototype
 */

class Singleton {
public:
	static Singleton* getInstance() {
		if (_instance == nullptr) {
			_instance = new Singleton();
		}
		return _instance;
	}
private:
	Singleton() {}
	~Singleton() {
		delete _instance;
	}

	static Singleton* _instance;
};
Singleton* Singleton::_instance = nullptr;

//enum ObjectType {
//	One, Two
//};
//class ReturnObject {
//public:
//	virtual void print()=0;
//};
//class ReturnObject1 : public ReturnObject {
//public:
//	void print() override {
//		cout << "Object 1" << endl;
//	}
//};
//class ReturnObject2 : public ReturnObject {
//public:
//	void print() override {
//		cout << "Object 2" << endl;
//	}
//};
//class Factory {
//public:
//	ReturnObject* create(ObjectType aType) {
//		if (aType == ObjectType::One) {
//			return new ReturnObject1();
//		} else if (aType == ObjectType::Two) {
//			return new ReturnObject2();
//		}
//		return nullptr;
//	};
//};

enum ObjectType {
	Type1, Type2
};
class Object {
public:
	virtual void print()=0;
	virtual Object* prototype()=0;
};
class Object1 : public Object {
	void print() {
		cout << "Object 1" << endl;
	}
	Object* prototype() override {
		return new Object1(*this);
	}
};
class Object2 : public Object {
	void print() {
		cout << "Object 2" << endl;
	}
	Object* prototype() override {
		return new Object2(*this);
	}
};

class Prototype {
public:
	Object* getObject(ObjectType aType) {
		return prototypes[aType]->prototype();
	}
private:
	map<ObjectType, Object*> prototypes = {
			{ObjectType::Type1, new Object1()},
			{ObjectType::Type2, new Object2()}
	};
};