cmake_minimum_required(VERSION 3.8)

include_directories("dependencies/LDL/include")
link_directories("dependencies/LDL/lib")

include_directories("include")

add_library(ArcanumLib STATIC
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp"

"source/Managers/PathManager.cpp"
"source/Managers/SpriteManager.cpp"
"source/Managers/WidgetManager.cpp"

"source/Formats/Art.cpp"
"source/Formats/Msg.cpp"
"source/Formats/Sec.cpp"

"source/Graphics/Image.cpp"
"source/Graphics/Sprite.cpp"
"source/Graphics/Camera.cpp"

"source/Loaders/ArtLoader.cpp"

"source/Readers/ByteReader.cpp"
"source/Readers/MesReader.cpp"
"source/Readers/SecReader.cpp"

"source/Core/RuntimeError.cpp"

"source/Objects/Tile.cpp"
"source/Objects/Critter.cpp"
"source/Objects/Location.cpp"
"source/Objects/Scenery.cpp"
"source/Objects/TileData.cpp"
"source/Objects/Script.cpp"
"source/Objects/ScriptCritter.cpp"

"source/Widgets/Widget.cpp"
"source/Widgets/Button.cpp"
"source/Widgets/Form.cpp"
"source/Widgets/Container.cpp"

"source/Forms/GameMenu.cpp"

"source/Painters/LocationPainter.cpp"
"source/Painters/LocationPainter3D.cpp")

add_executable(Arcanum "source/main.cpp")

target_link_libraries(Arcanum ArcanumLib LDL)

add_subdirectory("test")