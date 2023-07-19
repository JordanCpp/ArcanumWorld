#include <Arcanum/Managers/FontManager.hpp>

using namespace Arcanum::Text;
using namespace Arcanum::Managers;
using namespace Arcanum::Readers;

FontManager::FontManager(FileManager* fileManager, Rasterizer* rasterizer) :
    _FileManager(fileManager),
	_Rasterizer(rasterizer)
{
}

FontManager::~FontManager()
{
    for (auto i = _Fonts.begin(); i != _Fonts.end(); i++)
    {
        delete i->second;
    }
}

Font* FontManager::GetFont(const std::string& path, size_t sizeFont)
{
    std::string filePath = "fonts/" + path;

    auto i = _Fonts.find(filePath);

    Font* result = nullptr;

    if (i == _Fonts.end())
    {
        MemoryReader reader = _FileManager->GetFile(filePath);

        result = new Font(_Rasterizer, reader, sizeFont);

        _Fonts.emplace(filePath, result);
    }
    else
    {
        result = i->second;
    }

    return result;
}