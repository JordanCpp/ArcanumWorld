#ifndef Arcanum_Painters_LocationPainter_hpp
#define Arcanum_Painters_LocationPainter_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Isometric.hpp>
#include <Arcanum/Objects/Location.hpp>

namespace Arcanum
{
    namespace Painters
    {
        class LocationPainter
        {
        public:
            LocationPainter(LDL::Graphics::Render* render);
            void DrawTiles(Objects::Location* location, const LDL::Graphics::Point2u& start);
            void DrawSceneries(Objects::Location* location, const LDL::Graphics::Point2u& start);
            void Draw(Objects::Location* location, const LDL::Graphics::Point2u& start);
        private:
            LDL::Graphics::Render*   _Render;
            LDL::Graphics::Isometric _Isometric;
        };
    }
}

#endif