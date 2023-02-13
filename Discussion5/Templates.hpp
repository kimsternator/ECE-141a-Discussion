//
// Created by steph on 2/13/2023.
//

#ifndef DISCUSSION5_TEMPLATES_HPP
#define DISCUSSION5_TEMPLATES_HPP

#include <iostream>
#include <string>

using std::string, std::cout;

template<typename T1, typename T2>
bool lessThan(T1 aLeft, T2 aRight) {
	return aLeft < aRight;
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
	printResult(lessThan(Coordinate{1, 2}, new Coordinate{1, 4}));
}


#endif //DISCUSSION5_TEMPLATES_HPP
