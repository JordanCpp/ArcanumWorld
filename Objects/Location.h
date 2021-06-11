#ifndef _Objects_Location_h_
#define _Objects_Location_h_ 

#include <vector>
#include "ScriptLocation.h"
#include "ScriptCritter.h"
#include "../Managers/ObjectManager.h"
#include "../Graphics/Point.h"
#include "Tile.h"

class ScriptLocation;
class ObjectManager;

class Location
{
public:
	Location(ObjectManager* ObjectManagerSource);
	size_t Width();
	size_t Height();
	void Clear();
	void Load(const std::string& Name);
	void DrawTiles(Point Start);
private:
	void InitScripts();
	void AddObject(Critter* critter);
	void AddObject(Tile* tile);
	void AddScript(ScriptCritter* script);
	Point IsometricToCartesian(Point Pt);
	Point CartesianToIsometric(Point Pt);
	size_t PointToIndex(Point Pt);
	Point IndexToPoint(size_t Index);
	void ReadLocation();
	void ReadInfo();
	void ReadTiles();
	void ReadFloor();
	void ReadTile();
	void ReadCritters();
	void ReadCritter();
	ScriptLocation* self;
	std::vector<ScriptCritter*> critter_scripts;
	std::vector<ScriptTile*> tile_scripts;
	std::vector<Tile*> floor;
	std::vector<Critter*> critters;
	XmlReader reader;
	ObjectManager* object_manager;
	Point size;
};

#endif