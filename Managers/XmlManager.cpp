#include "XmlManager.h"
#include "../Common/Utils.h"

XmlManager::XmlManager(const std::string& Path):
	IManager(Path),
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
    auto i = xml_files.find(GetPath(DirName, FileName));

    XmlFile* p = nullptr;

    if (i == xml_files.end())
    {
        p = new XmlFile(GetPath(DirName, FileName));
        xml_files.emplace(GetPath(DirName, FileName), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}

XmlReader* XmlManager::GetReader(const std::string& DirName, const std::string& FileName)
{
    XmlFile* p = GetXmlFile(DirName, FileName);

    reader.Reset(p->Content(), XmlReader::FromString);

    return &reader;
}

XmlReader* XmlManager::GetTile(const std::string& Name)
{
    return GetReader("Prototypes\\Tiles\\", Name);
}

XmlReader* XmlManager::GetCritter(const std::string& Name)
{
    return GetReader("Prototypes\\Critters\\", Name);
}

const std::string& XmlManager::GetLocation(const std::string& Source)
{
    return GetPath("Locations\\", Source);
}