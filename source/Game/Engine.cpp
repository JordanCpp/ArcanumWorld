#include <Arcanum/Game/Engine.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Allocators;
using namespace LDL::Enums;
using namespace LDL::Loaders;
using namespace LDL::Events;
using namespace Arcanum::Game;

Engine::Engine(Settings* settings) :
	_Settings(settings),
	_PathManager(settings->Path()),
	_ImageAllocator(Allocator::Mb * 2),
	_ImageLoader(&_ImageAllocator),
	_Window(Point2u(0,0), _Settings->Size(), _Settings->Title()),
	_Render(&_RenderContext, &_Window),
	_FpsLimiter(_Settings->Fps()),
	_SpriteManager(&_RenderContext, &_ArtLoader, &_PathManager),
	_SecReader(&_ByteReader),
	_LocationPainter(&_Render),
	_WidgetManager(&_Render),
	_GameMenu(&_Render)
{
	_SecReader.Reset(_PathManager.Path("maps/Tarant Sewers-01/", "0.sec"));

	size_t sz = 10;

	_Location.Reset(Point2u(sz, sz));
	
	for (size_t i = 0; i < _Location.Size().PosX() * _Location.Size().PosY(); i++)
	{
		_Location.Tiles()[i].Init(_SpriteManager.Tile("grsbse0c.ART"));
	}
	
	_Location.Sceneries()[_Location.Index(3, 7)].Init(_SpriteManager.Scenery("savanna_tree02.ART"));
	_Location.Sceneries()[_Location.Index(9, 7)].Init(_SpriteManager.Scenery("engine.ART"));
}

void Engine::Run()
{
	Event report = { 0 };

	size_t dx   = 0;
	size_t dy   = 0;
	size_t step = 25;

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

		_LocationPainter.Draw(&_Location, Point2u(dx, dy));

		_GameMenu.Draw();

		_Render.End();

		if (report.IsKeyPresed(KeyboardKey::W))
		{
			dy += step;
		}

		if (report.IsKeyPresed(KeyboardKey::S))
		{
			dy -= step;
		}

		if (report.IsKeyPresed(KeyboardKey::A))
		{
			dx += step;
		}

		if (report.IsKeyPresed(KeyboardKey::D))
		{
			dx -= step;
		}

		_FpsLimiter.Throttle();

		if (_FpsCounter.Calc())
		{
			_Title = _Settings->Title() + " Fps: " + _Convert.Convert(_FpsCounter.Fps());
			_Window.Title(_Title);
			_FpsCounter.Clear();
		}
	}
}