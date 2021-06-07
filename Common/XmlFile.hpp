#ifndef _XmlFile_hpp_
#define _XmlFile_hpp_

#include <iostream>
#include <fstream>
#include <string>

class XmlFile
{
public:
    XmlFile(const std::string & name);
    ~XmlFile();
    const std::string & Content();
private:
    std::fstream input;
    std::string content;
};

#endif