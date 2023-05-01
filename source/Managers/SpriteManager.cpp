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

Sprite* SpriteManager::GetSprite(const std::string& dir, const std::string& file)
{
    const char* path = _PathManager->Path(dir, file).c_str();

    auto i = _Sprites.find(path);

    Sprite* result = nullptr;

    if (i == _Sprites.end())
    {
        _ArtLoader->Load(path);

        result = new Sprite;

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

Sprite* SpriteManager::GetScenery(const std::string& fileName)
{
    return GetSprite("art/scenery/", fileName);
}