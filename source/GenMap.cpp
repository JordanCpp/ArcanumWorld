#include <iostream>
#include <Arcanum/Writters/XmlWritter.hpp>
#include <LDL/Math/Vec2.hpp>

using namespace Arcanum::Writters;

int main()
{
	XmlWritter writter;

	writter.Reset("Empty.xml");

	LDL::Math::Vec2u size(100, 100);

	writter.TagBegin("Info");
	writter.Node("Width", size.x);
	writter.Node("Heigth", size.y);
	writter.TagEnd("Info");

	writter.TagBegin("Tiles");

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		writter.TagBegin("Tile");
		writter.Node("Proto", "Empty.xml");
		writter.TagEnd("Tile");
	}

	writter.TagEnd("Tiles");

	return 0;
}