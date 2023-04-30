#ifndef _Allocators_LinearAllocator_h_
#define _Allocators_LinearAllocator_h_

#include "Allocator.h"

class LinearAllocator: public Allocator
{
public:
	enum
	{
		Kb = 1024,
		Mb = Kb * 1024,
		Gb = Mb * 1024
	};

	LinearAllocator(size_t Count);
	~LinearAllocator();
	void Reset();
	void* Alloc(size_t Count);
	size_t FreeSize();
	size_t UsedSize();
private:
	size_t total;
	size_t pos;
	uint8_t* data;
};

#endif