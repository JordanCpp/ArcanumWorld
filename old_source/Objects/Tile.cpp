#include "Tile.h"

Tile::Tile(XmlReader* Reader, ImageManager* SourceManager):
    script(nullptr),
    body(nullptr),
    critter(nullptr)
{
    Reader->NextOpening("Tile");

    Reader->NextNode("Body");
    body = SourceManager->GetTile(Reader->Value());

    Reader->NextClosing("Tile");
}

void Tile::Init(Critter* CritterSource)
{
    critter = CritterSource;
}

void Tile::Draw(Point pos)
{
    if (body)
    {
        body->Draw(pos);
    }
}