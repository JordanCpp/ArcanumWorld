#include <Arcanum/Allocators/ObjectAllocator.hpp>

using namespace LDL::Allocators;
using namespace Arcanum::Allocators;
using namespace Arcanum::Objects;

ObjectAllocator::ObjectAllocator(size_t bytes, LDL::Allocators::Allocator* allocator) :
	_Allocator(bytes, allocator)
{
}

Scenery* ObjectAllocator::GetScenery()
{
	void * p = _Allocator.Allocate(sizeof(Scenery));

	return new(p) Scenery;
}

Critter* ObjectAllocator::GetCritter()
{
	void* p = _Allocator.Allocate(sizeof(Critter));

	return new(p) Critter;
}
