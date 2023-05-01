#ifndef Arcanum_Readers_MesReader_hpp
#define Arcanum_Readers_MesReader_hpp

#include <string>
#include <fstream>

namespace Arcanum
{
	namespace Readers
	{
		class MesReader
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