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
    Image * GetImage(const std::string & DirName, const std::string & FileName);
    Image* GetTile(const std::string& Name);
private:
    Canvas * canvas;
    std::string short_path;
    std::string full_path;
    std::unordered_map<std::string, Image*> images;
    
    
};

#endif // _ResourceManager_h_
