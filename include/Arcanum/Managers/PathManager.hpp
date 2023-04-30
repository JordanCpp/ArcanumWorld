#ifndef Arcanum_Managers_PathManager_hpp
#define Arcanum_Managers_PathManager_hpp

#include <string>

namespace Arcanum
{
	namespace Managers
	{
		class PathManager
		{
		public:
			PathManager(const std::string& path);
			const std::string& Path(const std::string& dir, const std::string& file);
		private:
			std::string _ShortPath;
			std::string _FullPath;
		};
	}
}

#endif    