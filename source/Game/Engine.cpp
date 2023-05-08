#include <Arcanum/Game/Engine.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>

using namespace Arcanum::Game;
using namespace LDL::Graphics;
using namespace LDL::Allocators;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Loaders;

GLuint LoadTexture(const std::string& path, ImageLoader& loader)
{
	GLuint result = 0;

	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	loader.Load(path);

	GLenum format = 0;

	if (loader.BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, format, GL_UNSIGNED_BYTE, loader.Pixels());

	return result;
}

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
	_GameMenu(&_Render),
	_LocationPainter3D(&_TileData)
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


	_TileData.Reset(Point2u(10, 10));

	//_Tex1 = LoadTexture("tr256.bmp", _ImageLoader);
}

void Engine::Run()
{
	LDL::Events::Event report = { 0 };

	size_t dx   = 0;
	size_t dy   = 0;
	size_t step = 25;

	while (_Window.GetEvent(report))
	{
		_FpsLimiter.Mark();
		_FpsCounter.Start();

		if (report.Type == LDL::Events::IsQuit)
		{
			_Window.StopEvent();
		}

		//_Camera.Handle(report);

		//glViewport(0, 0, (GLsizei)_Render.Size().PosX(), (GLsizei)_Render.Size().PosY());

		_Render.Begin();

		_Render.Color(Color(0, 0, 0));
		_Render.Clear();

		/*
		glClearColor(0, 0, 0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(_Camera.Projection().Values());

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(_Camera.ModelView().Values());
		glEnable(GL_TEXTURE_2D);

		glBindTexture(_Tex1, GL_TEXTURE_2D);

		_LocationPainter3D.Draw();

		glDisable(GL_TEXTURE_2D);
		*/

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