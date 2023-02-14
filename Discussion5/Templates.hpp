//
// Created by steph on 2/13/2023.
//

#ifndef DISCUSSION5_TEMPLATES_HPP
#define DISCUSSION5_TEMPLATES_HPP

#include <iostream>
#include <string>

using std::string, std::cout;

template<typename T1, typename T2>
static bool lessThan(T1 aLeft, T2 aRight) {
	return aLeft < aRight;
}

struct Number {
    float num;

//    bool operator<(const float& aFloat) {
//        return this->num < aFloat;
//    }
};

// HINT :partial template specialization mocks if conditions for types
template<>
static bool lessThan(Number aLeft, Number aRight) {
    return aLeft.num < aRight.num;
}

struct Coordinate {
	int x;
	int y;
};

struct KeyValue {
	string key;
	int value;
};

void printResult(bool aResult) {
	cout << (aResult ? "True" : "False") << "\n";
}

void runTemplateExample() {
	printResult(lessThan(Number{1.0f}, Number{2.0f}));
}

//template <typename T>
//class SomeClass {
//public:
//    bool fun(T aT) {
//        return aT.size();
//    }
//    template<>
//    bool fun(int aT) {
//        return aT;
//    }
//};


#endif //DISCUSSION5_TEMPLATES_HPP
