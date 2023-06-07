#include <LDL/Core/TestEqual.hpp>
#include <Arcanum/Readers/DatReader.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL::Core;
using namespace Arcanum::Readers;

int main()
{
	Directory dir;
	FileInfo info;
	DatList list;
	DatReader reader;

	std::string path = "c:\\Games\\Arcanum\\";
	std::string ext = "*.dat";

	if (dir.Open(path + ext))
	{ 
		while (dir.Next(info))
		{
			LDL_TEST_EQUAL(reader.Reset(path, info.Name(), list) == true);
		}
	}

	LDL_TEST_EQUAL(list.GetItem("art\\tile\\grsbse0c.ART") != nullptr);

	return 0;
}