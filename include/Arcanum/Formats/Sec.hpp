#ifndef Arcanum_Formats_Sec_hpp
#define Arcanum_Formats_Sec_hpp

#include <stdint.h>
#include <vector>

namespace Arcanum
{
	namespace Formats
	{
		struct Light
		{
			uint8_t data[48];
		};

		struct Sec
		{
			enum
			{
				MaxTiles = 4096,
				MaxRoffs = 256
			};

			uint32_t lights_count;
			std::vector<Light> lights;
			std::vector<uint32_t> tiles;
			std::vector<uint32_t> roofs;
		};
	}
}

#endif