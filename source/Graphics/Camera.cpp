#include <Arcanum/Graphics/Camera.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;

Camera::Camera(const Point2u& pos, const Point2u& size) :
	_Area(pos, size),
	_Step(25)
{
}

const Point2u& Camera::Pos()
{
	return _Area.Pos();
}

const Point2u& Camera::Size()
{
	return _Area.Size();
}

void Camera::Move(const Point2u& pos)
{
	_Area.Pos(pos.PosX(), pos.PosY());
}

void Camera::Handle(Event& event)
{
	size_t x = Pos().PosX();
	size_t y = Pos().PosY();

	if (event.IsKeyPressed(KeyboardKey::W))
	{
		y += _Step;
	}

	if (event.IsKeyPressed(KeyboardKey::S))
	{
		y -= _Step;
	}

	if (event.IsKeyPressed(KeyboardKey::A))
	{
		x += _Step;
	}

	if (event.IsKeyPressed(KeyboardKey::D))
	{
		x -= _Step;
	}

	Move(Point2u(x, y));
}