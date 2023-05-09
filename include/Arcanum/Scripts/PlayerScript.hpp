#ifndef Arcanum_Scripts_PlayerScript_hpp
#define Arcanum_Scripts_PlayerScript_hpp

#include <Arcanum/Objects/ScriptCritter.hpp>

namespace Arcanum
{
	namespace Scripts
	{
		class PlayerScript: public Objects::ScriptCritter
		{
		public:
			void MapEnter();
		private:
		};
	}
}

#endif