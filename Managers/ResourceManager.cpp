#include "ResourceManager.h"
#include "../Common/Utils.h"

ResourceManager::ResourceManager(Canvas * Source, const std::string & Path):
    canvas(Source),
    short_path(Path)
{
}

ResourceManager::~ResourceManager()
{
    for (auto i =  images.begin(); i != images.end(); i++)
    {
        delete i->second;
    }
}

Image * ResourceManager::GetImage(const std::string & DirName, const std::string & FileName)
{
   Utils::ConcatPath(full_path, short_path, DirName, FileName);

    auto i =  images.find(full_path);

    Image * p = nullptr;

    if (i == images.end())
    {
        p = new Image(canvas, full_path);
        images.emplace(full_path, p);
    }
    else
    {
        p = i->second;
    }

    return p;
}

Image* ResourceManager::GetTile(const std::string& Name)
{
    return GetImage("Images\\Tiles\\", Name);
}