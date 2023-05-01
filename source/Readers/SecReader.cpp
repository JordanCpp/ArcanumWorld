#include <Arcanum/Readers/SecReader.hpp>

using namespace Arcanum::Readers;

SecReader::SecReader(ByteReader* byteReader) :
	_ByteReader(byteReader)
{
}

void SecReader::Reset(const std::string& path)
{
	_ByteReader->Reset(path);

	ReadLights();
	ReadTiles();
	ReadRoofs();
}

void SecReader::ReadLights()
{
	_Sec.lights_count = _ByteReader->u32();

	uint8_t light[48] = { 0 };

	for (size_t i = 0; i < _Sec.lights_count; i++)
		_ByteReader->Read(light, sizeof(light));
}

void SecReader::ReadTiles()
{
	for (size_t i = 0; i < _Sec.MaxTiles; i++)
		_Sec.tiles[i] = _ByteReader->u32();
}

void SecReader::ReadRoofs()
{
	for (size_t i = 0; i < _Sec.MaxRoffs; i++)
		_Sec.roofs[i] = _ByteReader->u32();
}