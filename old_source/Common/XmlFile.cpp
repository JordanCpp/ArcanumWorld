#include "XmlFile.hpp"

XmlFile::XmlFile(const std::string & name)
{
    input.open(name.c_str());

    if (input.is_open())
    {
        std::string line;

        while (std::getline(input, line))
        {
            content.append(line);
            content.push_back('\n');
        }

        input.close();
    }
    else
    {
        std::cout << "Not found file: " + name << '\n';
        std::terminate();
    }
}

XmlFile::~XmlFile()
{
}

const std::string & XmlFile::Content()
{
    return content;
}
