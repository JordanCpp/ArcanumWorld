#include "MainMenu.h"

MainMenu::MainMenu(Canvas * CanvasSource, Settings * SettingsSource):
    window(CanvasSource, Rect(0, 0, SettingsSource->WindowSize().PosX(), SettingsSource->WindowSize().PosY())),
    new_game(CanvasSource, Rect(15, 15, 100, 25)),
    editor(CanvasSource, Rect(15, 60, 100, 25))
{
    window.Append(&new_game);
    window.Append(&editor);
}

MainMenu::~MainMenu()
{
}

void MainMenu::Run()
{
    window.Draw();
}
