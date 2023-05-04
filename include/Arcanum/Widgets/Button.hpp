#ifndef Arcanum_Widgets_Button_hpp
#define Arcanum_Widgets_Button_hpp

#include <Arcanum/Widgets/Widget.hpp>

namespace Arcanum
{
    namespace Widgets
    {
        class Button : public Widget
        {
        public:
            Button(LDL::Graphics::Render* render, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
            void Draw();
        private:
        };
    }
}

#endif