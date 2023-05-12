#ifndef Arcanum_Objects_Critter_hpp
#define Arcanum_Objects_Critter_hpp

#include <Arcanum/Objects/CritterScript.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class CritterScript;

		class Critter
		{
		public:
			void Init(CritterScript* script);
		private:
			CritterScript* _Script;
		};
	}
}

#endif