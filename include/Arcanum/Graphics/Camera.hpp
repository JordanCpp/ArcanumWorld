#ifndef Arcanum_Graphics_Camera_hpp
#define Arcanum_Graphics_Camera_hpp

#include <LDL/Math/Mat4f.hpp>
#include <LDL/Events/Event.hpp>

namespace Arcanum
{
	namespace Graphics
	{
		class Camera
		{
		public:
			Camera();
			void Handle(LDL::Events::Event& event);
			LDL::Math::Mat4f& Projection();
			LDL::Math::Mat4f& ModelView();
		private:
			LDL::Math::Mat4f _Projection;
			LDL::Math::Mat4f _ModelView;
			float _PosX;
			float _PosY;
			float _Zoom;
			float _PosAlpha;
			float _ZoomAlpha;
			float _StepZoom;
			float _StepPos;
		};
	}
}

#endif    