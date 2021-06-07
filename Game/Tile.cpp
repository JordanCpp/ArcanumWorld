#include "Tile.h"

Tile::Tile(XmlReader* Reader, ResourceManager* SourceManager):
    body(nullptr)
{
    Reader->NextOpening("Tile");

    Reader->NextNode("Body");
    body = SourceManager->GetTile(Reader->Value());

    Reader->NextClosing("Tile");
}

Tile::~Tile()
{
}

void Tile::Draw(Point pos)
{
    if (body)
    {
        body->Draw(pos);
    }
}
