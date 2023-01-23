#include <iostream>
#include <vector>
#include <sstream>

using std::cout, std::endl,
	std::ostream;

class Value {
public:
	Value() {}
	Value(int aNum): num(aNum) {}
	~Value() {}
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
		num = aNum;
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
	int num;
};


int main() {
	cout << "Hello, World!" << endl;
	return 0;
}

/* Agenda:
 * Pointers & Memory
 * Object Lifestyle
 * Classes (OCF, Access Specifiers, This pointer, Inheritance)
 * Slight discussion on Polymorphism
 * Function Pointers & Functors
 * String Streams
 * is-a & has-a relationships
 * Warnings
 * templates & STL
 */

// Some sample text. Another sentence!