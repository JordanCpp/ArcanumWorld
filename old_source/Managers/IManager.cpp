#include "IManager.h"
#include "../Common/Utils.h"

IManager::IManager(const std::string& Path):
	short_path(Path)
{
}

const std::string& IManager::GetPath(const std::string& DirName, const std::string& FileName)
{
	Utils::ConcatPath(full_path, short_path, DirName, FileName);

	return full_path;
}