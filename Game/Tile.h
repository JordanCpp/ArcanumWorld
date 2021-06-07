#ifndef _Objects_Tile_h_
#define _Objects_Tile_h_

#include "../Graphics/Image.h"
#include "ResourceManager.h"

class Tile
{
public:
    enum
    {
        Width  = 78,
        Height = 40
    };

    Tile();
    ~Tile();
    void Init(XmlReader * Reader, ResourceManager * SourceManager);
    void Draw(Point pos);

private:
    Image* t[6];
    Image * body;
};

#endif // TILE_H
