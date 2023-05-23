#ifndef Arcanum_Allocators_ObjectAllocator_hpp
#define Arcanum_Allocators_ObjectAllocator_hpp

#include <LDL/Allocators/FixedLinear.hpp>
#include <Arcanum/Objects/Critter.hpp>
#include <Arcanum/Objects/Scenery.hpp>

namespace Arcanum
{
	namespace Allocators
	{
		class ObjectAllocator
		{
		public:
			ObjectAllocator(size_t bytes, LDL::Allocators::Allocator* allocator);
			Objects::Scenery* GetScenery();
			Objects::Critter* GetCritter();
		private:
			LDL::Allocators::FixedLinear _Allocator;
		};
	}
}

#endif