#ifndef _XmlWriter_hpp
#define _XmlWriter_hpp

#include <string>
#include <fstream>


class XmlWriter
{
public:
    XmlWriter(const std::string & Name);
    ~XmlWriter();
    void Node(const std::string & Name, const std::string & Value);
    void OpenTag(const std::string & Name);
    void CloseTag(const std::string & Name);
    void AddSpace();
private:
    int mTabs;
    std::string mResult;
    std::ofstream mOutput;
};

#endif
