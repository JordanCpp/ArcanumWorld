#include "Settings.h"
#include "../Common/XmlReader.hpp"

Settings::Settings(const std::string& Name):
    size(Point(0, 0)),
    fps(0)
{
    XmlReader reader(Name);

    reader.NextOpening("Config");
    reader.NextOpening("Video");

    reader.NextNode("Width");
    size.PosX(reader.ValueInt());

    reader.NextNode("Height");
    size.PosY(reader.ValueInt());

    reader.NextNode("Fps");
    fps = reader.ValueInt();

    reader.NextClosing("Video");
    
    reader.NextNode("Path");
    path = reader.Value();

    reader.NextClosing("Config");
}

Settings::~Settings()
{
}

const std::string & Settings::Path()
{
    return path;
}

size_t Settings::Fps()
{
    return fps;
}

Point Settings::WindowSize()
{
    return size;
}