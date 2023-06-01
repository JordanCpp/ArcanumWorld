#include <Arcanum/Objects/Location.hpp>

using namespace Arcanum::Objects;

Location::Location(LocationData* locationData, Managers::ObjectManager* objectManager) :
	_LocationData(locationData),
	_ObjectManager(objectManager)
{
}