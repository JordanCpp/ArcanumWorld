cmake_minimum_required(VERSION 3.8)

include_directories("dependencies/LDL/include")
link_directories("dependencies/LDL/lib")

include_directories("include")

add_library(ArcanumLib STATIC
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp"

"source/Managers/PathManager.cpp"
"source/Managers/SpriteManager.cpp"

"source/Formats/Art.cpp"
"source/Formats/Msg.cpp"

"source/Graphics/Image.cpp"
"source/Graphics/Sprite.cpp"

"source/Loaders/ArtLoader.cpp"

"source/Readers/ByteReader.cpp"
"source/Readers/MesReader.cpp"
"source/Readers/SecReader.cpp"

"source/Core/RuntimeError.cpp"

"source/Objects/Tile.cpp"
"source/Objects/Location.cpp"

"source/Painters/LocationPainter.cpp")

add_executable(Arcanum "source/main.cpp")

target_link_libraries(Arcanum ArcanumLib LDL)

add_subdirectory("test")