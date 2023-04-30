#ifndef _Objects_ScriptTile_h_
#define _Objects_ScriptTile_h_ 

#include "Tile.h"
#include "Script.h"

class Tile;

class ScriptTile : public Script
{
public:
	ScriptTile(Engine* EngineSource);
	void Init(Tile* TileSource);
private:
	Tile* location;
};

#endif