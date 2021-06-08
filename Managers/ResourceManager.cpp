#include "ResourceManager.h"
#include "../Common/Utils.h"

ResourceManager::ResourceManager(Canvas * Source, const std::string & Path):
    canvas(Source),
    short_path(Path),
    reader("", XmlReader::FromString)
{
}

ResourceManager::~ResourceManager()
{
    for (auto i =  images.begin(); i != images.end(); i++)
    {
        delete i->second;
    }

    for (auto i =  xml_files.begin(); i != xml_files.end(); i++)
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

XmlFile * ResourceManager::GetXmlFile(const std::string & DirName, const std::string & FileName)
{
    Utils::ConcatPath(full_path, short_path, DirName, FileName);

    auto i =  xml_files.find(full_path);

    XmlFile * p = nullptr;

    if (i == xml_files.end())
    {
        p = new XmlFile(full_path);
        xml_files.emplace(full_path, p);
    }
    else
    {
        p = i->second;
    }

    return p;
}

XmlReader * ResourceManager::GetXml(const std::string & DirName, const std::string & FileName)
{
    Utils::ConcatPath(full_path, short_path, DirName, FileName);

    auto i =  xml_files.find(full_path);

    XmlFile * p = nullptr;

    if (i == xml_files.end())
    {
        p = new XmlFile(full_path);
        xml_files.emplace(full_path, p);
    }
    else
    {
        p = i->second;
    }

    reader.Reset(p->Content(), XmlReader::FromString);

    return &reader;
}

XmlReader * ResourceManager::GetXmlTile(const std::string & Name)
{
    return GetXml("Prototypes\\Tiles\\", Name);
}

XmlReader* ResourceManager::GetXmlCritter(const std::string& Name)
{
    return GetXml("Prototypes\\Critters\\", Name);
}

XmlFile * ResourceManager::GetProtoTile(const std::string & Name)
{
    return GetXmlFile("Prototypes\\Tiles\\", Name);
}

XmlFile * ResourceManager::GetProtoScenery(const std::string & Name)
{
    return GetXmlFile("Prototypes\\Scenery\\", Name);
}

Image * ResourceManager::GetTile(const std::string & Name)
{
    return GetImage("Images\\Tiles\\", Name);
}

const std::string & ResourceManager::GetLocation(const std::string & Source)
{
    Utils::ConcatPath(full_path, short_path, "Locations\\", Source);

    return full_path;
}
