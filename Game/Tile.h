#ifndef _Objects_Tile_h_
#define _Objects_Tile_h_

#include "../Graphics/Image.h"
#include "../Managers/ResourceManager.h"
#include "Critter.h"

class ResourceManager;

class Tile
{
public:
    enum
    {
        Width  = 78,
        Height = 40
    };

    Tile(XmlReader* Reader, ResourceManager* SourceManager);
    ~Tile();
    void Draw(Point pos);

private:
    Image * body;
    Critter* critter;
};

#endif // TILE_H
