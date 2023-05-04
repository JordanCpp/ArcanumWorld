#ifndef Arcanum_Widgets_Form_hpp
#define Arcanum_Widgets_Form_hpp

#include <Arcanum/Widgets/Widget.hpp>
#include <Arcanum/Widgets/Container.hpp>

namespace Arcanum
{
    namespace Widgets
    {
        class Form : public Widget
        {
        public:
            Form(LDL::Graphics::Render* render, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
            void Attach(Widget* widget);
            void Draw();
        private:
            Container _Container;
        };
    }
}

#endif