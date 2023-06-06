#include <Arcanum/Game/Engine.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace LDL::Allocators;
using namespace LDL::Enums;
using namespace LDL::Loaders;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace Arcanum::Game;
using namespace Arcanum::Objects;

Engine::Engine(Settings* settings) :
	_Settings(settings),
	_OriginalAllocator(Allocator::Mb * 4),
	_PathManager(settings->Path()),
	_ImageAllocator(Allocator::Mb * 2, &_OriginalAllocator),
	_ImageLoader(&_ImageAllocator),
	_Window(Vec2u(0,0), _Settings->Size(), _Settings->Title(), WindowMode::Fixed),
	_Render(&_RenderContext, &_Window),
	_FpsLimiter(_Settings->Fps()),
	_SpriteManager(&_RenderContext, &_ArtLoader, &_PathManager),
	_SecReader(&_ByteReader),
	_LocationPainter(&_Render, &_LocationData),
	_WidgetManager(&_Render),
	_GameMenu(&_Render),
	_Camera(Vec2u(400, 100), _Render.Size()),
	_ObjectManager(&_ObjectAllocator, &_SpriteManager),
	_LocationCreator(&_LocationData, &_ObjectManager),
	_Location(&_LocationData, &_LocationCreator, &_LocationPainter),
	_LocationSaver(&_XmlWritter),
	_LocationLoader(&_XmlReader, &_LocationCreator)
{
	_LocationLoader.Reset("Empty.xml");
	/*
	_SecReader.Reset(_PathManager.Path("maps/Tarant Sewers-01/", "0.sec"));

	size_t sz = 10;

	_LocationData.Reset(Vec2u(sz, sz));
	
	for (size_t x = 0; x < _LocationData.Size().x; x++)
	{
		for (size_t y = 0; y < _LocationData.Size().y; y++)
		{
			_Location.NewTile(Vec2u(x, y), "grsbse0c.ART");
		}
	}

	_Location.NewScenery(Vec2u(3, 7), "savanna_tree02.ART");
	_Location.NewScenery(Vec2u(6, 5), "engine.ART");
	_Location.NewScenery(Vec2u(0, 0), "ArmorDisplay2.ART");

	_LocationSaver.Save(&_LocationData, "TestLocation.xml");
	*/
}

void Engine::ShowFps()
{
	if (_FpsCounter.Calc())
	{
		_Title = _Settings->Title() + " Fps: " + _Convert.Convert(_FpsCounter.Fps());
		_Window.Title(_Title);
		_FpsCounter.Clear();
	}
}

void Engine::Draw()
{
}

void Engine::Update()
{
}

void Engine::Run()
{
	Event report = { 0 };

	while (_Window.Running())
	{
		_FpsLimiter.Mark();
		_FpsCounter.Start();

		while (_Window.GetEvent(report))
		{
			if (report.Type == IsQuit || report.IsKeyPressed(KeyboardKey::Escape))
			{
				_Window.StopEvent();
			}
		}

		_Render.Begin();

		_Render.Color(Color(0, 0, 0));
		_Render.Clear();

		_Location.Draw(_Camera.Pos());

		_GameMenu.Draw();

		_Render.End();

		_Camera.Handle(report);

		_FpsLimiter.Throttle();

		ShowFps();

		_Window.PollEvents();
	}
}