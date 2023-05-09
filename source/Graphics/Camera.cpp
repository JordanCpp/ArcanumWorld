#include <Arcanum/Graphics/Camera.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;

Camera::Camera(const Point2u& size) :
	_Area(Point2u(0, 0), size),
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

void Camera::Handle(Event& event)
{
	size_t x = _Area.Pos().PosX();
	size_t y = _Area.Pos().PosY();

	if (event.IsKeyPresed(KeyboardKey::W))
	{
		y += _Step;
	}

	if (event.IsKeyPresed(KeyboardKey::S))
	{
		y -= _Step;
	}

	if (event.IsKeyPresed(KeyboardKey::A))
	{
		x += _Step;
	}

	if (event.IsKeyPresed(KeyboardKey::D))
	{
		x -= _Step;
	}

	_Area.Pos(x, y);
}