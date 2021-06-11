#ifndef _Settings_h_
#define _Settings_h_

#include <string>
#include "../Graphics/Point.h"

class Settings
{
public:
    Settings(const std::string & Name);
    ~Settings();
    const std::string & Path();
    size_t Fps();
    Point WindowSize();
private:
    Point size;
    size_t fps;
    std::string path;
};

#endif