#include "Location.h"

Location::Location(ObjectManager* ObjectManagerSource) :
	reader("", XmlReader::FromString),
	object_manager(ObjectManagerSource),
    size(Point(0, 0))
{
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

size_t Location::Width()
{
    return size.PosX();
}

size_t Location::Height()
{
    return size.PosY();
}

void Location::Clear()
{
    self = nullptr;
    critter_scripts.clear();
    floor.clear();
    critters.clear();
}

void Location::Load(const std::string& Name)
{
    Clear();
	reader.Reset(Name, XmlReader::FromFile);
    ReadLocation();
}

void Location::InitScripts()
{
	for (size_t i = 0; i < critter_scripts.size(); i++)
	{
		critter_scripts[i]->MapEnter();
	}
}

Point Location::IsometricToCartesian(Point Pt)
{
    size_t x = (2 * Pt.PosY() + Pt.PosX()) / 2;
    size_t y = (2 * Pt.PosY() - Pt.PosX()) / 2;

    return Point(x, y);
}

void Location::AddObject(Critter* critter)
{
    critters.push_back(critter);
}

void Location::AddScript(ScriptCritter* script)
{
    critter_scripts.push_back(script);
}

Point Location::CartesianToIsometric(Point Pt)
{
    size_t x = Pt.PosX() - Pt.PosY();
    size_t y = (Pt.PosX() + Pt.PosY()) / 2;

    return Point(x, y);
}

void Location::AddObject(Tile* tile)
{
    floor.push_back(tile);
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
                Tile* tile = object_manager->GetTile(reader.Value());
                floor.push_back(tile);
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
            Critter* critter = nullptr;

            if (reader.Name() == "Proto")
            {
                critter = object_manager->GetCritter(reader.Value());
                critters.push_back(critter);
            }

            if (reader.Name() == "Script")
            {
                ScriptCritter * script = object_manager->GetScriptCritter(reader.Value());
                critter_scripts.push_back(script);
                critter->Init(script);
                script->Init(critter);
            }
        }

        reader.AssertClosing("Critter");
    }
}