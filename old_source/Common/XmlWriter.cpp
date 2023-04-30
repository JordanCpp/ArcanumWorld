#include "XmlWriter.hpp"

XmlWriter::XmlWriter(const std::string & Name):
    mTabs(-1)
{
    mOutput.open(Name.c_str());
}

XmlWriter::~XmlWriter()
{
    mOutput.close();
}

void XmlWriter::AddSpace()
{
    for (int i = 0; i < mTabs; i++)
    {
        mResult.push_back(' ');
        mResult.push_back(' ');
    }
}

void XmlWriter::OpenTag(const std::string & Name)
{
    mTabs++;

    mResult.clear();

    AddSpace();
    mResult.push_back('<');
    mResult.append(Name);
    mResult.push_back('>');

    mOutput << mResult << std::endl;
}

void XmlWriter::CloseTag(const std::string & Name)
{
    mTabs--;
    mResult.clear();

    AddSpace();
    mResult.push_back('<');
    mResult.push_back('/');
    mResult.append(Name);
    mResult.push_back('>');

    mOutput << mResult << std::endl;
}

void XmlWriter::Node(const std::string & Name, const std::string & Value)
{
    mResult.clear();

    mTabs++;
    AddSpace();
    mResult.push_back('<');
    mResult.append(Name);
    mResult.push_back('>');

    mResult.append(Value);

    mResult.append("</");
    mResult.append(Name);
    mResult.push_back('>');

    mTabs--;

    mOutput << mResult << std::endl;
}
