#include "ImageManager.h"
#include "../Common/Utils.h"

ImageManager::ImageManager(Canvas* Source, const std::string& Path) :
    canvas(Source),
    IManager(Path)
{
}

ImageManager::~ImageManager()
{
    for (auto i = images.begin(); i != images.end(); i++)
    {
        delete i->second;
    }
}

Image* ImageManager::GetImage(const std::string& DirName, const std::string& FileName)
{
    auto i = images.find(GetPath(DirName, FileName));

    Image* p = nullptr;

    if (i == images.end())
    {
        p = new Image(canvas, GetPath(DirName, FileName));
        images.emplace(GetPath(DirName, FileName), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}

Image* ImageManager::GetTile(const std::string& Name)
{
    return GetImage("Images\\Tiles\\", Name);
}

Image* ImageManager::GetInterface(const std::string& Name)
{
    return GetImage("Images\\Interfaces\\", Name);
}