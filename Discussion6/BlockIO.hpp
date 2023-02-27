#ifndef BlockIO_hpp
#define BlockIO_hpp

#include <cstdio>
#include <iostream>
#include <cstring>

namespace ECE141 {

	enum class BlockType {
		data_block='D',
		index_block='I',
		unknown_block='U',
	};

	struct Empty{};

	//a small header that describes the block...
	struct BlockHeader {
		BlockHeader(BlockType aType=BlockType::data_block)
				: type(static_cast<char>(aType)), count(1),
				  pos(1), next(0), id(0) {}

		BlockHeader(const BlockHeader &aCopy) {
			*this=aCopy;
		}

		BlockHeader& operator=(const BlockHeader &aCopy)=default;

		char      type;     //char version of block type
		uint8_t   count;    //how many parts
		uint8_t   pos;      //i of n...
		uint32_t  next;     //next block in sequence.
		uint32_t  id;       //use this anyway you like
	};

	const size_t BLOCK_SIZE = 32;
	const size_t PAYLOAD_SIZE = BLOCK_SIZE - sizeof(BlockHeader);
	const size_t ACTUAL_PAYLOAD_SIZE = PAYLOAD_SIZE - 1;

	//block .................
	class Block {
	public:
		Block(BlockType aType=BlockType::data_block);
		Block(const Block &aCopy);

		Block& operator=(const Block &aCopy);

		BlockHeader   header_;
		char          payload_[PAYLOAD_SIZE];
	};

	//blockIO............
	class BlockIO {
	public:

		BlockIO(std::iostream &aStream);

		uint32_t              getBlockCount();

		virtual bool readBlock(uint32_t aBlockNumber,
										Block &aBlock);
		virtual bool writeBlock(uint32_t aBlockNumber,
										 Block &aBlock);
	protected:
		std::iostream &stream;
	};
}

#endif /* BlockIO_hpp */