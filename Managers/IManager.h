#ifndef _IManager_h_
#define _IManager_h_ 

#include <string>

class IManager
{
public:
	IManager(const std::string& Path);
	const std::string& GetPath(const std::string & DirName, const std::string & FileName);
private:
	std::string short_path;
	std::string full_path;
};

#endif