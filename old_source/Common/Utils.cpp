#include "Utils.h"

void Utils::NormalizePath(std::string& Dest)
{
    for (size_t i = 0; i < Dest.size(); i++)
    {
        if (Dest[i] == '\\')
        {
            Dest[i] = '\\';
        }
    }
}

void Utils::ConcatPath(std::string& Dest, const std::string& ShortPath, const std::string& DirName, const std::string& FileName)
{
    Dest.clear();
    Dest.append(ShortPath);
    Dest.append(DirName);
    Dest.append(FileName);

    NormalizePath(Dest);
}