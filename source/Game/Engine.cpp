#include <Arcanum/Game/Engine.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Allocators;
using namespace LDL::Enums;
using namespace LDL::Loaders;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace Arcanum::Game;

Engine::Engine(Settings* settings) :
	_Settings(settings),
	_PathManager(settings->Path()),
	_ImageAllocator(Allocator::Mb * 2),
	_ImageLoader(&_ImageAllocator),
	_Window(Point2u(0,0), _Settings->Size(), _Settings->Title(), WindowMode::Fixed),
	_Render(&_RenderContext, &_Window),
	_FpsLimiter(_Settings->Fps()),
	_SpriteManager(&_RenderContext, &_ArtLoader, &_PathManager),
	_SecReader(&_ByteReader),
	_LocationPainter(&_Render, &_Location),
	_WidgetManager(&_Render),
	_GameMenu(&_Render),
	_Camera(Point2u(400, 50), _Render.Size())
{
	_SecReader.Reset(_PathManager.Path("maps/Tarant Sewers-01/", "0.sec"));

	size_t sz = 10;

	_Location.Reset(Point2u(sz, sz));
	
	for (size_t i = 0; i < _Location.Size().PosX() * _Location.Size().PosY(); i++)
	{
		_Location.Tiles()[i].Init(_SpriteManager.Tile("grsbse0c.ART"));
	}

	_Location.GetScenery(3, 7).Init(_SpriteManager.Scenery("savanna_tree02.ART"));
	_Location.GetScenery(9, 7).Init(_SpriteManager.Scenery("engine.ART"));
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

	while (_Window.GetEvent(report))
	{
		_FpsLimiter.Mark();
		_FpsCounter.Start();

		if (report.Type == IsQuit)
		{
			_Window.StopEvent();
		}

		_Render.Begin();

		_Render.Color(Color(0, 0, 0));
		_Render.Clear();

		_LocationPainter.Draw(_Camera.Pos());

		_GameMenu.Draw();

		_Render.End();

		_Camera.Handle(report);

		_FpsLimiter.Throttle();

		ShowFps();
	}
}