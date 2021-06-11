#ifndef _TextManager_h_
#define _TextManager_h_ 

#include <unordered_map>
#include "../Graphics/Text.h"

class TextManager
{
public:

private:
	std::unordered_map<std::string, Text*> text_strings;
};

#endif