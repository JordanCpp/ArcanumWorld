#ifndef _XmlManager_h_
#define _XmlManager_h_ 

#include <unordered_map>
#include "../Common/XmlFile.hpp"
#include "../Common/XmlReader.hpp"
#include "IManager.h"

class XmlManager: public IManager
{
public:
	XmlManager(const std::string& Path);
	~XmlManager();
	XmlFile* GetXmlFile(const std::string& DirName, const std::string& FileName);
	XmlReader* GetReader(const std::string& DirName, const std::string& FileName);
	XmlReader* GetTile(const std::string& Name);
	XmlReader* GetCritter(const std::string& Name);
	const std::string& GetLocation(const std::string& Source);
private:
	XmlReader reader;
	std::unordered_map<std::string, XmlFile*> xml_files;
};

#endif