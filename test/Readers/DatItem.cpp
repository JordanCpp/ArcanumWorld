#include <LDL/Core/TestEqual.hpp>
#include <Arcanum/Readers/DatReader.hpp>

using namespace Arcanum::Readers;

void Init()
{
	DatItem datItem;

    LDL_TEST_EQUAL(datItem.NameSize            == 0); 
    LDL_TEST_EQUAL(strcmp(datItem.Name, "")    == 0);
    LDL_TEST_EQUAL(datItem.Unknown1            == 0);
    LDL_TEST_EQUAL(datItem.Type                == 0);
    LDL_TEST_EQUAL(datItem.RealSize            == 0);
    LDL_TEST_EQUAL(datItem.PackedSize          == 0);
    LDL_TEST_EQUAL(datItem.Offset              == 0);
    LDL_TEST_EQUAL(strcmp(datItem.Archive, "") == 0);
}

int main()
{
	Init();

	return 0;
}