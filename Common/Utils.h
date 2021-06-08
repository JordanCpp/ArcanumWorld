#ifndef _Utils_h_
#define _Utils_h_

#include <string>

namespace Utils
{
    void NormalizePath(std::string& Dest);

    void ConcatPath(std::string& Dest, const std::string & ShortPath, const std::string& DirName, const std::string& FileName);
}

#endif