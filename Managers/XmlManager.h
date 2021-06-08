#ifndef _XmlManager_h_
#define _XmlManager_h_

#include <unordered_map>
#include "../Common/XmlFile.hpp"
#include "../Common/XmlReader.hpp"

class XmlManager
{
public:
    XmlManager(const std::string& Path);
    ~XmlManager();
    XmlFile* GetXmlFile(const std::string& DirName, const std::string& FileName);
    XmlReader* GetXml(const std::string& DirName, const std::string& FileName);
    XmlReader* GetXmlTile(const std::string& Name);
    XmlReader* GetXmlCritter(const std::string& Name);
    XmlFile* GetProtoTile(const std::string& Name);
    XmlFile* GetProtoScenery(const std::string& Name);
    const std::string& GetLocation(const std::string& Source);
private:
	std::string short_path;
	std::string full_path;
	std::unordered_map<std::string, XmlFile*> xml_files;
	XmlReader reader;
};

#endif