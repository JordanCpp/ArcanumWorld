#include <Arcanum/Managers/FileManager.hpp>
#include <LDL/Core/Directory.hpp>

using namespace Arcanum::Managers;
using namespace Arcanum::Readers;
using namespace Arcanum::Loaders;
using namespace LDL::Core;

FileManager::FileManager(Managers::PathManager* pathManager) :
	_PathManager(pathManager),
	_DatLoader(&_ArchiveList)
{
	Directory directory;
	FileInfo fileInfo;

	if (directory.Open("*.dat"))
	{
		while (directory.Next(fileInfo))
		{
			_ArchiveReader.Reset("", fileInfo.Name(), _ArchiveList);
		}
	}
}

MemoryReader& FileManager::GetFile(const std::string& path)
{
	return _DatLoader.GetFile(path);
}