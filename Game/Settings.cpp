#include "Settings.h"

Settings::Settings(Point Size, size_t Fps, const std::string & Path):
    size(Size),
    fps(Fps),
    path(Path)
{
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
