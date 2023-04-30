#include <Arcanum/Readers/MsgReader.hpp>

using namespace Arcanum::Readers;

void MsgReader::Reset(const std::string& path)
{
	_File.open(path, std::ios::in);
}