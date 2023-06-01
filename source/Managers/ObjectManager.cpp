#include <Arcanum/Managers/ObjectManager.hpp>

using namespace Arcanum::Managers;
using namespace Arcanum::Objects;

ObjectManager::ObjectManager(Allocators::ObjectAllocator* objectAllocator, SpriteManager* spriteManager) :
	_ObjectAllocator(objectAllocator),
	_SpriteManager(spriteManager)
{
}

Scenery* ObjectManager::NewScenery(const std::string& name)
{
	Scenery* result = _ObjectAllocator->NewScenery();

	result->Init(_SpriteManager->GetScenery(name));

	return result;
}