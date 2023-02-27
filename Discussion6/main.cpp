#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

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


	Block theBlock2;
	theBlockIOStorage.readBlock(0, theBlock2);
	return 0;
}

/*
 * Agenda:
 * Algorithm warmup (Open-Close Parentheses) https://leetcode.com/problems/valid-parentheses/
 * Discussion on Assignment 3
 * 	How to Approach README
 * 	Ways to approach architecting a solution
 * 	Ways to approach Expressive Code Model Design
 * BlockIO Storage Model
 *
 */