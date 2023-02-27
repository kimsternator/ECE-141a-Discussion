#include "BlockIO.hpp"

namespace ECE141 {

	Block::Block(BlockType aType) : header_(aType) {}

	Block::Block(const Block &aCopy) {}

	Block& Block::operator=(const Block &aCopy) {
		return *this;
	}

	//---------------------------------------------------

	BlockIO::BlockIO(std::iostream &aStream) : stream(aStream) {}

	bool write(Block &aBlock, std::iostream &aStream, size_t aBlockSize) {
		if(aStream.write ((char*)&aBlock, aBlockSize)) {
			aStream.flush();
			return true;
		}
		return false;
	}

	// USE: write data a given block (after seek) ---------------------------------------
	bool BlockIO::writeBlock(uint32_t aBlockNum, Block &aBlock) {
		static size_t theSize=sizeof(aBlock);
		stream.seekg(stream.tellg(), std::ios::beg); //sync buffers...
		stream.seekp(aBlockNum * theSize);
		return write(aBlock, stream, theSize);
	}

	// USE: read data a given block (after seek) ---------------------------------------
	bool BlockIO::readBlock(uint32_t aBlockNumber, Block &aBlock) {
		static size_t theSize=sizeof(aBlock);
		stream.seekg(aBlockNumber * theSize);
		if(!stream.read ((char*)&aBlock, theSize)) {
			return false;
		}
		return true;
	}

	// USE: count blocks in file ---------------------------------------
	uint32_t BlockIO::getBlockCount() {
		stream.seekg(stream.tellg(), std::ios::beg); //force read mode; dumb c++ issue...
		stream.seekg(0, std::ios::end);
		int thePos = (int)stream.tellg();
		return thePos / sizeof(Block);
	}

}