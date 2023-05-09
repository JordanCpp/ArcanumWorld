#ifndef Arcanum_Graphics_Camera_hpp
#define Arcanum_Graphics_Camera_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Rect2u.hpp>
#include <LDL/Events/Event.hpp>

namespace Arcanum
{
	namespace Graphics
	{
		class Camera
		{
		public:
			Camera(const LDL::Graphics::Point2u& size);
			const LDL::Graphics::Point2u& Pos();
			const LDL::Graphics::Point2u& Size();
			void Handle(LDL::Events::Event& event);
		private:
			LDL::Graphics::Rect2u _Area;
			size_t _Step;
		};
	}
}

#endif    