#ifndef Arcanum_Managers_FontManager_hpp
#define Arcanum_Managers_FontManager_hpp

#include <unordered_map>
#include <Arcanum/Text/Font.hpp>
#include <Arcanum/Managers/FileManager.hpp>

namespace Arcanum
{
	namespace Managers
	{
		class FontManager
		{
		public:
			FontManager(FileManager* fileManager, Text::Rasterizer* rasterizer);
			~FontManager();
			Text::Font* GetFont(const std::string& path, size_t sizeFont);
		private:
			FileManager* _FileManager;
			Text::Rasterizer* _Rasterizer;
			std::unordered_map<std::string, Text::Font*> _Fonts;
		};
	}
}

#endif    