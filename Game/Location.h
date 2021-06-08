#ifndef LOCATION_H
#define LOCATION_H

#include <vector>
#include "Tile.h"
#include "../Managers/ResourceManager.h"
#include "../Common/XmlReader.hpp"
#include "Critter.h"
#include "../Managers/ObjectManager.h"
#include "../Managers/XmlManager.h"

class Location
{
public:
    Location(ResourceManager * Source, ObjectManager * SourceObjectManager, XmlManager* XmlManagerSource, const std::string & Name);
    ~Location();
    size_t Width();
    size_t Height();
    void DrawTiles(Point Start);

private:
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
    ResourceManager * manager;
    ObjectManager* objects;
    XmlManager* xml_manager;
    std::vector<Tile*> floor;
    std::vector<Critter*> critters;
    XmlReader reader;
    Point size;
};

#endif // LOCATION_H
