#include <iostream>
#include <sstream>


#include <vector>
#include <string>
#include <map>
#include <algorithm>

void func() {
    std::vector<int> theVec = {4, 1, 4, 2, 3};
    std::sort(theVec.begin(), theVec.end());
    int a = 1;
}

using std::cout, std::endl, std::string;

class Object{
    // 100 bytes
public:
    void member() {}
};

// pass-by-reference
// pass-by-value
void function1(Object* anObject) {}

void function(int& num) {

    num++;
}

int main() {
    /*
     * 0x00000000
     * -
     * 0xFFFFFFFF
     */

    func();
    // Reference - Pointer
    // Reference exists in Stack
//    Object anObject;
//    // Pointer exists in Heap
//    Object* aPointer;

//    anObject.member();
////    int num = 1;
////    cout << "Before: " << num << "\n";
////    function(num);
////    cout << "After: " << num << endl;
//
//    Object* anObjectPtr = new Object();
//    anObjectPtr->member();
//
//    Object dereferencedObj = *anObjectPtr;
//
//    int anObjectPtrVal = 1234;



    return 0;
}
