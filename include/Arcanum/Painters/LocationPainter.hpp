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
            LocationPainter(LDL::Graphics::Render* render, Objects::Location* location);
            void DrawTiles(const LDL::Graphics::Point2u& start);
            void DrawSceneries(const LDL::Graphics::Point2u& start);
            void Draw(const LDL::Graphics::Point2u& start);
        private:
            LDL::Graphics::Render*   _Render;
            Objects::Location* _Location;
            LDL::Graphics::Isometric _Isometric;
        };
    }
}

#endif