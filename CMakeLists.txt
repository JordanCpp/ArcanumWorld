cmake_minimum_required(VERSION 3.8)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

#Install LDL
set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)
set(LDL_RENDER_OPENGL1 true)
add_subdirectory(dependencies/LDL/source)
include_directories(dependencies/LDL/include)
link_directories (${CMAKE_CURRENT_BINARY_DIR}/dependencies/LDL)

#Install zlib
add_subdirectory(dependencies/zlib)
include_directories(dependencies/zlib)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/zlib)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/zlib)

include_directories("include")

add_library(ArcanumLib STATIC
"source/Game/Engine.cpp" 
"source/Game/Settings.cpp"

"source/Managers/PathManager.cpp"
"source/Managers/SpriteManager.cpp"
"source/Managers/WidgetManager.cpp"
"source/Managers/ScriptManager.cpp"
"source/Managers/ObjectManager.cpp"
"source/Managers/FileManager.cpp"

"source/Formats/Art.cpp"
"source/Formats/Msg.cpp"
"source/Formats/Sec.cpp"

"source/Graphics/Image.cpp"
"source/Graphics/Sprite.cpp"
"source/Graphics/Camera.cpp"

"source/Loaders/ArtLoader.cpp"
"source/Loaders/LocationLoader.cpp"
"source/Loaders/SettingsLoader.cpp"
"source/Loaders/DatLoader.cpp"

"source/Readers/ByteReader.cpp"
"source/Readers/MesReader.cpp"
"source/Readers/SecReader.cpp"
"source/Readers/XmlReader.cpp"
"source/Readers/MemoryReader.cpp"
"source/Readers/DatReader.cpp"

"source/Writters/XmlWritter.cpp"

"source/Savers/LocationSaver.cpp"

"source/Core/RuntimeError.cpp"
"source/Core/PathNormalizer.cpp"

"source/Objects/Tile.cpp"
"source/Objects/Critter.cpp"
"source/Objects/LocationData.cpp"
"source/Objects/LocationCreator.cpp"
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

target_link_libraries(ArcanumLib LDL zlibstatic)

add_executable(ArcanumWorld "source/main.cpp")
target_link_libraries(ArcanumWorld ArcanumLib)

add_executable(GenMap "source/GenMap.cpp")
target_link_libraries(GenMap ArcanumLib)

add_subdirectory("test")