#ifndef _FontManager_h_
#define _FontManager_h_ 

#include <unordered_map>
#include <string>
#include <SDL2/SDL_ttf.h>

class FontManager
{
public:

private:
	std::unordered_map<std::string, TTF_Font*> fonts;
};

#endif