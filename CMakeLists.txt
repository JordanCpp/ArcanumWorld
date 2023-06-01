cmake_minimum_required(VERSION 3.8)

#Install LDL
set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)
set(LDL_RENDER_OPENGL1 true)
add_subdirectory(dependencies/LDL/source)
include_directories(dependencies/LDL/include)
link_directories (${CMAKE_CURRENT_BINARY_DIR}/dependencies/LDL)

include_directories("include")

add_library(ArcanumLib STATIC
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp"

"source/Managers/PathManager.cpp"
"source/Managers/SpriteManager.cpp"
"source/Managers/WidgetManager.cpp"
"source/Managers/ScriptManager.cpp"
"source/Managers/ObjectManager.cpp"

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

"source/Writters/XmlWritter.cpp"

"source/Core/RuntimeError.cpp"

"source/Objects/Tile.cpp"
"source/Objects/Critter.cpp"
"source/Objects/LocationData.cpp"
"source/Objects/Location.cpp"
"source/Objects/Scenery.cpp"
"source/Objects/Script.cpp"
"source/Objects/CritterScript.cpp"
"source/Objects/Wall.cpp"
"source/Objects/MapObject.cpp"

"source/Allocators/ObjectAllocator.cpp"

"source/Widgets/Widget.cpp"
"source/Widgets/Button.cpp"
"source/Widgets/Form.cpp"
"source/Widgets/Container.cpp"

"source/Gameplay/StatCritter.cpp"

"source/Forms/GameMenu.cpp"

"source/Painters/LocationPainter.cpp"

"source/Scripts/PlayerScript.cpp")

add_executable(Arcanum "source/main.cpp")
target_link_libraries(Arcanum ArcanumLib LDL)

add_executable(GenMap "source/GenMap.cpp")
target_link_libraries(GenMap ArcanumLib LDL)

add_subdirectory("test")