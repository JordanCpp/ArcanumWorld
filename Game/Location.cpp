#include "Location.h"

Location::Location(ResourceManager * Source, ObjectManager* SourceObjectManager, XmlManager* XmlManagerSource, const std::string & Name):
    manager(Source),
    objects(SourceObjectManager),
    xml_manager(XmlManagerSource),
    reader(xml_manager->GetLocation(Name)),
    size(Point(0, 0))
{
    ReadLocation();
}

Location::~Location()
{
    objects->Clear();
}

size_t Location::Width()
{
    return size.PosX();
}

size_t Location::Height()
{
    return size.PosY();
}

Point Location::IsometricToCartesian(Point Pt)
{
    size_t x = (2 * Pt.PosY() + Pt.PosX()) / 2;
    size_t y = (2 * Pt.PosY() - Pt.PosX()) / 2;

    return Point(x, y);
}

Point Location::CartesianToIsometric(Point Pt)
{
    size_t x = Pt.PosX() - Pt.PosY();
    size_t y = (Pt.PosX() + Pt.PosY()) / 2;

    return Point(x, y);
}

size_t Location::PointToIndex(Point Pt)
{
  return (Width() * Pt.PosY()) + Pt.PosX();
}

Point Location::IndexToPoint(size_t Index)
{
  Point Pt(Index % Width(), Index / Width());

  return Pt;
}

void Location::ReadLocation()
{
    reader.Next();
    reader.AssertOpening("Location");

    while (reader.Next())
    {
        ReadInfo();
        ReadTiles();
    }

    reader.AssertClosing("Location");
}

void Location::ReadInfo()
{
    if (reader.IsOpening("Info"))
    {
        while (reader.NextNode())
        {
            if (reader.Name() == "Size")
            {
                size_t width = std::stoi(reader.Value());

                size.PosX(width);
                size.PosY(width);

                floor.reserve(size.PosX() * size.PosY());
            }
        }

        reader.AssertClosing("Info");
    }
}

void Location::ReadTiles()
{
    if (reader.IsOpening("Tiles"))
    {
        while (reader.Next() && !reader.IsClosing("Tiles"))
        {
            ReadFloor();
        }

        reader.AssertClosing("Tiles");
    }
}

void Location::ReadFloor()
{
    if (reader.IsOpening("Floor"))
    {
        while (reader.Next() && !reader.IsClosing("Floor"))
        {
            ReadTile();
        }

        reader.AssertClosing("Floor");
    }
}

void Location::ReadTile()
{
    if (reader.IsOpening("Tile"))
    {
        while (reader.NextNode())
        {
            if (reader.Name() == "Proto")
            {
                Tile * obj = objects->GetTile(reader.Value());
                floor.push_back(obj);
            }
        }

        reader.AssertClosing("Tile");
    }
}

void Location::ReadCritters()
{
    if (reader.IsOpening("Critters"))
    {
        while (reader.Next() && !reader.IsClosing("Critters"))
        {
            ReadCritter();
        }

        reader.AssertClosing("Critters");
    }
}

void Location::ReadCritter()
{
    if (reader.IsOpening("Critter"))
    {
        while (reader.NextNode())
        {
            if (reader.Name() == "Proto")
            {
                Critter * object = new Critter(xml_manager->GetXmlCritter(reader.Value()), manager);
                critters.push_back(object);
            }
        }

        reader.AssertClosing("Critter");
    }
}

void Location::DrawTiles(Point Start)
{
    for (size_t k = 0; k < floor.size(); k++)
    {
        size_t i = k / Width();
        size_t j = k % Width();;

        size_t x = j * Tile::Width / 2;
        size_t y = i * Tile::Height;

        Point Pt = CartesianToIsometric(Point(x, y));

        floor[k]->Draw(Point(Pt.PosX() + Start.PosX(), Pt.PosY() + Start.PosY()));
    }
}
