#ifndef Arcanum_Objects_Critter_hpp
#define Arcanum_Objects_Critter_hpp

#include <Arcanum/Objects/ScriptCritter.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class ScriptCritter;

		class Critter
		{
		public:
			void Init(ScriptCritter* script);
		private:
			ScriptCritter* _Script;
		};
	}
}

#endif