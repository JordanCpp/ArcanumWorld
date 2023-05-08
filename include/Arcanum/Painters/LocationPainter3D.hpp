#ifndef Arcanum_Painters_LocationPainter3D_hpp
#define Arcanum_Painters_LocationPainter3D_hpp

#include <Arcanum/Objects/TileData.hpp>

namespace Arcanum
{
    namespace Painters
    {
        class LocationPainter3D
        {
        public:
            LocationPainter3D(Objects::TileData* tileData);
            void Draw();
        private:
            Objects::TileData* _TileData;
        };
    }
}

#endif