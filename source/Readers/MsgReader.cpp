#include <Arcanum/Readers/MsgReader.hpp>
#include <LDL/Core/RuntimeError.hpp>

using namespace Arcanum::Readers;
using namespace LDL::Core;

void MsgReader::Reset(const std::string& path)
{
	_File.open(path, std::ios::in);

	if (!_File.is_open())
		throw RuntimeError("Can't open file: " + path);

	_File.close();
}