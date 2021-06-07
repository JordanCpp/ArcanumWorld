#include "Tile.h"

Tile::Tile():
    body(nullptr)
{
}

Tile::~Tile()
{
}

void Tile::Init(XmlReader * Reader, ResourceManager * SourceManager)
{
    Reader->NextOpening("Tile");

    Reader->NextNode("Body");
    body = SourceManager->GetTile(Reader->Value());

    Reader->NextClosing("Tile");
}

void Tile::Draw(Point pos)
{
    if (body)
    {
        body->Draw(pos);
    }
}
