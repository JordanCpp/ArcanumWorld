#ifndef Arcanum_Widgets_Widget_hpp
#define Arcanum_Widgets_Widget_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Primitives/Rect2u.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <functional>

namespace Arcanum
{
    namespace Widgets
    {
        class Widget
        {
        public:
            Widget(LDL::Graphics::Render* render, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
            virtual ~Widget();
            const LDL::Graphics::Point2u Pos();
            const LDL::Graphics::Point2u Size();
            LDL::Graphics::Render* Render();
            virtual void Draw() = 0;
            std::function<void(LDL::Graphics::Point2u pos)> Click;
            std::function<void(size_t key)> Keyboard;
        private:
            LDL::Graphics::Render* _Render;
            LDL::Graphics::Rect2u  _Area;
        };
    }
}

#endif