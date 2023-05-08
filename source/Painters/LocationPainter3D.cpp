#include <Arcanum/Painters/LocationPainter3D.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>

using namespace Arcanum::Painters;
using namespace Arcanum::Objects;

LocationPainter3D::LocationPainter3D(TileData* tileData) :
	_TileData(tileData)
{
}

void LocationPainter3D::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, _TileData->Vertexs().data());
	glTexCoordPointer(2, GL_FLOAT, 0, _TileData->Coords().data());

	glDrawArrays(GL_TRIANGLES, 0, _TileData->Vertexs().size() / 3);

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}