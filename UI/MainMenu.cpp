#include "MainMenu.h"

MainMenu::MainMenu(Canvas * CanvasSource, Settings * SettingsSource, ImageManager* ImageManagerSource):
    window(CanvasSource, Rect(0, 0, SettingsSource->WindowSize().PosX(), SettingsSource->WindowSize().PosY())),
    new_game(CanvasSource, Rect(15, 15, 100, 25)),
    editor(CanvasSource, Rect(15, 60, 100, 25)),
    image_manager(ImageManagerSource)
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
    image_manager->GetInterface("main_menu.bmp")->Draw(Point(0, 0));
}
