#ifndef Arcanum_Objects_ScriptCritter_hpp
#define Arcanum_Objects_ScriptCritter_hpp

#include <Arcanum/Objects/Script.hpp>
#include <Arcanum/Objects/Critter.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Critter;

		class ScriptCritter : public Script
		{
		public:
			Critter* Self();
			void Init(Critter* critter);
		private:
			Critter* _Critter;
		};
	}
}

#endif