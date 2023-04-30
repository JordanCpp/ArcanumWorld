#ifndef Arcanum_Readers_MsgReader_hpp
#define Arcanum_Readers_MsgReader_hpp

#include <string>
#include <fstream>

namespace Arcanum
{
	namespace Readers
	{
		class MsgReader
		{
		public:
			void Reset(const std::string& path);
		private:
			std::ifstream _File;
			std::string   _Result;
		};
	}
}

#endif    