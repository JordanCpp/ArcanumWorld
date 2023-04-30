#ifndef _ImageManager_h_
#define _ImageManager_h_ 

#include <unordered_map>
#include "../Graphics/Canvas.h"
#include "../Graphics/Image.h"
#include "IManager.h"

class ImageManager: public IManager
{
public:
    ImageManager(Canvas* Source, const std::string& Path);
    ~ImageManager();
    Image* GetImage(const std::string& DirName, const std::string& FileName);
    Image* GetTile(const std::string& Name);
    Image* GetInterface(const std::string& Name);
private:
    Canvas* canvas;
    std::unordered_map<std::string, Image*> images;
};

#endif