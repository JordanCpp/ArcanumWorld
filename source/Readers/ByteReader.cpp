#include <Arcanum/Readers/ByteReader.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Readers;
using namespace Arcanum::Core;

#define HTONS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))

#define HTONL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24)) 

void ByteReader::Reset(const std::string & path)
{
    if (_File.is_open())
        _File.close();

  _File.open(path.c_str(), std::ios::in | std::ios::binary);

  if (!_File.is_open())
      throw RuntimeError("Can't open file: " + path);
}

ByteReader::~ByteReader()
{
  _File.close();
}

void ByteReader::Pos(size_t value)
{
  _File.seekg(value, std::ios::beg);
}

void ByteReader::Read(void* buffer, size_t bytes)
{
    _File.read((char*)buffer, bytes);
}

bool ByteReader::Eof()
{
  return _File.good();
}

uint8_t ByteReader::u8()
{
  uint8_t val;

  _File.read((char*)&val, sizeof(uint8_t));

  return val;
}

uint16_t ByteReader::u16()
{
  uint16_t val;

  _File.read((char*)&val, sizeof(uint16_t));

  return HTONS(val);
}

int16_t ByteReader::i16()
{
  int16_t val;

  _File.read((char*)&val, sizeof(int16_t));

  return HTONS(val);
}

uint32_t ByteReader::u32()
{
  uint32_t val;

  _File.read((char*)&val, sizeof(uint32_t));
    
  return HTONL(val);
}

int32_t ByteReader::i32()
{
  int32_t val;

  _File.read((char*)&val, sizeof(int32_t));
    
  return HTONL(val);
}