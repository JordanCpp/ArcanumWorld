#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Location
		{
		public:
			Location(LocationData* locationData, Managers::ObjectManager* objectManager);
		private:
			LocationData* _LocationData;
			Managers::ObjectManager* _ObjectManager;
		};
	}
}

#endif