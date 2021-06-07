#include "LinearAllocator.h"
#include <cassert>

LinearAllocator::LinearAllocator(size_t Count) :
	total(Count),
	pos(0),
	data(nullptr)
{
	data = new uint8_t[total];
}

LinearAllocator::~LinearAllocator()
{
	delete[] data;
}

void* LinearAllocator::Alloc(size_t Count)
{
	assert(pos + Count < total);

	pos += Count;

	uint8_t* p = &data[pos];

	return p;
}

size_t LinearAllocator::FreeSize()
{
	return total - pos;
}

size_t LinearAllocator::UsedSize()
{
	return pos;
}
