#include <Arcanum/Objects/TileData.hpp>

using namespace Arcanum::Objects;

void TileData::Reset(const LDL::Graphics::Point2u& size)
{
	_Vertexs.reserve(size.PosX() * size.PosY());

    for (size_t y = 0; y < size.PosY(); y++)
    {
        for (size_t x = 0; x < size.PosX(); x++)
        {
            _Vertexs.push_back(float(x));
            _Vertexs.push_back(float(y));
            _Vertexs.push_back(0.0f);
            _Vertexs.push_back(float(x + 1));
            _Vertexs.push_back(float(y));
            _Vertexs.push_back(0.0f);
            _Vertexs.push_back(float(x));
            _Vertexs.push_back(float(y + 1));
            _Vertexs.push_back(0.0f);

            _Vertexs.push_back(float(x));
            _Vertexs.push_back(float(y + 1));
            _Vertexs.push_back(0.0f);
            _Vertexs.push_back(float(x + 1));
            _Vertexs.push_back(float(y + 1));
            _Vertexs.push_back(0.0f);
            _Vertexs.push_back(float(x + 1));
            _Vertexs.push_back(float(y));
            _Vertexs.push_back(0.0f);

            _Coords.push_back(0.0f);
            _Coords.push_back(0.0f);
            _Coords.push_back(1.0f);
            _Coords.push_back(0.0f);
            _Coords.push_back(0.0f);
            _Coords.push_back(1.0f);

            _Coords.push_back(0.0f);
            _Coords.push_back(1.0f);
            _Coords.push_back(1.0f);
            _Coords.push_back(1.0f);
            _Coords.push_back(1.0f);
            _Coords.push_back(0.0f);
        }
    }
}

const std::vector<float>& Arcanum::Objects::TileData::Vertexs()
{
    return _Vertexs;
}

const std::vector<float>& Arcanum::Objects::TileData::Coords()
{
    return _Coords;
}