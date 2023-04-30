#include "ScriptTile.h"

ScriptTile::ScriptTile(Engine* EngineSource) :
	Script(EngineSource)
{
}

void ScriptTile::Init(Tile* TileSource)
{
	location = TileSource;
}