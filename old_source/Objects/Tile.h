#ifndef _Objects_Tile_h_
#define _Objects_Tile_h_

#include "../Graphics/Image.h"
#include "../Managers/ImageManager.h"
#include "../Common/XmlReader.hpp"
#include "Critter.h"
#include "ScriptTile.h"

class ScriptTile;

class Tile
{
public:
    enum
    {
        Width  = 78,
        Height = 40
    };

    Tile(XmlReader* Reader, ImageManager* SourceManager);
    void Init(Critter* CritterSource);
    void Draw(Point pos);
private:
    ScriptTile* script;
    Image * body;
    Critter* critter;
};

#endif