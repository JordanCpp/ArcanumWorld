#include <Arcanum/Managers/SpriteManager.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Managers;
using namespace Arcanum::Graphics;
using namespace Arcanum::Loaders;

SpriteManager::SpriteManager(RenderContext* renderContext, ArtLoader* artLoader, PathManager* pathManager) :
    _RenderContext(renderContext),
    _ArtLoader(artLoader),
    _PathManager(pathManager)
{
}

SpriteManager::~SpriteManager()
{
    for (auto i = _Sprites.begin(); i != _Sprites.end(); i++)
        delete i->second;
}

Arcanum::Graphics::Sprite* SpriteManager::Sprite(const std::string& dir, const std::string& file)
{
    const char* path = _PathManager->Path(dir, file).c_str();

    auto i = _Sprites.find(path);

    Arcanum::Graphics::Sprite* result = nullptr;

    if (i == _Sprites.end())
    {
        _ArtLoader->Load(path);

        result = new Arcanum::Graphics::Sprite;

        for (size_t i = 0; i < _ArtLoader->Frames(); i++)
        {
            _ArtLoader->Frame(i);

            Image* image = new Image(_RenderContext, _ArtLoader->Size(), _ArtLoader->Pixels(), _ArtLoader->Offset(), _ArtLoader->Delta());

            result->Append(image);
        }

        _Sprites.emplace(path, result);
    }
    else
    {
        result = i->second;
    }

    return result;
}

Sprite* SpriteManager::Scenery(const std::string& fileName)
{
    return Sprite("art/scenery/", fileName);
}

Sprite* SpriteManager::Tile(const std::string& fileName)
{
    return Sprite("art/tile/", fileName);
}

Sprite* SpriteManager::Interface(const std::string& fileName)
{
    return Sprite("art/interface/", fileName);
}