#include <Arcanum/Graphics/Camera.hpp>
#include <LDL/Math/Vec3f.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Math;

Camera::Camera() :
	_PosX(0.0f),
	_PosY(0.0f),
	_Zoom(1.0f),
	_PosAlpha(0.0f),
	_ZoomAlpha(0.0f),
	_StepZoom(0.3f),
	_StepPos(0.1f)
{
}

void Camera::Handle(Event& event)
{
	if (event.IsKeyPresed(KeyboardKey::W))
	{
		_PosY -= _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::S))
	{
		_PosY += _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::A))
	{
		_PosX -= _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::D))
	{
		_PosX += _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::E))
	{
		_Zoom -= _StepZoom;
	}

	if (event.IsKeyPresed(KeyboardKey::R))
	{
		_Zoom += _StepZoom;
	}

	if (event.IsKeyPresed(KeyboardKey::Z))
	{
		_PosAlpha -= _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::X))
	{
		_PosAlpha += _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::C))
	{
		_ZoomAlpha -= _StepPos;
	}

	if (event.IsKeyPresed(KeyboardKey::V))
	{
		_ZoomAlpha += _StepPos;
	}

	_Projection.Identity();
	_Projection = Frustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 100.0f);

	_ModelView.Identity();
	_ModelView = Translate(_ModelView, Vec3f(-_PosX, -_PosY, -_Zoom));
	_ModelView = Rotate(_ModelView, _ZoomAlpha, Vec3f(1.0f, 0.0f, 0.0f));
	_ModelView = Rotate(_ModelView, _PosAlpha, Vec3f(0.0f, 0.0f, 1.0f));
}

Mat4f& Camera::Projection()
{
	return _Projection;
}

Mat4f& Camera::ModelView()
{
	return _ModelView;
}