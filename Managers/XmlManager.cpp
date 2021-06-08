#include "XmlManager.h"
#include "../Common/Utils.h"

XmlManager::XmlManager(const std::string& Path) :
    short_path(Path),
    reader("", XmlReader::FromString)
{
}

XmlManager::~XmlManager()
{
    for (auto i = xml_files.begin(); i != xml_files.end(); i++)
    {
        delete i->second;
    }
}

XmlFile* XmlManager::GetXmlFile(const std::string& DirName, const std::string& FileName)
{
    Utils::ConcatPath(full_path, short_path, DirName, FileName);

    auto i = xml_files.find(full_path);

    XmlFile* p = nullptr;

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

XmlReader* XmlManager::GetXml(const std::string& DirName, const std::string& FileName)
{
    Utils::ConcatPath(full_path, short_path, DirName, FileName);

    auto i = xml_files.find(full_path);

    XmlFile* p = nullptr;

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

XmlReader* XmlManager::GetXmlTile(const std::string& Name)
{
    return GetXml("Prototypes\\Tiles\\", Name);
}

XmlReader* XmlManager::GetXmlCritter(const std::string& Name)
{
    return GetXml("Prototypes\\Critters\\", Name);
}

XmlFile* XmlManager::GetProtoTile(const std::string& Name)
{
    return GetXmlFile("Prototypes\\Tiles\\", Name);
}

XmlFile* XmlManager::GetProtoScenery(const std::string& Name)
{
    return GetXmlFile("Prototypes\\Scenery\\", Name);
}

const std::string& XmlManager::GetLocation(const std::string& Source)
{
    Utils::ConcatPath(full_path, short_path, "Locations\\", Source);

    return full_path;
}
