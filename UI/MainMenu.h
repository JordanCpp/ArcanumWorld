#ifndef MAINMENU_H
#define MAINMENU_H

#include "../GUI/Button.h"
#include "../GUI/Window.h"
#include "../Game/Settings.h"

class MainMenu
{
public:
    MainMenu(Canvas * CanvasSource, Settings * SettingsSource);
    ~MainMenu();
    void Run();

private:
    Window window;
    Button new_game;
    Button editor;
};

#endif // MAINMENU_H
