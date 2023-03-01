#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>

#include "BlockIO.hpp"

using ECE141::Block, ECE141::BlockHeader,
	std::string, std::stringstream;

const string DATABASE_PATH = "../Discussion.db";

void prepareBlock(Block& aBlock) {
	std::memset(aBlock.payload_, '%', ECE141::ACTUAL_PAYLOAD_SIZE);
	aBlock.payload_[ECE141::ACTUAL_PAYLOAD_SIZE] = '\0';
}

void insertData(Block& aBlock, string aData) {
	stringstream theStream(aData);
	theStream.read(aBlock.payload_, std::min(aData.length(), ECE141::ACTUAL_PAYLOAD_SIZE));
}

bool validParentheses(std::string aQuery);

int main() {
	std::fstream theStream;
	theStream.open(DATABASE_PATH, std::fstream::binary | std::fstream::in | std::fstream::out | std::fstream::trunc);
	Block theBlock;
	theBlock.header_ = BlockHeader();
	theBlock.header_.count = 2;
	theBlock.header_.id = 1;
	theBlock.header_.next = 2;
	theBlock.header_.pos = 2;
	prepareBlock(theBlock);
	insertData(theBlock, "Hello, World!123");

	ECE141::BlockIO theBlockIOStorage(theStream);
    theBlockIOStorage.writeBlock(0, theBlock);
    theBlockIOStorage.writeBlock(1, theBlock);


	Block theBlock2;
	theBlockIOStorage.readBlock(0, theBlock2);
//	const std::string test = "(()()(()()))";
//	std::cout << (validParentheses(test)) << std::endl;

    return 0;
}

// Given string parentheses determine if it's valid (all open parentheses are matched their closing ones)"
/*
 * (()))( - )(
 *
 * Solution:
 * Stack as a data structure {1) Can only remove top element 2) Can only look at the top element 3) Has size}
 */
bool validParentheses(std::string aQuery) {
    std::stack<char> theStack;

    for (char c: aQuery) {
        if (c == '(') {
            theStack.push(c);
            continue;
        }

        if (theStack.empty()) {
            return false;
        }

        if (theStack.top() == '(') {
            theStack.pop();
        }
    }
    return theStack.empty();
}

/*
 * Agenda:
 * Algorithm warmup (Open-Close Parentheses) https://leetcode.com/problems/valid-parentheses/
 * Discussion on Assignment 3
 * 	How to Approach README
 * 	    Always read the entire README
 * 	    Take notes
 * 	Ways to approach architecting a solution
 *      Implement everything in models but not fully
 * 	    Ways to approach Expressive Code Model Design
 * BlockIO Storage Model
 */

// Hold an in-memory JSON Model
class JSONModel {
public:
    // Fine details
};

// Parses JSON FILE
class JSONParser {
public:
    // Will parse the JSON file and save into a JSONModel object
    JSONModel& parseJSONFile(...);

    // Validate JSON file
    bool validJSONFile(...);
};

/*
 * Organize classes/functions based on problem sphere (NOT WORRY ABOUT FINE DETAILS)
 */

