#ifndef _ResourceManager_h_
#define _ResourceManager_h_

#include <unordered_map>
#include <string>
#include "../Graphics/Canvas.h"
#include "../Graphics/Image.h"
#include "../Common/XmlFile.hpp"
#include "../Common/XmlReader.hpp"

class ResourceManager
{
public:
    ResourceManager(Canvas * Source, const std::string & Path);
    ~ResourceManager();
    void Normalize(std::string & Dest);
    void Concatenate(std::string & Dest, const std::string & DirName, const std::string & FileName);
    Image * GetImage(const std::string & DirName, const std::string & FileName);
    XmlFile * GetXmlFile(const std::string & DirName, const std::string & FileName);
    XmlReader * GetXml(const std::string & DirName, const std::string & FileName);
    Image * GetTile(const std::string & Name);
    XmlReader * GetXmlTile(const std::string & Name);
    XmlReader* GetXmlCritter(const std::string& Name);
    XmlFile * GetProtoTile(const std::string & Name);
    XmlFile * GetProtoScenery(const std::string & Name);
    const std::string & GetLocation(const std::string & Source);
private:
    Canvas * canvas;
    std::string short_path;
    std::string full_path;
    std::unordered_map<std::string, Image*> images;
    std::unordered_map<std::string, XmlFile*> xml_files;
    XmlReader reader;
};

#endif // _ResourceManager_h_
