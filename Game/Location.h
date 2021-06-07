#ifndef LOCATION_H
#define LOCATION_H

#include <vector>
#include "Tile.h"
#include "ResourceManager.h"
#include "../Common/XmlReader.hpp"

class Location
{
public:
    Location(ResourceManager * Source, const std::string & Name);
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

    ResourceManager * manager;
    std::vector<Tile> floor;
    XmlReader reader;
    Point size;
};

#endif // LOCATION_H
