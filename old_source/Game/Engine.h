#ifndef _Engine_h_
#define _Engine_h_

#include "../Managers/SpriteManager.h"
#include "../Managers/XmlManager.h"
#include "../Managers/ObjectManager.h"
#include "../Managers/ScriptManager.h"
#include "../Managers/ImageManager.h"
#include "Settings.h"

class Engine
{
public:
	void Init(Canvas* CanvasSource, SpriteManager* SpriteSource, XmlManager* XmlSource, ObjectManager* ObjectSource, ScriptManager* ScriptSource, Location* LocationSource, Settings* SettingsSource, ImageManager* ImageSource);
	void Run();
private:
	Canvas* canvas;
	SpriteManager* sprite_manager;
	XmlManager* xml_manager;
	ObjectManager* object_manager;
	ScriptManager* script_manager;
	Location* location;
	Settings* setttings;
	ImageManager* image_manager;
};

#endif