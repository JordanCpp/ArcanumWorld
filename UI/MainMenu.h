#ifndef MAINMENU_H
#define MAINMENU_H

#include "../GUI/Button.h"
#include "../GUI/Window.h"
#include "../Game/Settings.h"
#include "../Managers/ImageManager.h"

class MainMenu
{
public:
    MainMenu(Canvas * CanvasSource, Settings * SettingsSource, ImageManager* ImageManagerSource);
    ~MainMenu();
    void Run();

private:
    Window window;
    Button new_game;
    Button editor;
    ImageManager* image_manager;
};

#endif // MAINMENU_H
